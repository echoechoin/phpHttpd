#include "debug.h"
#include <unistd.h>
int Log::logMode = 1;
std::string Log::logFilePath;
bool Log::isEnabled = false;
bool Log::isEnableDebug = true;
/**
 * @brief Log构造函数，主要用于Enable/Disable Logger
 * @param isEnable 是否启动Logger
 */
Log::Log(bool isEnable){
  HttpdConfig *c = HttpdConfig::getInstance();
  Log::logMode = c->getLogMode();
  Log::logFilePath = c->getLogFilePath();
  Log::isEnabled = isEnable;
}
/**
 * @brief Enable Logger
 * @return 0
 *  0 表示成功
 */
int Log::enable(){
  Log *tmp = new Log(true);
  delete tmp;
  return 0;
}
/**
 * @brief Disable Logger
 * @return 0
 *  0 表示成功
 */
int Log::disable(){
  Log *tmp = new Log(false);
  delete tmp;
  return 0;
}
// 默认enable
int Log::enableDebug(){
  Log::isEnableDebug = true;
}
int Log::disableDebug(){ 
  Log::isEnableDebug = false;
  daemon(1,0);
}
/**
 * @brief info 记录
 * @return 0 或 -1
 *  0 表示成功 -1 表示没有启动Logger
 */
int Log::info(std::string info){
  if(!isEnabled){
    return -1;
  }
  if(Log::logMode == 1){

  }else{
    std::cout << "\033[32m[" << __FILE__ << ": " <<__LINE__ << "] info:\033[0m " ;
    std::cout << info << std::endl;
  }
}
/**
 * @brief warning 记录
 * @return 0 或 -1
 *  0 表示成功 -1 表示没有启动Logger
 */
int Log::warning(std::string warning){
  if(!isEnabled){
    return -1;
  }
  if(Log::logMode == 1){

  }else{
    std::cout << "\033[33m[" << __FILE__ << ": " <<__LINE__ << "] warning:\033[0m " ;
    std::cout << warning << std::endl;
  }
}
/**
 * @brief error 记录
 * @return 0 或 -1
 *  0 表示成功 -1 表示没有启动Logger
 */
int Log::error(std::string error){
  if(!isEnabled){
    return -1;
  }
  if(Log::logMode == 1){

  }else{
    std::cout << "\033[31m[" << __FILE__ << ": " <<__LINE__ << "] error:\033[0m " ;
    std::cout << error << std::endl;
  }
}
/**
 * @brief debug 记录
 * @return 0 或 -1
 *  0 表示成功 -1 表示没有启动Logger
 */
int Log::debug(std::string debug){
  if(!Log::isEnabled ){
    return -1;
  }
  if(!Log::isEnableDebug){
    return -1;
  }
  if(Log::logMode == 1){
    ///< no permission
  }else{
    // std::cout << "[" << __FILE__ << ": " <<__LINE__ << "] " << debug << std::endl;
    std::cout << ">> \033[36m"<< debug << "\033[0m" << std::endl;
  }
}