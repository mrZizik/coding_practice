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
CMAKE_COMMAND = /home/mrzizik/utils/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mrzizik/utils/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrzizik/projects/coding_practice/C/dynamic_array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dynamic_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dynamic_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dynamic_array.dir/flags.make

CMakeFiles/dynamic_array.dir/main.c.o: CMakeFiles/dynamic_array.dir/flags.make
CMakeFiles/dynamic_array.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dynamic_array.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dynamic_array.dir/main.c.o   -c /home/mrzizik/projects/coding_practice/C/dynamic_array/main.c

CMakeFiles/dynamic_array.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dynamic_array.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mrzizik/projects/coding_practice/C/dynamic_array/main.c > CMakeFiles/dynamic_array.dir/main.c.i

CMakeFiles/dynamic_array.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dynamic_array.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mrzizik/projects/coding_practice/C/dynamic_array/main.c -o CMakeFiles/dynamic_array.dir/main.c.s

# Object files for target dynamic_array
dynamic_array_OBJECTS = \
"CMakeFiles/dynamic_array.dir/main.c.o"

# External object files for target dynamic_array
dynamic_array_EXTERNAL_OBJECTS =

dynamic_array: CMakeFiles/dynamic_array.dir/main.c.o
dynamic_array: CMakeFiles/dynamic_array.dir/build.make
dynamic_array: CMakeFiles/dynamic_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dynamic_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamic_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dynamic_array.dir/build: dynamic_array

.PHONY : CMakeFiles/dynamic_array.dir/build

CMakeFiles/dynamic_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dynamic_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dynamic_array.dir/clean

CMakeFiles/dynamic_array.dir/depend:
	cd /home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrzizik/projects/coding_practice/C/dynamic_array /home/mrzizik/projects/coding_practice/C/dynamic_array /home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug /home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug /home/mrzizik/projects/coding_practice/C/dynamic_array/cmake-build-debug/CMakeFiles/dynamic_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dynamic_array.dir/depend

