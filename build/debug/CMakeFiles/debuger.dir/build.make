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
include debug/CMakeFiles/debuger.dir/depend.make

# Include the progress variables for this target.
include debug/CMakeFiles/debuger.dir/progress.make

# Include the compile flags for this target's objects.
include debug/CMakeFiles/debuger.dir/flags.make

debug/CMakeFiles/debuger.dir/debug.cpp.o: debug/CMakeFiles/debuger.dir/flags.make
debug/CMakeFiles/debuger.dir/debug.cpp.o: ../debug/debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/httpd_project/httpd-0.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object debug/CMakeFiles/debuger.dir/debug.cpp.o"
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/debuger.dir/debug.cpp.o -c /home/echo/httpd_project/httpd-0.0.2/debug/debug.cpp

debug/CMakeFiles/debuger.dir/debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/debuger.dir/debug.cpp.i"
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/echo/httpd_project/httpd-0.0.2/debug/debug.cpp > CMakeFiles/debuger.dir/debug.cpp.i

debug/CMakeFiles/debuger.dir/debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/debuger.dir/debug.cpp.s"
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/echo/httpd_project/httpd-0.0.2/debug/debug.cpp -o CMakeFiles/debuger.dir/debug.cpp.s

debug/CMakeFiles/debuger.dir/debug.cpp.o.requires:

.PHONY : debug/CMakeFiles/debuger.dir/debug.cpp.o.requires

debug/CMakeFiles/debuger.dir/debug.cpp.o.provides: debug/CMakeFiles/debuger.dir/debug.cpp.o.requires
	$(MAKE) -f debug/CMakeFiles/debuger.dir/build.make debug/CMakeFiles/debuger.dir/debug.cpp.o.provides.build
.PHONY : debug/CMakeFiles/debuger.dir/debug.cpp.o.provides

debug/CMakeFiles/debuger.dir/debug.cpp.o.provides.build: debug/CMakeFiles/debuger.dir/debug.cpp.o


# Object files for target debuger
debuger_OBJECTS = \
"CMakeFiles/debuger.dir/debug.cpp.o"

# External object files for target debuger
debuger_EXTERNAL_OBJECTS =

debug/libdebuger.a: debug/CMakeFiles/debuger.dir/debug.cpp.o
debug/libdebuger.a: debug/CMakeFiles/debuger.dir/build.make
debug/libdebuger.a: debug/CMakeFiles/debuger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/echo/httpd_project/httpd-0.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdebuger.a"
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && $(CMAKE_COMMAND) -P CMakeFiles/debuger.dir/cmake_clean_target.cmake
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/debuger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
debug/CMakeFiles/debuger.dir/build: debug/libdebuger.a

.PHONY : debug/CMakeFiles/debuger.dir/build

debug/CMakeFiles/debuger.dir/requires: debug/CMakeFiles/debuger.dir/debug.cpp.o.requires

.PHONY : debug/CMakeFiles/debuger.dir/requires

debug/CMakeFiles/debuger.dir/clean:
	cd /home/echo/httpd_project/httpd-0.0.2/build/debug && $(CMAKE_COMMAND) -P CMakeFiles/debuger.dir/cmake_clean.cmake
.PHONY : debug/CMakeFiles/debuger.dir/clean

debug/CMakeFiles/debuger.dir/depend:
	cd /home/echo/httpd_project/httpd-0.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/echo/httpd_project/httpd-0.0.2 /home/echo/httpd_project/httpd-0.0.2/debug /home/echo/httpd_project/httpd-0.0.2/build /home/echo/httpd_project/httpd-0.0.2/build/debug /home/echo/httpd_project/httpd-0.0.2/build/debug/CMakeFiles/debuger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : debug/CMakeFiles/debuger.dir/depend

