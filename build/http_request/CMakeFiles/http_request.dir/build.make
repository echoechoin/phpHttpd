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
include http_request/CMakeFiles/http_request.dir/depend.make

# Include the progress variables for this target.
include http_request/CMakeFiles/http_request.dir/progress.make

# Include the compile flags for this target's objects.
include http_request/CMakeFiles/http_request.dir/flags.make

http_request/CMakeFiles/http_request.dir/http_request.cpp.o: http_request/CMakeFiles/http_request.dir/flags.make
http_request/CMakeFiles/http_request.dir/http_request.cpp.o: ../http_request/http_request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/httpd_project/phpHttpd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object http_request/CMakeFiles/http_request.dir/http_request.cpp.o"
	cd /home/echo/httpd_project/phpHttpd/build/http_request && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_request.dir/http_request.cpp.o -c /home/echo/httpd_project/phpHttpd/http_request/http_request.cpp

http_request/CMakeFiles/http_request.dir/http_request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_request.dir/http_request.cpp.i"
	cd /home/echo/httpd_project/phpHttpd/build/http_request && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/echo/httpd_project/phpHttpd/http_request/http_request.cpp > CMakeFiles/http_request.dir/http_request.cpp.i

http_request/CMakeFiles/http_request.dir/http_request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_request.dir/http_request.cpp.s"
	cd /home/echo/httpd_project/phpHttpd/build/http_request && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/echo/httpd_project/phpHttpd/http_request/http_request.cpp -o CMakeFiles/http_request.dir/http_request.cpp.s

http_request/CMakeFiles/http_request.dir/http_request.cpp.o.requires:

.PHONY : http_request/CMakeFiles/http_request.dir/http_request.cpp.o.requires

http_request/CMakeFiles/http_request.dir/http_request.cpp.o.provides: http_request/CMakeFiles/http_request.dir/http_request.cpp.o.requires
	$(MAKE) -f http_request/CMakeFiles/http_request.dir/build.make http_request/CMakeFiles/http_request.dir/http_request.cpp.o.provides.build
.PHONY : http_request/CMakeFiles/http_request.dir/http_request.cpp.o.provides

http_request/CMakeFiles/http_request.dir/http_request.cpp.o.provides.build: http_request/CMakeFiles/http_request.dir/http_request.cpp.o


# Object files for target http_request
http_request_OBJECTS = \
"CMakeFiles/http_request.dir/http_request.cpp.o"

# External object files for target http_request
http_request_EXTERNAL_OBJECTS =

http_request/libhttp_request.a: http_request/CMakeFiles/http_request.dir/http_request.cpp.o
http_request/libhttp_request.a: http_request/CMakeFiles/http_request.dir/build.make
http_request/libhttp_request.a: http_request/CMakeFiles/http_request.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/echo/httpd_project/phpHttpd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhttp_request.a"
	cd /home/echo/httpd_project/phpHttpd/build/http_request && $(CMAKE_COMMAND) -P CMakeFiles/http_request.dir/cmake_clean_target.cmake
	cd /home/echo/httpd_project/phpHttpd/build/http_request && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_request.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
http_request/CMakeFiles/http_request.dir/build: http_request/libhttp_request.a

.PHONY : http_request/CMakeFiles/http_request.dir/build

http_request/CMakeFiles/http_request.dir/requires: http_request/CMakeFiles/http_request.dir/http_request.cpp.o.requires

.PHONY : http_request/CMakeFiles/http_request.dir/requires

http_request/CMakeFiles/http_request.dir/clean:
	cd /home/echo/httpd_project/phpHttpd/build/http_request && $(CMAKE_COMMAND) -P CMakeFiles/http_request.dir/cmake_clean.cmake
.PHONY : http_request/CMakeFiles/http_request.dir/clean

http_request/CMakeFiles/http_request.dir/depend:
	cd /home/echo/httpd_project/phpHttpd/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/echo/httpd_project/phpHttpd /home/echo/httpd_project/phpHttpd/http_request /home/echo/httpd_project/phpHttpd/build /home/echo/httpd_project/phpHttpd/build/http_request /home/echo/httpd_project/phpHttpd/build/http_request/CMakeFiles/http_request.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : http_request/CMakeFiles/http_request.dir/depend

