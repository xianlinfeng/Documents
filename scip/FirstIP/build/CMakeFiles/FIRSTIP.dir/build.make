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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arthur/Documents/scip/FirstIP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Documents/scip/FirstIP/build

# Include any dependencies generated for this target.
include CMakeFiles/FIRSTIP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FIRSTIP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FIRSTIP.dir/flags.make

CMakeFiles/FIRSTIP.dir/src/cmain.c.o: CMakeFiles/FIRSTIP.dir/flags.make
CMakeFiles/FIRSTIP.dir/src/cmain.c.o: ../src/cmain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/FirstIP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FIRSTIP.dir/src/cmain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FIRSTIP.dir/src/cmain.c.o   -c /home/arthur/Documents/scip/FirstIP/src/cmain.c

CMakeFiles/FIRSTIP.dir/src/cmain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FIRSTIP.dir/src/cmain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/FirstIP/src/cmain.c > CMakeFiles/FIRSTIP.dir/src/cmain.c.i

CMakeFiles/FIRSTIP.dir/src/cmain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FIRSTIP.dir/src/cmain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/FirstIP/src/cmain.c -o CMakeFiles/FIRSTIP.dir/src/cmain.c.s

CMakeFiles/FIRSTIP.dir/src/cmain.c.o.requires:

.PHONY : CMakeFiles/FIRSTIP.dir/src/cmain.c.o.requires

CMakeFiles/FIRSTIP.dir/src/cmain.c.o.provides: CMakeFiles/FIRSTIP.dir/src/cmain.c.o.requires
	$(MAKE) -f CMakeFiles/FIRSTIP.dir/build.make CMakeFiles/FIRSTIP.dir/src/cmain.c.o.provides.build
.PHONY : CMakeFiles/FIRSTIP.dir/src/cmain.c.o.provides

CMakeFiles/FIRSTIP.dir/src/cmain.c.o.provides.build: CMakeFiles/FIRSTIP.dir/src/cmain.c.o


# Object files for target FIRSTIP
FIRSTIP_OBJECTS = \
"CMakeFiles/FIRSTIP.dir/src/cmain.c.o"

# External object files for target FIRSTIP
FIRSTIP_EXTERNAL_OBJECTS =

FIRSTIP: CMakeFiles/FIRSTIP.dir/src/cmain.c.o
FIRSTIP: CMakeFiles/FIRSTIP.dir/build.make
FIRSTIP: CMakeFiles/FIRSTIP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arthur/Documents/scip/FirstIP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FIRSTIP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FIRSTIP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FIRSTIP.dir/build: FIRSTIP

.PHONY : CMakeFiles/FIRSTIP.dir/build

CMakeFiles/FIRSTIP.dir/requires: CMakeFiles/FIRSTIP.dir/src/cmain.c.o.requires

.PHONY : CMakeFiles/FIRSTIP.dir/requires

CMakeFiles/FIRSTIP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FIRSTIP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FIRSTIP.dir/clean

CMakeFiles/FIRSTIP.dir/depend:
	cd /home/arthur/Documents/scip/FirstIP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Documents/scip/FirstIP /home/arthur/Documents/scip/FirstIP /home/arthur/Documents/scip/FirstIP/build /home/arthur/Documents/scip/FirstIP/build /home/arthur/Documents/scip/FirstIP/build/CMakeFiles/FIRSTIP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FIRSTIP.dir/depend
