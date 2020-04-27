cmake_minimum_required (VERSION 2.6)
include_directories(./)

add_library(httpd_config CJsonObject.cpp httpd-config.cpp cJSON.c)
target_link_libraries(httpd_config pthread)