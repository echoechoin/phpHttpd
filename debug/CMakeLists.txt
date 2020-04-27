cmake_minimum_required (VERSION 2.6)
include_directories(./)
include_directories(../httpd_config)

add_library(debuger debug.cpp)
target_link_libraries(debuger httpd_config)