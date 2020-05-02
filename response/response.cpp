#include "response.h"

std::string Response::serverInfo = "PHP SERVER";
std::string Response::getStatus(unsigned status){
  switch (status)
  {
  case 200:
    return "HTTP/1.0 200 OK\r\n";
  case 404:
    return "HTTP/1.0 404 NOT FOUND\r\n";
  case 501:
    return "HTTP/1.0 501 SERVER ERROR\r\n";
  case 502:
    return "HTTP/1.0 501 NOT SUPPORTED\r\n";
  default:
    return "HTTP/1.0 200 OK\r\n";
  }
}
std::string Response::getServer(){
  return std::string("Server: ") + Response::serverInfo + std::string("\r\n");
}
std::string Response::getContentLength(unsigned int length){
  char num[1024] = {0};
  sprintf(num,"%d",length);
  return std::string("Content-Length: ") + std::string(num) + std::string("\r\n");
}
std::string Response::getContenType(std::string path){
  std::string type;
  std::string ext = path.substr(path.rfind('.'),path.length()-path.rfind('.'));
  if(ext.compare(".html") == 0){
    type = "text/html";
  }else if(ext.compare(".css") == 0){
    type = "text/css";
  }else if(ext.compare(".js") == 0){
    type = "application/javascript";
  }
  return std::string("Content-Type: ") + type + std::string("\r\n");
}