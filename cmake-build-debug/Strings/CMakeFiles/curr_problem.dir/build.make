# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gasanoe/Documents/GitHub/interviewbit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug

# Include any dependencies generated for this target.
include Strings/CMakeFiles/curr_problem.dir/depend.make

# Include the progress variables for this target.
include Strings/CMakeFiles/curr_problem.dir/progress.make

# Include the compile flags for this target's objects.
include Strings/CMakeFiles/curr_problem.dir/flags.make

Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.o: Strings/CMakeFiles/curr_problem.dir/flags.make
Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.o: ../Strings/power_of_two.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.o"
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curr_problem.dir/power_of_two.cpp.o -c /Users/gasanoe/Documents/GitHub/interviewbit/Strings/power_of_two.cpp

Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curr_problem.dir/power_of_two.cpp.i"
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gasanoe/Documents/GitHub/interviewbit/Strings/power_of_two.cpp > CMakeFiles/curr_problem.dir/power_of_two.cpp.i

Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curr_problem.dir/power_of_two.cpp.s"
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gasanoe/Documents/GitHub/interviewbit/Strings/power_of_two.cpp -o CMakeFiles/curr_problem.dir/power_of_two.cpp.s

# Object files for target curr_problem
curr_problem_OBJECTS = \
"CMakeFiles/curr_problem.dir/power_of_two.cpp.o"

# External object files for target curr_problem
curr_problem_EXTERNAL_OBJECTS =

Strings/curr_problem: Strings/CMakeFiles/curr_problem.dir/power_of_two.cpp.o
Strings/curr_problem: Strings/CMakeFiles/curr_problem.dir/build.make
Strings/curr_problem: Strings/CMakeFiles/curr_problem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable curr_problem"
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/curr_problem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Strings/CMakeFiles/curr_problem.dir/build: Strings/curr_problem

.PHONY : Strings/CMakeFiles/curr_problem.dir/build

Strings/CMakeFiles/curr_problem.dir/clean:
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings && $(CMAKE_COMMAND) -P CMakeFiles/curr_problem.dir/cmake_clean.cmake
.PHONY : Strings/CMakeFiles/curr_problem.dir/clean

Strings/CMakeFiles/curr_problem.dir/depend:
	cd /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gasanoe/Documents/GitHub/interviewbit /Users/gasanoe/Documents/GitHub/interviewbit/Strings /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings /Users/gasanoe/Documents/GitHub/interviewbit/cmake-build-debug/Strings/CMakeFiles/curr_problem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Strings/CMakeFiles/curr_problem.dir/depend

