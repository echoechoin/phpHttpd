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
CMAKE_SOURCE_DIR = /home/echo/httpd_project/phpHttpd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/echo/httpd_project/phpHttpd/build

# Include any dependencies generated for this target.
include CMakeFiles/phpHttpd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phpHttpd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phpHttpd.dir/flags.make

CMakeFiles/phpHttpd.dir/main.cpp.o: CMakeFiles/phpHttpd.dir/flags.make
CMakeFiles/phpHttpd.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/httpd_project/phpHttpd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phpHttpd.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phpHttpd.dir/main.cpp.o -c /home/echo/httpd_project/phpHttpd/main.cpp

CMakeFiles/phpHttpd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phpHttpd.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/echo/httpd_project/phpHttpd/main.cpp > CMakeFiles/phpHttpd.dir/main.cpp.i

CMakeFiles/phpHttpd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phpHttpd.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/echo/httpd_project/phpHttpd/main.cpp -o CMakeFiles/phpHttpd.dir/main.cpp.s

CMakeFiles/phpHttpd.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/phpHttpd.dir/main.cpp.o.requires

CMakeFiles/phpHttpd.dir/main.cpp.o.provides: CMakeFiles/phpHttpd.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/phpHttpd.dir/build.make CMakeFiles/phpHttpd.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/phpHttpd.dir/main.cpp.o.provides

CMakeFiles/phpHttpd.dir/main.cpp.o.provides.build: CMakeFiles/phpHttpd.dir/main.cpp.o


# Object files for target phpHttpd
phpHttpd_OBJECTS = \
"CMakeFiles/phpHttpd.dir/main.cpp.o"

# External object files for target phpHttpd
phpHttpd_EXTERNAL_OBJECTS =

phpHttpd: CMakeFiles/phpHttpd.dir/main.cpp.o
phpHttpd: CMakeFiles/phpHttpd.dir/build.make
phpHttpd: httpd_config/libhttpd_config.a
phpHttpd: debug/libdebuger.a
phpHttpd: event/libevent_loop.a
phpHttpd: http_request/libhttp_request.a
phpHttpd: response/libresponse.a
phpHttpd: debug/libdebuger.a
phpHttpd: httpd_config/libhttpd_config.a
phpHttpd: CMakeFiles/phpHttpd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/echo/httpd_project/phpHttpd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable phpHttpd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phpHttpd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phpHttpd.dir/build: phpHttpd

.PHONY : CMakeFiles/phpHttpd.dir/build

CMakeFiles/phpHttpd.dir/requires: CMakeFiles/phpHttpd.dir/main.cpp.o.requires

.PHONY : CMakeFiles/phpHttpd.dir/requires

CMakeFiles/phpHttpd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phpHttpd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phpHttpd.dir/clean

CMakeFiles/phpHttpd.dir/depend:
	cd /home/echo/httpd_project/phpHttpd/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/echo/httpd_project/phpHttpd /home/echo/httpd_project/phpHttpd /home/echo/httpd_project/phpHttpd/build /home/echo/httpd_project/phpHttpd/build /home/echo/httpd_project/phpHttpd/build/CMakeFiles/phpHttpd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phpHttpd.dir/depend

