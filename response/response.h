#include <stdio.h>
#include <string>
#include <iostream>

#ifndef RESPONSE_H
#define RESPONSE_H

class Response{
  public:
    std::string getStatus(unsigned status);
    std::string getServer();
    std::string getContentLength(unsigned int length);
    std::string getContenType(std::string path);
  private:
    static std::string serverInfo;
};



#endif