#include <string>
#include <iostream>
#include <pthread.h>
#include <fstream>
#include <stdlib.h>
#include "CJsonObject.h"
#ifndef HTTPD_CONFIG_H
#define HTTPD_CONFIG_H

class HttpdConfig{
  public: 
    ~HttpdConfig();
    static HttpdConfig* getInstance();
    static int httpdConfigInit();
    std::string getListenAddress();
    unsigned int getListenPort();
    std::string getServerMode();
    std::string getLogFilePath();
    std::string getRootPath();
    std::string getDefaultFile();
    std::string getEntraceFilePath();
    std::string getEntraceFileName();
    int getLogMode();
    void configCheck();
  private:
    HttpdConfig();

    static HttpdConfig* configInstance;          ///< 单例
    static pthread_mutex_t mutex;                ///< 互斥锁
    unsigned int listenPort;                     ///< 监听端口
    std::string listenAddress;                   ///< 监听地址

    std::string phpEntraceFilePath;              ///< php入口文件路径
    std::string phpEntraceFileName;              ///< php入口文件
    std::string phpFastcigSocketFilePath;        ///< php fastcgi本地套接字路径
    std::string serverMode;                      ///< 是否为php模式 php：指定php入口地址，default：指定文件跟路径

    std::string rootPath;                        ///< 静态web服务器的根路径

    std::string defaultFile;                     ///< 默认打开的文件

    std::string logFilePath;                     ///< 日志文件保存地址
    std::string logMode;                         ///< 文件还是直接输出日志 stdout | file
    
};

#endif