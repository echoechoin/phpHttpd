#include <string>
#include <iostream>
#include "httpd-config.h"
#include "debug.h"
#include "event_loop.h"
#include "http_request.h"

int main ( int argc, char *argv[] ){
  Log::enable(); ///< 初始化Loger
  Log::debug("------------------debug message-----------------");



  Log::debug("------------------debug message-----------------");

  HttpRequest *r = new HttpRequest(std::string("GET http://127.0.0.1/ HTTP/1.1\n")   
    + std::string("Accept: application/json, text/javascript, */*; q=0.01\n")
    + std::string("X-Requested-With: XMLHttpRequest\n")
    + std::string("Referer: https://testrail-tools.trendmicro.com/portal/admin/toLicenseTimerConfig?id=7\n")
    + std::string("Accept-Language: zh-CN\n")
    + std::string("Accept-Encoding: gzip, deflate\n")
    + std::string("User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko\n")
    + std::string("Host: testrail-tools.trendmicro.com\n")
    + std::string("Connection: Keep-Alive\n")
    + std::string("Cookie: _ga=GA1.2.1909963682.1524537669; _gid=GA1.2.563928490.1529501401")
  );
  if(r->isParsed()){
    Log::debug(r->getMethod());
    Log::debug(r->getUrl());
  }else{
    Log::debug(r->getParseError());
  }
    

  return 0;
}