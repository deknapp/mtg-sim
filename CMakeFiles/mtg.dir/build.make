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
CMAKE_COMMAND = /Library/Python/2.7/site-packages/cmake/data/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Library/Python/2.7/site-packages/cmake/data/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nknapp/code/mtg-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nknapp/code/mtg-sim

# Include any dependencies generated for this target.
include CMakeFiles/mtg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mtg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mtg.dir/flags.make

CMakeFiles/mtg.dir/main.cpp.o: CMakeFiles/mtg.dir/flags.make
CMakeFiles/mtg.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nknapp/code/mtg-sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mtg.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mtg.dir/main.cpp.o -c /Users/nknapp/code/mtg-sim/main.cpp

CMakeFiles/mtg.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtg.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nknapp/code/mtg-sim/main.cpp > CMakeFiles/mtg.dir/main.cpp.i

CMakeFiles/mtg.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtg.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nknapp/code/mtg-sim/main.cpp -o CMakeFiles/mtg.dir/main.cpp.s

# Object files for target mtg
mtg_OBJECTS = \
"CMakeFiles/mtg.dir/main.cpp.o"

# External object files for target mtg
mtg_EXTERNAL_OBJECTS =

mtg: CMakeFiles/mtg.dir/main.cpp.o
mtg: CMakeFiles/mtg.dir/build.make
mtg: CMakeFiles/mtg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nknapp/code/mtg-sim/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mtg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mtg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mtg.dir/build: mtg

.PHONY : CMakeFiles/mtg.dir/build

CMakeFiles/mtg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mtg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mtg.dir/clean

CMakeFiles/mtg.dir/depend:
	cd /Users/nknapp/code/mtg-sim && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nknapp/code/mtg-sim /Users/nknapp/code/mtg-sim /Users/nknapp/code/mtg-sim /Users/nknapp/code/mtg-sim /Users/nknapp/code/mtg-sim/CMakeFiles/mtg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mtg.dir/depend

