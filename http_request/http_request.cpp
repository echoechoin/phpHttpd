#include "http_request.h"

HttpRequest::HttpRequest(std::string request){
  this->request = request;

  ///< 初始化所有的成员
  this->method = "";
  this->url ="";
  this->lineCount = -1;
  this->parseStatus = false;
  this->error = "unknown error.";

  ///< 获取各个成员的值
  if(this->getMethod() == "")
    goto step;
  if(this->getUrl() == "")
    goto step;

  this->parseStatus = true;
step:
  while(0);
}
bool HttpRequest::isParsed(){
  return this->parseStatus;
}
int HttpRequest::getLineCount(){
  if(this->lineCount != -1){
    return this->lineCount;
  }
  int count = 0;
  for(int i = 0; i < this->request.length();i++){
    if(this->request[i] == '\n');
    i++;
  }
  this->lineCount = count;
  return this->lineCount;
}
std::string HttpRequest::getMethod(){
  if(this->method.length() != 0)
    return this->method;
  std::string tmp = this->request.substr(0,this->request.find(' ',0));
  if(!tmp.compare("GET") || !tmp.compare("POST") || !tmp.compare("HEAD") || !tmp.compare("PUT")
    || !tmp.compare("PUT") || !tmp.compare("DELETE") || !tmp.compare("CONNECT") || !tmp.compare("OPTIONS") || !tmp.compare("TRACE")){
    this->method = tmp;
  }else{
    this->error = "can not match any method!";
    this->parseStatus = false;
  } 
  return this->method;
}
std::string HttpRequest::getUrl(){
  if(this->url.length() != 0)
    return this->url;
  int pos1 = this->request.find(' ',0);
  int pos2 = this->request.find(' ',pos1+1);
  std::string tmp = this->request.substr(pos1+1,pos2-pos1);

  // TODO 使用正则表达式验证是否为一个有效的路径
  if(this->isURL(tmp)){
    this->url = tmp;
  }else{
    this->error = "Invalid url";
    this->parseStatus = false;
  }
  return this->url;
}
std::string HttpRequest::getParseError(){
  return this->error;
}
bool  HttpRequest::isURL(std::string url){
  return true;
}