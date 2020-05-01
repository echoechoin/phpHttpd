cmake_minimum_required (VERSION 2.6)
project (phpHttpd)

# 子模块
add_subdirectory(./httpd_config)
add_subdirectory(./debug)
add_subdirectory(./event)
add_subdirectory(./http_request)
add_subdirectory(./response)

# 头文件路径
include_directories(./httpd_config)
include_directories(./debug)
include_directories(./event)
include_directories(./http_request)
include_directories(./response)

# 编译成可执行文件
add_executable(phpHttpd main.cpp)

# 链接静态库
target_link_libraries(phpHttpd httpd_config)
target_link_libraries(phpHttpd pthread)
target_link_libraries(phpHttpd debuger)
target_link_libraries(phpHttpd event_loop)
target_link_libraries(phpHttpd http_request)
target_link_libraries(phpHttpd response)

