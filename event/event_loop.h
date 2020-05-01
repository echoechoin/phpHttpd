#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include "debug.h"
#include "httpd-config.h"
#include "http_request.h"
#include "response.h"
#include <string>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <event2/event.h> 
#include <event2/listener.h> 
#include <event2/bufferevent.h> 
#include <event2/buffer.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <stdio.h>
#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

class EventLoop{
  public:
    int startup();
  private:
    static void event_listener_callback(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *addr, int len, void *ptr);
    static void read_cb(struct bufferevent *bev, void *arg);
    static void write_cb(struct bufferevent *bev, void *arg);
    static void event_cb(struct bufferevent *bev, short events, void *arg);

    std::string listenAddress;
    unsigned int listenPort;
};

#endif