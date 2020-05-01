cmake_minimum_required (VERSION 2.6)

include_directories(./)
include_directories(../debug)

add_library(response response.cpp)
target_link_libraries(response debuger)
