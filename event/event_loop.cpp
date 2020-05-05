#include "event_loop.h"
#include "debug.h"
/**
 *  @brief 启动事件循环，监听 listenAddress:port
 *  @return 0 或 -1
 *  0表示成功， -1 表示失败
 */
int EventLoop::startup(){
  struct sockaddr_in sock_addr;     
  struct event_base *base;                          ///< epoll root
  struct evconnlistener *listener;                  ///< leaf listener
  HttpdConfig *c = HttpdConfig::getInstance();

  inet_pton(AF_INET,c->getListenAddress().c_str(),(&sock_addr.sin_addr.s_addr));    
  sock_addr.sin_port = htons(c->getListenPort());     
  sock_addr.sin_family = AF_INET;     

  // create base     
  base = event_base_new();  

  // create event_connection_listerner     
  listener = evconnlistener_new_bind(       
    base,       
    EventLoop::event_listener_callback,
    base,       
    LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,       
    36,       
    (struct sockaddr*)&sock_addr,       
    sizeof(sock_addr) 
  ); 
  if(listener == NULL){
    Log::debug("evconnlistener_new_bind  error: ");
    perror("");
    exit(-1);
  }
            
  // dispatch base     
  event_base_dispatch(base);     
  evconnlistener_free(listener);     
  event_base_free(base);
  return 0;
}
/**
 *  @brief 事件监听回调函数，当接收到http请求的时候，创建一个bufferevent用于响应请求。
 */
void EventLoop::event_listener_callback(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *addr, int len, void *ptr){
  struct event_base *base = (struct event_base*)ptr; // 获取base
  struct bufferevent *buffer_event = NULL;
  // create bufferevent
  buffer_event = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
  // set callback to buffer_event 
  bufferevent_setcb(buffer_event,  EventLoop::read_cb,  EventLoop::write_cb,  EventLoop::event_cb, NULL);
  bufferevent_enable(buffer_event, EV_READ);
}

/**
 *  @brief 处理http请求并响应浏览器
 */
void EventLoop::read_cb(struct bufferevent *bev, void *arg){
  Log::debug("----newConnection---");
  char data[1024];
  std::string requestEntity;
  int len = bufferevent_read(bev,data,sizeof(data)-1);
  while(len >0){
    if(len == 1023){
      data[1024] = 0;
    }
    requestEntity += std::string(data);
    memset(data,0,sizeof(data));
    len = bufferevent_read(bev,data,sizeof(data));
  }
  HttpdConfig *c = HttpdConfig::getInstance();
  HttpRequest r(requestEntity);
  Response res;
  Log::debug(std::string("--------url:     ") + r.getUrl());
  Log::debug(std::string("--------method:  ") + r.getMethod());
  if(!r.isParsed()){
    Log::error(std::string("url parse error: ") + r.getParseError());
    bufferevent_free(bev);
    return;
  }
  std::string rootPath = c->getRootPath();
    std::string path = r.getPath();
    path.erase(path.begin());
  if(c->getServerMode().compare("default") == 0){ ///< 普通静态服务器模式
staticServer:
    if(path.length() == 0){
      path = c->getDefaultFile();
    }
    std::string realPath = rootPath + path;
    int fd = open(realPath.c_str(),O_RDONLY);
    if(!fd){ // 不存在 发送404
      bufferevent_write(bev,res.getStatus(404).c_str(),res.getStatus(404).length());
      bufferevent_write(bev,"\r\n",3);
      close(fd);
      return;
    }else{
      bufferevent_write(bev,res.getStatus(200).c_str(),res.getStatus(200).length()); ///< 获取状态码
      bufferevent_write(bev,res.getContenType(path).c_str(),res.getContenType(path).length()); ///< 获取content-type
      bufferevent_write(bev,"\r\n",2); ///< 空行
      char data[10];
      int len = read(fd,data,sizeof(data));
      while(len > 0){
        bufferevent_write(bev,data,len);
        memset(data,0,sizeof(data));
        len = read(fd,data,sizeof(data));
      }
      close(fd);
      return;
    }    
  }else if(c->getServerMode().compare("php") == 0){
    std::string ext;
    if(path.rfind('.') == path.npos){
      ext = "";
    }else{
      ext = path.substr(path.rfind('.'),path.length()-path.rfind('.'));
    }
    if(ext.compare(".php") != 0 && path.length() != 0){
      goto staticServer; ///< 不是.php文件就触发静态模式
    }else{
      std::string realPath;
      if(path.length() == 0){
        realPath = c->getEntraceFilePath() + c->getEntraceFileName();
      }else{
        realPath = c->getEntraceFilePath()+path;
      }
      int fd = open(realPath.c_str(),O_RDONLY);
      if(fd<0){
        bufferevent_write(bev,res.getStatus(404).c_str(),res.getStatus(404).length());
        Log::debug("--------404");
        return;
      }
      close(fd);
      FastCgi_t *cgi;
      cgi = (FastCgi_t *)malloc(sizeof(FastCgi_t));
      FastCgi_init(cgi);
      setRequestId(cgi,1);
      startConnect(cgi,c);
      sendStartRequestRecord(cgi);
      char cwd[1024] = {0};
      getcwd(cwd,1024);
      std::string scwd(cwd);
      realPath.erase(realPath.begin());
      std::string absPath = scwd + realPath;
      sendParams(cgi, "SCRIPT_FILENAME",(char *)absPath.c_str());
      if(r.getMethod().compare("GET") == 0){
        sendParams(cgi, "REQUEST_METHOD","GET");
        sendParams(cgi, "QUERY_STRING",(char* )r.queryStrOfGet().c_str()); 
        sendEndRequestRecord(cgi);
      }else if(r.getMethod().compare("POST") == 0){
        sendParams(cgi, "SCRIPT_FILENAME", (char *)absPath.c_str());
        sendParams(cgi, "REQUEST_METHOD", "POST");
        char length[10];
        sprintf(length,"%d",r.queryStrOfPost().length());
        sendParams(cgi, "CONTENT_LENGTH", length); 
        sendParams(cgi, "CONTENT_TYPE", "application/x-www-form-urlencoded");
        sendEndRequestRecord(cgi);
        //设置type==5,为了发 body
        FCGI_Header t = makeHeader(FCGI_STDIN, cgi->requestId_, r.queryStrOfPost().length(), 0); 
        send(cgi->sockfd_, &t, sizeof(t), 0);

        /*发送正式的 body */
        send(cgi->sockfd_, r.queryStrOfPost().c_str(), r.queryStrOfPost().length(), 0); 
        //制造头告诉　body　结束　
        FCGI_Header endHeader;
        endHeader = makeHeader(FCGI_STDIN, cgi->requestId_, 0, 0);
        send(cgi->sockfd_, &endHeader, sizeof(endHeader), 0);
      }
      readFromPhp(cgi,bev);
      FastCgi_finit(cgi);
    }
  }
  Log::debug("---endOfNewConnection");
}
 
/**
 *  @brief free bufferevent
 */
void EventLoop::write_cb(struct bufferevent *bev, void *arg){
  Log::debug("----disconnected---");
  bufferevent_free(bev);
}
 
/**
 *  @brief bufferevent资源释放
 */
void EventLoop::event_cb(struct bufferevent *bev, short events, void *arg){
  if(events & BEV_EVENT_EOF){
    Log::debug("connection closed\n");  
  }
  else if(events & BEV_EVENT_ERROR){
    Log::debug("some other error\n");
  }

  bufferevent_free(bev);    
  Log::debug("buffevent 资源已经被释放...\n"); 
}
