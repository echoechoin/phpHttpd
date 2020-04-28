cmake_minimum_required (VERSION 2.6)

include_directories(./)
include_directories(../debug)
include_directories(../httpd_config)

add_library(event_loop event_loop.cpp)
target_link_libraries(event_loop event)
target_link_libraries(event_loop debuger)