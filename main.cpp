#include <string>
#include <iostream>
#include "httpd-config.h"
#include "debug.h"
#include "event_loop.h"
#include "http_request.h"
#include <map>

int main ( int argc, char *argv[] ){
  HttpdConfig::httpdConfigInit();
  HttpdConfig *c = HttpdConfig::getInstance();
  c->configCheck();

  Log::enable();
  Log::debug("phpHttpd start listening...");
  Log::disableDebug();

  EventLoop e;
  e.startup();
  return 0;
}