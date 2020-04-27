cmake_minimum_required (VERSION 2.6)
project (phpHttpd)

add_subdirectory(./httpd_config)
add_subdirectory(./debug)

include_directories(./httpd_config)
include_directories(./debug)

add_executable(phpHttpd main.cpp)
target_link_libraries(phpHttpd httpd_config)
target_link_libraries(phpHttpd pthread)
target_link_libraries(phpHttpd debuger)
