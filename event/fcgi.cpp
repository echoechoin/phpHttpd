/*
 * @filename:    fcgi.c
 * @author:      Tanswer
 * @date:        2017年12月23日 00:00:09
 * @description:
 */
#include "unistd.h"
#include <stdlib.h>
#include "fastcgi.h"
#include "fcgi.h"
#include "sys/un.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <httpd-config.h>


static const int PARAMS_BUFF_LEN = 1024;    //环境参数buffer的大小
static const int CONTENT_BUFF_LEN = 1024;   //内容buffer的大小

static char *findStartHtml(char *content);
static void getHtmlFromContent(FastCgi_t *c, char *content);
/**
 * @brief 初始化结构体FastCgi_t
 */ 
void FastCgi_init(FastCgi_t *c)
{
    c -> sockfd_ = 0;    ///< 本地套接字文件描述符
    c -> flag_ = 0;
    c -> requestId_ = 0; ///< 每一个请求都得有一个id
}

/**
 * @brief 关闭套接字
 */ 
void FastCgi_finit(FastCgi_t *c)
{
    close(c -> sockfd_);
}

/**
 * @brief 设置请求id
 */ 
void setRequestId(FastCgi_t *c, int requestId)
{
    c -> requestId_ = requestId;
}

FCGI_Header makeHeader(int type, int requestId,
                        int contentLength, int paddingLength)
{
    FCGI_Header header;
    
    header.version = FCGI_VERSION_1;
    
    header.type = (unsigned char)type;

    /* 两个字段保存请求ID */
    header.requestIdB1 = (unsigned char)((requestId >> 8) & 0xff);
    header.requestIdB0 = (unsigned char)(requestId & 0xff);

    /* 两个字段保存内容长度 */
    header.contentLengthB1 = (unsigned char)((contentLength >> 8) & 0xff);
    header.contentLengthB0 = (unsigned char)(contentLength & 0xff);

    /* 填充字节的长度 */
    header.paddingLength = (unsigned char)paddingLength;

    /* 保存字节赋为 0 */
    header.reserved = 0;

    return header;

}

FCGI_BeginRequestBody makeBeginRequestBody(int role, int keepConnection)
{
    FCGI_BeginRequestBody body;

    /* 两个字节保存期望 php-fpm 扮演的角色 */
    body.roleB1 = (unsigned char)((role >> 8) & 0xff);
    body.roleB0 = (unsigned char)(role & 0xff);

    /* 大于0长连接，否则短连接 */
    body.flags = (unsigned char)((keepConnection) ? FCGI_KEEP_CONN : 0);

    bzero(&body.reserved, sizeof(body.reserved));

    return body;
}   


int makeNameValueBody(char *name, int nameLen,
                        char *value, int valueLen,
                        unsigned char *bodyBuffPtr, int *bodyLenPtr)
{
    /* 记录 body 的开始位置 */
    unsigned char *startBodyBuffPtr = bodyBuffPtr;  

    /* 如果 nameLen 小于128字节 */
    if(nameLen < 128){
        *bodyBuffPtr++ = (unsigned char)nameLen;    //nameLen用1个字节保存
    } else {
        /* nameLen 用 4 个字节保存 */
        *bodyBuffPtr++ = (unsigned char)((nameLen >> 24) | 0x80);
        *bodyBuffPtr++ = (unsigned char)(nameLen >> 16);
        *bodyBuffPtr++ = (unsigned char)(nameLen >> 8);
        *bodyBuffPtr++ = (unsigned char)nameLen;
    }

    /* valueLen 小于 128 就用一个字节保存 */
    if(valueLen < 128){
        *bodyBuffPtr++ = (unsigned char)valueLen;
    } else {
        /* valueLen 用 4 个字节保存 */
        *bodyBuffPtr++ = (unsigned char)((valueLen >> 24) | 0x80);
        *bodyBuffPtr++ = (unsigned char)(valueLen >> 16);
        *bodyBuffPtr++ = (unsigned char)(valueLen >> 8);
        *bodyBuffPtr++ = (unsigned char)valueLen;
    }

    /* 将 name 中的字节逐一加入body中的buffer中 */
    for(int i=0; i<strlen(name); i++){
        *bodyBuffPtr++ = name[i];
    }

    /* 将 value 中的值逐一加入body中的buffer中 */
    for(int i=0; i<strlen(value); i++){
        *bodyBuffPtr++ = value[i];
    }
    
    /* 计算出 body 的长度 */
    *bodyLenPtr = bodyBuffPtr - startBodyBuffPtr;
    return 1;
}

/*
 * 如果有配置文件的话，可以将一些信息，比如IP 从配置文件里读出来
 *
char *getIpFromConf()
{
    return getMessageFromFile("IP");
}
*/
/**
 * @brief 初始化本地套接字
 */ 
void startConnect(FastCgi_t *c,HttpdConfig *cfg)
{
    int sockfd;
    int result;
    int len;
    struct sockaddr_un address;
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    address.sun_family = AF_UNIX;
    strcpy (address.sun_path, cfg->getPhpSocketFile().c_str());
    len = sizeof (address);
    result = connect (sockfd, (struct sockaddr *)&address, len);
    if(result != 0){
        perror("error");
        exit(-1);
    }

    c -> sockfd_ = sockfd;
}
int sendStartRequestRecord(FastCgi_t *c)
{
    int rc;
    FCGI_BeginRequestRecord beginRecord; ///< 包括请求头和请求体

    ///< FCGI_BEGIN_REQUEST 表示此消息为请求开始的第一个消息
    ///< c->requestId_ 表示请求id
    ///< sizeof(beginRecord.body) 表示请求体的长度
    ///< 0 表示padding
    beginRecord.header = makeHeader(FCGI_BEGIN_REQUEST, c->requestId_, sizeof(beginRecord.body),0);

    ///< FCGI_RESPONDER 表示web服务器所期望php-fpm扮演的角色
    ///< 0 表示短连接，完成后立即断开
    beginRecord.body = makeBeginRequestBody(FCGI_RESPONDER, 0);

    ///< 发送开始请求
    rc = write(c->sockfd_, (char *)&beginRecord, sizeof(beginRecord));
    assert(rc == sizeof(beginRecord));

    return 1;
}


int sendParams(FastCgi_t *c, char *name, char *value)
{
    int rc;
    
    unsigned char bodyBuff[PARAMS_BUFF_LEN];

    bzero(bodyBuff, sizeof(bodyBuff));

    /* 保存 body 的长度 */
    int bodyLen;

    /* 生成 PARAMS 参数内容的 body */
    makeNameValueBody(name, strlen(name), value, strlen(value), bodyBuff, &bodyLen);

    FCGI_Header nameValueHeader;
    nameValueHeader = makeHeader(FCGI_PARAMS, c->requestId_, bodyLen, 0);

    int nameValueRecordLen = bodyLen + FCGI_HEADER_LEN;
    char nameValueRecord[nameValueRecordLen];

    /* 将头和body拷贝到一块buffer 中只需调用一次write */
    memcpy(nameValueRecord, (char *)&nameValueHeader, FCGI_HEADER_LEN);
    memcpy(nameValueRecord + FCGI_HEADER_LEN, bodyBuff, bodyLen);

    rc = write(c->sockfd_, nameValueRecord, nameValueRecordLen);
    assert(rc == nameValueRecordLen);

    return 1;
}

int sendEndRequestRecord(FastCgi_t *c)
{
    int rc;

    FCGI_Header endHeader;
    endHeader = makeHeader(FCGI_PARAMS, c->requestId_, 0, 0);

    rc = write(c->sockfd_, (char *)&endHeader, FCGI_HEADER_LEN);
    assert(rc == FCGI_HEADER_LEN);

    return 1;
}

int readFromPhp(FastCgi_t *c,struct bufferevent *bev)
{
    FCGI_Header responderHeader;
    char content[CONTENT_BUFF_LEN];

    int contentLen;
    char tmp[8];    //用来暂存padding字节
    int ret;
    int isSendHead = 0;
    /* 先将头部 8 个字节读出来 */
    Response res;
    while(read(c->sockfd_, &responderHeader,FCGI_HEADER_LEN) > 0){
        if(responderHeader.type == FCGI_STDOUT){
            if(!isSendHead){
                isSendHead = 1;
                bufferevent_write(bev,res.getStatus(200).c_str(),res.getStatus(200).length());
            }
           // std::cout << "123456" << std::endl;
            /* 获取内容长度 */
            contentLen = (responderHeader.contentLengthB1 << 8) + (responderHeader.contentLengthB0);
            bzero(content, CONTENT_BUFF_LEN);
            /* 读取获取内容 */
            int times = contentLen / CONTENT_BUFF_LEN; // 需要读满的次数
            int left = contentLen % CONTENT_BUFF_LEN; // 最后剩余
            while(times){
                ret = read(c->sockfd_, content, CONTENT_BUFF_LEN);
                bufferevent_write(bev,content,ret);
                times--;
            }
            ret = read(c->sockfd_, content, left);
            bufferevent_write(bev,content,ret);
            

            /* 跳过填充部分 */
            if(responderHeader.paddingLength > 0){
                ret = read(c->sockfd_, tmp, responderHeader.paddingLength);
                assert(ret == responderHeader.paddingLength);
            }
           // std::cout << "1234567" << std::endl;
        } //end of type FCGI_STDOUT
        else if(responderHeader.type == FCGI_STDERR){
            if(!isSendHead){
                isSendHead = 1;
                bufferevent_write(bev,res.getStatus(500).c_str(),res.getStatus(500).length());
            }
            contentLen = (responderHeader.contentLengthB1 << 8) + (responderHeader.contentLengthB0);
            bzero(content, CONTENT_BUFF_LEN);

            ret = read(c->sockfd_, content, contentLen);
            if(ret > 0){
                bufferevent_write(bev,content,ret);
            }

            /* 跳过填充部分 */
            if(responderHeader.paddingLength > 0){
                ret = read(c->sockfd_, tmp, responderHeader.paddingLength);
                assert(ret == responderHeader.paddingLength);
            }
        }// end of type FCGI_STDERR 
        else if(responderHeader.type == FCGI_END_REQUEST){
            FCGI_EndRequestBody endRequest;

            ret = read(c->sockfd_, &endRequest, sizeof(endRequest));
            assert(ret == sizeof(endRequest));
        }
    }
    printf("\n");
    return 1;
}

char *findStartHtml(char *content)
{
    for(; *content != '\0'; content++){
        if(*content == '<')
            return content;
    }
    return NULL;
}

void getHtmlFromContent(FastCgi_t *c, char *content)
{
    /* 保存html内容开始位置 */
    char *pt;

    /* 读取到的content是html内容 */
    if(c->flag_ == 1){
        printf("%s",content);
    } else {
        if((pt = findStartHtml(content)) != NULL){
            c->flag_ = 1;
            for(char *i = pt; *i != '\0'; i++){
                printf("%c",*i);
            }
        }
    }
}
