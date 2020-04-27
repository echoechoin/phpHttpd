# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/echo/httpd_project/httpd-0.0.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/echo/httpd_project/httpd-0.0.2/build

# Include any dependencies generated for this target.
include httpd_config/CMakeFiles/cppjson.dir/depend.make

# Include the progress variables for this target.
include httpd_config/CMakeFiles/cppjson.dir/progress.make

# Include the compile flags for this target's objects.
include httpd_config/CMakeFiles/cppjson.dir/flags.make

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o: httpd_config/CMakeFiles/cppjson.dir/flags.make
httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o: ../httpd_config/CJsonObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/httpd_project/httpd-0.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o"
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppjson.dir/CJsonObject.cpp.o -c /home/echo/httpd_project/httpd-0.0.2/httpd_config/CJsonObject.cpp

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppjson.dir/CJsonObject.cpp.i"
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/echo/httpd_project/httpd-0.0.2/httpd_config/CJsonObject.cpp > CMakeFiles/cppjson.dir/CJsonObject.cpp.i

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppjson.dir/CJsonObject.cpp.s"
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/echo/httpd_project/httpd-0.0.2/httpd_config/CJsonObject.cpp -o CMakeFiles/cppjson.dir/CJsonObject.cpp.s

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.requires:

.PHONY : httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.requires

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.provides: httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.requires
	$(MAKE) -f httpd_config/CMakeFiles/cppjson.dir/build.make httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.provides.build
.PHONY : httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.provides

httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.provides.build: httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o


# Object files for target cppjson
cppjson_OBJECTS = \
"CMakeFiles/cppjson.dir/CJsonObject.cpp.o"

# External object files for target cppjson
cppjson_EXTERNAL_OBJECTS =

httpd_config/libcppjson.a: httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o
httpd_config/libcppjson.a: httpd_config/CMakeFiles/cppjson.dir/build.make
httpd_config/libcppjson.a: httpd_config/CMakeFiles/cppjson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/echo/httpd_project/httpd-0.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcppjson.a"
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && $(CMAKE_COMMAND) -P CMakeFiles/cppjson.dir/cmake_clean_target.cmake
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppjson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
httpd_config/CMakeFiles/cppjson.dir/build: httpd_config/libcppjson.a

.PHONY : httpd_config/CMakeFiles/cppjson.dir/build

httpd_config/CMakeFiles/cppjson.dir/requires: httpd_config/CMakeFiles/cppjson.dir/CJsonObject.cpp.o.requires

.PHONY : httpd_config/CMakeFiles/cppjson.dir/requires

httpd_config/CMakeFiles/cppjson.dir/clean:
	cd /home/echo/httpd_project/httpd-0.0.2/build/httpd_config && $(CMAKE_COMMAND) -P CMakeFiles/cppjson.dir/cmake_clean.cmake
.PHONY : httpd_config/CMakeFiles/cppjson.dir/clean

httpd_config/CMakeFiles/cppjson.dir/depend:
	cd /home/echo/httpd_project/httpd-0.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/echo/httpd_project/httpd-0.0.2 /home/echo/httpd_project/httpd-0.0.2/httpd_config /home/echo/httpd_project/httpd-0.0.2/build /home/echo/httpd_project/httpd-0.0.2/build/httpd_config /home/echo/httpd_project/httpd-0.0.2/build/httpd_config/CMakeFiles/cppjson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : httpd_config/CMakeFiles/cppjson.dir/depend
