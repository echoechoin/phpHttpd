cmake_minimum_required (VERSION 2.6)
project (phpHttpd)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# 子模块
add_subdirectory(./httpd_config)
add_subdirectory(./debug)
add_subdirectory(./event)
add_subdirectory(./http_request)

# 头文件路径
include_directories(./httpd_config)
include_directories(./debug)
include_directories(./event)
include_directories(./http_request)

# 编译成可执行文件
add_executable(phpHttpd main.cpp)

# 链接静态库
target_link_libraries(phpHttpd httpd_config)
target_link_libraries(phpHttpd pthread)
target_link_libraries(phpHttpd debuger)
target_link_libraries(phpHttpd event_loop)
target_link_libraries(phpHttpd http_request)

