#include <string>
#include <iostream>
#include "httpd-config.h"
#include "debug.h"
#include "event_loop.h"
#include "http_request.h"
#include <map>

int main ( int argc, char *argv[] ){
 //  Log::enable(); ///< 初始化Loger
  
  // HttpRequest *r = new HttpRequest(std::string("POST /123/?id=123&qq=1233 HTTP/1.1\r\n")   
  //   + std::string("Accept: application/json, text/javascript, */*; q=0.01\n")
  //   + std::string("X-Requested-With: XMLHttpRequest\r\n")
  //   + std::string("Referer: https://testrail-tools.trendmicro.com/portal/admin/toLicenseTimerConfig?id=7\r\n")
  //   + std::string("Content-Length: 99\r\n")
  //   + std::string("Content-Type: application/x-www-form-urlencoded\r\n")
  //   + std::string("Accept-Language: zh-CN\r\n")
  //   + std::string("Accept-Encoding: gzip, deflate\r\n")
  //   + std::string("User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko\r\n")
  //   + std::string("Host: testrail-tools.trendmicro.com\r\n")
  //   + std::string("Connection: Keep-Alive\r\n")
  //   + std::string("Cookie: _ga=GA1.2.1909963682.1524537669; _gid=GA1.2.563928490.1529501401\n")
  //   + std::string("\r\n")
  //   + std::string("idddd=admin&qq111=c%2B%2B%20%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4%E5%A4%B4%E6%96%87%E4%BB%B6%E5%92%8Cc%E6%96%87%E4%BB%B6")
  // );
  // if(r->isParsed()){
  //   std::cout << "mehtod "<< r->getMethod() << "EOL" << std::endl;
  //   std::cout << "url "<< r->getUrl() << "EOL" << std::endl;
  //   std::cout << "host "<< r->getHost() << "EOL" << std::endl;
  //   std::cout << "path "<< r->getPath() << "EOL" << std::endl; 
  //   std::cout << "agent "<< r->getAgent() << "EOL" << std::endl;
  //   std::cout << "accept "<< r->getAccept() << "EOL" << std::endl;
  //   std::cout << "accept-encoding "<< r->getAcceptEncoding() << "EOL" << std::endl;
  //   if(r->getMethod().compare("GET") == 0){
  //     std::cout << "get params:" << std::endl;
  //     std::map<std::string,std::string> Params = r->paramsOfGet();
  //     for(std::map<std::string,std::string>::iterator it = Params.begin();it != Params.end(); it++){
  //       std::cout << (*it).first << ":" << (*it).second << "EOL" << std::endl;
  //     }
  //   }
  //   if(r->getMethod().compare("POST") == 0){
  //     std::cout << "content-length " << r->getContentLength() << "EOL" << std::endl;
  //     std::cout << "conten-type " << r->getContentType() << "EOL" << std::endl;
  //     std::map<std::string,std::string> Params = r->paramsOfPost();
  //     std::cout << "post params:" << std::endl;
  //     for(std::map<std::string,std::string>::iterator it = Params.begin();it != Params.end(); it++){
  //       std::cout << (*it).first << ":" << (*it).second << "EOL" << std::endl;
  //     }
  //   }
  // }else{
  //   Log::debug(r->getParseError());
  // }

  EventLoop e;
  e.startup();
  return 0;
}