#include "event_loop.h"
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
  std::cout << "---new connection---" << std::endl;
  struct evbuffer *bufferInput = bufferevent_get_input(bev);
  int inputLen = evbuffer_get_length(bufferInput);
  const char *pBody = (const char *)evbuffer_pullup(bufferInput, inputLen);
  std::string requestEntity(pBody);
   HttpdConfig *c = HttpdConfig::getInstance();
  HttpRequest r(requestEntity);
  if(!r.isParsed()){
    std::cout << r.getParseError() << std::endl;
  }
 
  if(c->getServerMode().compare("default") == 0){ ///< 普通静态服务器模式
    Response res;
    std::string rootPath = c->getRootPath();
    std::string path = r.getPath();
    path.erase(path.begin());
    std::string realPath = rootPath + path;
    std::ifstream fs;
    fs.open(realPath.c_str());
    std::cout << fs << std::endl;
    std::cout <<  realPath << std::endl;
    if(!fs){ // 不存在 发送404
      std::cout << "404" << std::endl;
      bufferevent_write(bev,res.getStatus(404).c_str(),res.getStatus(404).length());
      bufferevent_write(bev,"\r\n",3);
    }else{
      bufferevent_write(bev,res.getStatus(200).c_str(),res.getStatus(200).length());
      bufferevent_write(bev,res.getContenType(path).c_str(),res.getContenType(path).length());
      bufferevent_write(bev,"\r\n",2); ///< 空行
      while(!fs.eof()){
        char data[1024];
        fs.read(data,sizeof(data));
        bufferevent_write(bev,data,strlen(data));
      }
    }
    // 通过reponse类响应
  }else if(c->getServerMode().compare("php") == 0){
    ///< php mode...
  }
}
 
/**
 *  @brief 暂时无用
 */
void EventLoop::write_cb(struct bufferevent *bev, void *arg){
  Log::debug("我是写缓冲区的回调函数...您已发送\n"); 
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
