# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tonio/Documents/opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tonio/Documents/opengl/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/testHelloWorld.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/testHelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/testHelloWorld.dir/flags.make

tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o: tests/CMakeFiles/testHelloWorld.dir/flags.make
tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o: ../tests/testHelloWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tonio/Documents/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o"
	cd /home/tonio/Documents/opengl/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o -c /home/tonio/Documents/opengl/tests/testHelloWorld.cpp

tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.i"
	cd /home/tonio/Documents/opengl/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tonio/Documents/opengl/tests/testHelloWorld.cpp > CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.i

tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.s"
	cd /home/tonio/Documents/opengl/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tonio/Documents/opengl/tests/testHelloWorld.cpp -o CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.s

# Object files for target testHelloWorld
testHelloWorld_OBJECTS = \
"CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o"

# External object files for target testHelloWorld
testHelloWorld_EXTERNAL_OBJECTS =

bin/testHelloWorld: tests/CMakeFiles/testHelloWorld.dir/testHelloWorld.cpp.o
bin/testHelloWorld: tests/CMakeFiles/testHelloWorld.dir/build.make
bin/testHelloWorld: tests/CMakeFiles/testHelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tonio/Documents/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/testHelloWorld"
	cd /home/tonio/Documents/opengl/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testHelloWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/testHelloWorld.dir/build: bin/testHelloWorld

.PHONY : tests/CMakeFiles/testHelloWorld.dir/build

tests/CMakeFiles/testHelloWorld.dir/clean:
	cd /home/tonio/Documents/opengl/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/testHelloWorld.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/testHelloWorld.dir/clean

tests/CMakeFiles/testHelloWorld.dir/depend:
	cd /home/tonio/Documents/opengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tonio/Documents/opengl /home/tonio/Documents/opengl/tests /home/tonio/Documents/opengl/build /home/tonio/Documents/opengl/build/tests /home/tonio/Documents/opengl/build/tests/CMakeFiles/testHelloWorld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/testHelloWorld.dir/depend
