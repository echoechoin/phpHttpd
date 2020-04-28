#include <string>
#include <map>
#include "debug.h"
#include <regex.h>
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

    std::map<std::string,std::string> getParams();
    std::map<std::string,std::string> postParams();

    std::string getAgent();
    std::map<std::string,std::string> getCookies();

    std::string getAccept();
    std::string getAcceptEncoding();
  private:
    std::string request;
    std::string method;
    std::string url;
    std::string host;

    std::map<std::string,std::string> get;
    std::map<std::string,std::string> post;
    std::string agent;

    std::map<std::string,std::string> cookies;
    std::string accept;
    std::string accept_encoding;

    bool isURL(std::string url);
    int getLineCount();
    std::string error;
    bool parseStatus;
    int lineCount;
};

#endif