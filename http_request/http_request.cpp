#include "http_request.h"
namespace urldecode{
  char dec2hexChar(short int n) {
  if ( 0 <= n && n <= 9 ) {
    return char( short('0') + n );
    } else if ( 10 <= n && n <= 15 ) {
      return char( short('A') + n - 10 );
    } else {
      return char(0);
    }
  }
  
  short int hexChar2dec(char c) {
  if ( '0'<=c && c<='9' ) {
    return short(c-'0');
    } else if ( 'a'<=c && c<='f' ) {
      return ( short(c-'a') + 10 );
    } else if ( 'A'<=c && c<='F' ) {
      return ( short(c-'A') + 10 );
    } else {
      return -1;
    }
  }
  
  std::string escapeURL(const std::string &URL)
  {
    std::string result = "";
    for ( unsigned int i=0; i<URL.size(); i++ ) {
      char c = URL[i];
      if (
      ( '0'<=c && c<='9' ) ||
      ( 'a'<=c && c<='z' ) ||
      ( 'A'<=c && c<='Z' ) ||
      c=='/' || c=='.'
      ) {
      result += c;
      } else {
      int j = (short int)c;
      if ( j < 0 ) {
        j += 256;
      }
      int i1, i0;
      i1 = j / 16;
      i0 = j - i1*16;
      result += '%';
      result += dec2hexChar(i1);
      result += dec2hexChar(i0);
      }
    }
    return result;
  }
  
  std::string deescapeURL(const std::string &URL) {
    std::string result = "";
    for ( unsigned int i=0; i<URL.size(); i++ ) {
      char c = URL[i];
      if ( c != '%' ) {
      result += c;
      } else {
      char c1 = URL[++i];
      char c0 = URL[++i];
      int num = 0;
      num += hexChar2dec(c1) * 16 + hexChar2dec(c0);
      result += char(num);
      }
    }
    return result;
  }
  
  int example()
  {
    std::string str = "你好 世界";
    std::string temp = escapeURL(str);
    std::cout<<temp<<std::endl;
    std::cout<<deescapeURL(temp)<<std::endl;
    getchar();
    return 0;
  }
}
HttpRequest::~HttpRequest(){};
HttpRequest::HttpRequest(std::string request){
   this->request = request;
  //std::cout << this->request << std::endl;
  ///< 初始化所有的成员
  this->method = "";
  this->url ="";
  // this->lineCount = -1;
  this->parseStatus = false;
  this->error = "unknown error.";
  this->host = "";
  this->path = "";
  this->accept_encoding = "";
  this->accept = "";
  this->agent = "";

  std::vector<std::string> lines;
  unsigned int lineNum = 0;
  std::size_t start = 0;
  std::size_t end = 0;
  bool isRequestHead = true;
  ///< 获取各个成员的值 有错就直接跳出
  if(this->getMethod() == "")
    goto step;
  if(this->getUrl() == "")
    goto step;
  if(this->getPath() == "")
    goto step;

  ///< 获取每一行
  while(true){
    end = this->request.find('\n',start);
   // std::cout <<start << ":" << end << ":" << this->request.length() << std::endl;
    if(start == this->request.length()){
      break;
    }
    if(end == this->request.npos){
      lines.push_back(request.substr(start,this->request.length()-start));
     // std::cout << request.substr(start,this->request.length()-start).length() << std::endl;
     // std::cout << request.substr(start,this->request.length()-start) << "1234" << std::endl;
      break;
    }else{
      lines.push_back(request.substr(start,end-start));
     // std::cout << request.substr(start,end-start).length() << std::endl;
     // std::cout << request.substr(start,end-start) << "1234" <<std::endl;
    }
    start = end + 1;
  }

  ///< 获取元素中的数据
  for(std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it){
    ///< 移除结尾的\r\n
    std::string line = *it;
    for(std::string::iterator it2 = line.begin();it2 != line.end();it2){
      if(*it2 == '\r' || *it2 == '\n'){
        std::string::iterator temp = line.erase(it2);
        it2 = temp;
        continue;
      }
      it2++;
    }
    lineNum++;
    if(it == lines.begin())continue;

    if(line.length() == 0){
      isRequestHead = false;
    }
    ///< 请求头处理
    if(isRequestHead){
      int middlePos = (line).find(':');
      if(middlePos == (line).npos || (line)[middlePos+1] != ' '){
        char lN[10];
        sprintf(lN,"%d",lineNum);
        this->error = std::string("syntax error at line ") + std::string(lN) + std::string(": ")
          + (line);
        goto step;
      }
      std::string key = (line).substr(0, middlePos);
      std::string value = (line).substr(middlePos+2, (line).length());
      if(key.compare("User-Agent") == 0){
        this->agent = value;
      }else if(key.compare("Cookie") == 0){
        // TODO: 将cooke保存到cookies
      }else if(key.compare("Accept") == 0){
        this->accept = value;
      }else if(key.compare("Accept-Encoding") == 0){
        this->accept_encoding = value;
      }else if(key.compare("Content-Type") == 0){
        this->contentType = value;
      }else if(key.compare("Content-Length") == 0){
        this->contentLength = atoi(value.c_str());
      }else if(key.compare("Host") == 0){
        this->host = atoi(value.c_str());
      }
      // std::cout << (line).substr(0, middlePos) << ": ";
      // std::cout << (line).substr(middlePos+2, (line).length()) << std::endl;
    }

    ///< 请求体处理
    else if(this->method.compare("POST") == 0){ 
      if(line.length() == 0)
        continue;
      if(this->getContentType().compare("application/x-www-form-urlencoded") == 0){ ///< 普通post请求
        std::string paramsStr = line;
        std::map<std::string,std::string> t;
        unsigned int start = 0;
        unsigned int end = 0;

        std::string kv;
        while(true){
          if(paramsStr.find('&',start) == paramsStr.npos){
            kv = paramsStr.substr(start,paramsStr.length()-start);
            // std::cout << kv << std::endl;
            if(kv.find('=') == kv.npos)
              break;
            std::string k = kv.substr(0,kv.find('='));
            std::string v = kv.substr(kv.find('=')+1,kv.length()-kv.find('=')-1);
            //std::cout << k << v << std::endl;
            t.insert(std::pair<std::string,std::string>(urldecode::deescapeURL(k),urldecode::deescapeURL(v)));
            break;
          }else{
            end = paramsStr.find('&',start);
            kv = paramsStr.substr(start,end-start);
          //  std::cout << kv << std::endl;
            if(kv.find('=') == kv.npos)
              break;
            std::string k = kv.substr(0,kv.find('='));
            std::string v = kv.substr(kv.find('=')+1,kv.length()-kv.find('=')-1);
            //std::cout << k << v << std::endl;
           t.insert(std::pair<std::string,std::string>(urldecode::deescapeURL(k),urldecode::deescapeURL(v)));
          }
          start = end+1;
        }
        this->post = t;
      }
    }
  }

  this->parseStatus = true;
step:
  while(0);
}
bool HttpRequest::isParsed(){
  return this->parseStatus;
}
// int HttpRequest::getLineCount(){
//   if(this->lineCount != -1){
//     return this->lineCount;
//   }
//   int count = 0;
//   for(int i = 0; i < this->request.length();i++){
//     if(this->request[i] == '\n')
//       count++;
//   }
//   this->lineCount = count;
//   return this->lineCount;
// }
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
  std::string tmp = this->request.substr(pos1+1,pos2-(pos1+1));

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
std::string HttpRequest::getHost(){
  return this->host; 
}
std::string HttpRequest::getPath(){
  if(this->path.length() != 0){
    return this->path;
  }
  if(this->url.length() != 0){
    std::size_t path_start = 0;
    std::size_t path_end = this->url.find('?',path_start);
    if(path_end != this->url.npos)
      this->path = this->url.substr(path_start,path_end-path_start);
    else
      this->path = this->url.substr(path_start,this->url.length());
  }
  this->parseStatus = false;
  this->error = "Invalid url";
  return this->path;
}
bool  HttpRequest::isURL(std::string url){
  return true;
}
std::string HttpRequest::getAgent(){
  return this->agent;
}
std::string HttpRequest::getAccept(){
  return this->accept;
}
std::string HttpRequest::getAcceptEncoding(){
  return this->accept_encoding;
}
unsigned int HttpRequest::getContentLength(){
  return this->contentLength;
}
std::string HttpRequest::getContentType(){
  return this->contentType;
}
std::map<std::string,std::string> HttpRequest::paramsOfGet(){
  std::map<std::string,std::string> t;
  if(this->url.find('?') == this->url.npos){
    return t;
  }
  std::string paramsStr = this->url.substr(this->url.find('?')+1,this->url.length()-this->url.find('?')-1);
  if(paramsStr.length() == 0){
    return t;
  }
  // std::cout << paramsStr;
  unsigned int start = 0;
  unsigned int end = 0;

  std::string kv;
  while(true){
    if(paramsStr.find('&',start) == paramsStr.npos){
      kv = paramsStr.substr(start,paramsStr.length()-start);
      // std::cout << kv << std::endl;
      if(kv.find('=') == kv.npos)
        break;
      std::string k = kv.substr(0,kv.find('='));
      std::string v = kv.substr(kv.find('=')+1,kv.length()-kv.find('=')-1);
      //std::cout << k << v << std::endl;
      t.insert(std::pair<std::string,std::string>(urldecode::deescapeURL(k),urldecode::deescapeURL(v)));
      break;
    }else{
      end = paramsStr.find('&',start);
      kv = paramsStr.substr(start,end-start);
     //  std::cout << kv << std::endl;
      if(kv.find('=') == kv.npos)
        break;
      std::string k = kv.substr(0,kv.find('='));
      std::string v = kv.substr(kv.find('=')+1,kv.length()-kv.find('=')-1);
      //std::cout << k << v << std::endl;
      t.insert(std::pair<std::string,std::string>(urldecode::deescapeURL(k),urldecode::deescapeURL(v)));;
    }
    start = end+1;
  }
  return t;
}
std::map<std::string,std::string> HttpRequest::paramsOfPost(){
  return this->post;
}