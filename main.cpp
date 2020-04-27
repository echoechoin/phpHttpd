#include <string>
#include <iostream>
#include "httpd-config.h"
#include "debug.h"
int main ( int argc, char *argv[] ){
  Log::enable(); ///< 初始化Loger
  Log::debug("123456");
  Log::error("1234");
  Log::warning("123r");
  Log::info("1234erf");
  return 0;
}