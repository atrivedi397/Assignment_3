# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/atrivedi/Downloads/clion-2017.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/atrivedi/Downloads/clion-2017.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/atrivedi/Assignment_3/Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/atrivedi/Assignment_3/Tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tree.dir/flags.make

CMakeFiles/Tree.dir/main.cpp.o: CMakeFiles/Tree.dir/flags.make
CMakeFiles/Tree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atrivedi/Assignment_3/Tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tree.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tree.dir/main.cpp.o -c /home/atrivedi/Assignment_3/Tree/main.cpp

CMakeFiles/Tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atrivedi/Assignment_3/Tree/main.cpp > CMakeFiles/Tree.dir/main.cpp.i

CMakeFiles/Tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atrivedi/Assignment_3/Tree/main.cpp -o CMakeFiles/Tree.dir/main.cpp.s

CMakeFiles/Tree.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Tree.dir/main.cpp.o.requires

CMakeFiles/Tree.dir/main.cpp.o.provides: CMakeFiles/Tree.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tree.dir/build.make CMakeFiles/Tree.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Tree.dir/main.cpp.o.provides

CMakeFiles/Tree.dir/main.cpp.o.provides.build: CMakeFiles/Tree.dir/main.cpp.o


# Object files for target Tree
Tree_OBJECTS = \
"CMakeFiles/Tree.dir/main.cpp.o"

# External object files for target Tree
Tree_EXTERNAL_OBJECTS =

Tree: CMakeFiles/Tree.dir/main.cpp.o
Tree: CMakeFiles/Tree.dir/build.make
Tree: CMakeFiles/Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/atrivedi/Assignment_3/Tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tree.dir/build: Tree

.PHONY : CMakeFiles/Tree.dir/build

CMakeFiles/Tree.dir/requires: CMakeFiles/Tree.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Tree.dir/requires

CMakeFiles/Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tree.dir/clean

CMakeFiles/Tree.dir/depend:
	cd /home/atrivedi/Assignment_3/Tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/atrivedi/Assignment_3/Tree /home/atrivedi/Assignment_3/Tree /home/atrivedi/Assignment_3/Tree/cmake-build-debug /home/atrivedi/Assignment_3/Tree/cmake-build-debug /home/atrivedi/Assignment_3/Tree/cmake-build-debug/CMakeFiles/Tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tree.dir/depend

