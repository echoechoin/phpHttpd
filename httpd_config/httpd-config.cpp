#include "httpd-config.h"

HttpdConfig* HttpdConfig::configInstance = NULL;

pthread_mutex_t HttpdConfig::mutex;
/**
 * @brief 构造函数，解析httpd_config.json文件获取数据信息
 */
HttpdConfig::HttpdConfig(){
  std::ifstream configFileStream;
  configFileStream.open("./httpd_config/httpd_config.json");
  if(!configFileStream){
    perror("open configure file failed! cause:");
    exit(-1);
  }
  std::string configStr;
  while(!configFileStream.eof()){
    std::string tempStr;
    configFileStream >> tempStr;
    configStr += tempStr;
  }
  configFileStream.close();
  neb::CJsonObject configJsonObject(configStr);
  if(configJsonObject.IsEmpty()){
    std::cout << configJsonObject.GetErrMsg() << std::endl;
    exit(-1);
  }
  /* ip */
  (configJsonObject["server"]("listenAddress").length() != 0) ? 
    (this->listenAddress = configJsonObject["server"]("listenAddress")) :
    (this->listenAddress = "127.0.0.1");
  /* port */
  configJsonObject["server"]("listenPort").length() != 0 && atoi(configJsonObject["server"]("listenPort").c_str()) < 65536 && atoi(configJsonObject["server"]("listenPort").c_str()) > 0 ? 
    this->listenPort = atoi(configJsonObject["server"]("listenPort").c_str()) :
    this->listenPort = 80;
  /* server mode */
  configJsonObject["server"]("mode").length() != 0 && (!configJsonObject["server"]("mode").compare("php") || !configJsonObject["server"]("mode").compare("default"))?
    this->serverMode = configJsonObject["server"]("mode") :
    this->serverMode = "default";

  /* php entrace file path */
  configJsonObject["phpConfig"]("entraceFilePath").length() != 0 ?
    this->phpEntraceFilePath = configJsonObject["phpConfig"]("entraceFilePath") :
    this->phpEntraceFilePath = "./++++++++++++++++++++++++++++++++++++++++==";
  /* fcgi socket path */
  configJsonObject["phpConfig"]("fastcigSocketFilePath").length() != 0 ?
    this->phpFastcigSocketFilePath = configJsonObject["phpConfig"]("fastcigSocketFilePath") :
    this->phpFastcigSocketFilePath = "./+++++++++++++++++++++++++++++++++++++++++";

  /* log file path */
  configJsonObject["debug"]("logFilePath").length() != 0 ?
   this->logFilePath = configJsonObject["debug"]("logFilePath") :
   this->logFilePath = "./+++++++++++++++++++++++++++++++++++";
  /* log mode */
  configJsonObject["debug"]("logFilePath").compare("stdout") || configJsonObject["debug"]("logFilePath").compare("default") ?
  this->logMode = configJsonObject["debug"]("logMode") :
  this->logMode = "default";
}
HttpdConfig::~HttpdConfig(){
  std::cout << "destructor" << std::endl;
}


/** 
 * @brief 获取单例配置对象。
 * @return 单例对象HttpdConfigInstance。
 */
HttpdConfig* HttpdConfig::getInstance(){
  if(HttpdConfig::configInstance == NULL){
    pthread_mutex_lock(&HttpdConfig::mutex);
    if(HttpdConfig::configInstance == NULL){
      HttpdConfig::configInstance = new HttpdConfig();
    }
  }
  pthread_mutex_unlock(&HttpdConfig::mutex);
  return HttpdConfig::configInstance;
}
/** 
 * @brief 初始化线程所；线程不安全！请在线程初始化前完成此函数的调用。
 * @return 0 或-1
 * 成功返回0，失败返回1
 */
int HttpdConfig::httpdConfigInit(){
    pthread_mutex_init(&HttpdConfig::mutex,NULL);
}
/**
 * @brief 获取日志文件存储位置
 * @return string
 * 返回日志文件存储位置
 */
std::string HttpdConfig::getLogFilePath(){
  return this->logFilePath;
}
/**
 * @brief 获取监听的IP地址
 * @return string
 * 返回监听的IP地址 点分十进制 例"127.0.0.1"
 */
std::string HttpdConfig::getListenAddress(){
  return this->listenAddress;
}
/**
 * @brief 获取监听的端口
 * @return unsigned int
 * 返回监听的端口
 */
unsigned int HttpdConfig::getListenPort(){
  return this->listenPort;
}
/**
 * @brief 获取服务器的运行模式
 * @return string
 * "php"：表示以php为脚本作为服务器； "default"静态服务器。
 */
std::string HttpdConfig::getServerMode(){
  return this->serverMode;
}
/**
 * @brief 获取服务器的运行模式
 * @return 0 或 1
 * 0 直接从stdout输出
 * 1 输出到日志文件
 */
int HttpdConfig::getLogMode(){
  if(this->logMode == "stdout")
    return 0;
  else 
    return 1;
}
void HttpdConfig::getAllConfig(){
  std::cout.setf(std::ios::left);
  std::cout.width(25); std::cout << "listenAddress" << this->listenAddress << std::endl;
  std::cout.width(25); std::cout << "listenPort" << this->listenPort << std::endl;
  std::cout.width(25); std::cout << "logFilePath" << this->logFilePath << std::endl;
  std::cout.width(25); std::cout << "logMode" << this->logMode << std::endl;
  std::cout.width(25); std::cout << "phpEntraceFilePath" << this->phpEntraceFilePath << std::endl;
  std::cout.width(25); std::cout << "phpFastcigSocketFilePath" << this->phpFastcigSocketFilePath << std::endl;
  std::cout.width(25); std::cout << "serverMode" << this->serverMode << std::endl;

}