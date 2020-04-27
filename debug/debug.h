#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include "httpd-config.h"
class Log{
  public:
    static int enable();
    static int disable();
    static int info(std::string info);
    static int warning(std::string warning);
    static int error(std::string error);
    static int debug(std::string debug);
  private:
    Log(bool);
    static int logMode;                  ///< 0：日志输出到stdout, 1：日志输出到file
    static std::string logFilePath;      ///< 日志输出文件地址
    static bool isEnabled;               ///< 是否启动了debuger
};
#endif