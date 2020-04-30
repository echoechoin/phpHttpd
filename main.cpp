#include <string>
#include <iostream>
#include "httpd-config.h"
#include "debug.h"
#include "event_loop.h"
#include "http_request.h"
#include <map>

int main ( int argc, char *argv[] ){
  Log::enable(); ///< 初始化Loger
  Log::debug("------------------debug message-----------------");



  Log::debug("------------------debug message-----------------");
  
  HttpRequest *r = new HttpRequest(std::string("GET http://127.0.0.1/1123/1122?id=1&qq=123& HTTP/1.1\r\n")   
    + std::string("Accept: application/json, text/javascript, */*; q=0.01\r\n")
    + std::string("X-Requested-With: XMLHttpRequest\r\n")
    + std::string("Referer: https://testrail-tools.trendmicro.com/portal/admin/toLicenseTimerConfig?id=7\r\n")
    + std::string("Accept-Language: zh-CN\r\n")
    + std::string("Accept-Encoding: gzip, deflate\r\n")
    + std::string("User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko\r\n")
    + std::string("Host: testrail-tools.trendmicro.com\r\n")
    + std::string("Connection: Keep-Alive\r\n")
    + std::string("Cookie: _ga=GA1.2.1909963682.1524537669; _gid=GA1.2.563928490.1529501401\r\n")
  );
  if(r->isParsed()){
    std::cout << "mehtod "<< r->getMethod() << "|" << std::endl;
    std::cout << "url "<< r->getUrl() << "|" << std::endl;
    std::cout << "host "<< r->getHost() << "|" << std::endl;
    std::cout << "path "<< r->getPath() << "|" << std::endl; 
    std::cout << "agent "<< r->getAgent() << "|" << std::endl;
    std::cout << "accept "<< r->getAccept() << "|" << std::endl;
    std::cout << "accept-encoding "<< r->getAcceptEncoding() << "|" << std::endl;
    if(r->getMethod() == "GET"){
      std::map<std::string,std::string> getParams = r->paramsOfget();
    }
  }else{
    Log::debug(r->getParseError());
  }
    

  return 0;
}