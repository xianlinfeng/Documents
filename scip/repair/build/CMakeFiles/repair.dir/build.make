# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/arthur/Documents/scip/repair

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Documents/scip/repair/build

# Include any dependencies generated for this target.
include CMakeFiles/repair.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/repair.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/repair.dir/flags.make

CMakeFiles/repair.dir/src/cmain.c.o: CMakeFiles/repair.dir/flags.make
CMakeFiles/repair.dir/src/cmain.c.o: ../src/cmain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/repair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/repair.dir/src/cmain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/repair.dir/src/cmain.c.o   -c /home/arthur/Documents/scip/repair/src/cmain.c

CMakeFiles/repair.dir/src/cmain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/repair.dir/src/cmain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/repair/src/cmain.c > CMakeFiles/repair.dir/src/cmain.c.i

CMakeFiles/repair.dir/src/cmain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/repair.dir/src/cmain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/repair/src/cmain.c -o CMakeFiles/repair.dir/src/cmain.c.s

# Object files for target repair
repair_OBJECTS = \
"CMakeFiles/repair.dir/src/cmain.c.o"

# External object files for target repair
repair_EXTERNAL_OBJECTS =

repair: CMakeFiles/repair.dir/src/cmain.c.o
repair: CMakeFiles/repair.dir/build.make
repair: /home/arthur/opt/scipoptsuite-6.0.1/scip/build/lib/libscip.so.6.0.1.0
repair: CMakeFiles/repair.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arthur/Documents/scip/repair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable repair"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/repair.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/repair.dir/build: repair

.PHONY : CMakeFiles/repair.dir/build

CMakeFiles/repair.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/repair.dir/cmake_clean.cmake
.PHONY : CMakeFiles/repair.dir/clean

CMakeFiles/repair.dir/depend:
	cd /home/arthur/Documents/scip/repair/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Documents/scip/repair /home/arthur/Documents/scip/repair /home/arthur/Documents/scip/repair/build /home/arthur/Documents/scip/repair/build /home/arthur/Documents/scip/repair/build/CMakeFiles/repair.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/repair.dir/depend

