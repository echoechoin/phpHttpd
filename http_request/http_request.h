#include <string>
#include <map>
#include "debug.h"
#include <sys/types.h>
#include <regex.h>
#include <vector>
#ifndef HTTP_REQUEST
#define HTTP_REQUEST

class HttpRequest{
  public:
    HttpRequest(std::string request);
    ~HttpRequest();

    std::string getParseError(); // 打印错误信息
    bool isParsed(); // 判断是否解析成功

    /* 先获取一些简单的 */
    std::string getMethod();  
    std::string getUrl();
    std::string getHost();
    std::string getPath();

    std::map<std::string,std::string> paramsOfGet(); // TODO
    std::map<std::string,std::string> paramsOfPost(); //TODO
    std::string queryStrOfGet();
    std::string queryStrOfPost();

    std::string getContentType(); // TODO
    unsigned int getContentLength(); // TODO

    std::string getAgent(); 
    std::map<std::string,std::string> getCookies();

    std::string getAccept();
    std::string getAcceptEncoding();
  private:
    std::string request;
    std::string method;
    std::string url;
    std::string host;
    std::string path;

    std::map<std::string,std::string> get;
    std::map<std::string,std::string> post;
    std::string postQueryString;
    
    std::string contentType;
    unsigned int contentLength;

    std::string agent;

    std::map<std::string,std::string> cookies;
    std::string accept;
    std::string accept_encoding;

    bool isURL(std::string url);
    std::string error;
    bool parseStatus;
};

#endif