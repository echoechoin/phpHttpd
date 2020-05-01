cmake_minimum_required (VERSION 2.6)

include_directories(./)
include_directories(../debug)
include_directories(../httpd_config)
include_directories(../http_request)
include_directories(../response)

add_library(event_loop event_loop.cpp)
target_link_libraries(event_loop event)
target_link_libraries(event_loop debuger)
target_link_libraries(event_loop http_request)
target_link_libraries(event_loop httpd_config)
target_link_libraries(event_loop response)