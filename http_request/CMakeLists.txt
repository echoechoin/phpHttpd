cmake_minimum_required (VERSION 2.6)

include_directories(./)
include_directories(../debug)
include_directories(../httpd_config)

add_library(http_request http_request.cpp)
target_link_libraries(http_request debuger)
target_link_libraries(http_request httpd_config)