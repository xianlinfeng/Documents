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
CMAKE_SOURCE_DIR = /home/arthur/Documents/scip/applications/CycleClustering

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Documents/scip/applications/CycleClustering/build

# Include any dependencies generated for this target.
include CMakeFiles/cycleclustering.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cycleclustering.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cycleclustering.dir/flags.make

CMakeFiles/cycleclustering.dir/src/main.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cycleclustering.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/main.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/main.c

CMakeFiles/cycleclustering.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/main.c > CMakeFiles/cycleclustering.dir/src/main.c.i

CMakeFiles/cycleclustering.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/main.c -o CMakeFiles/cycleclustering.dir/src/main.c.s

CMakeFiles/cycleclustering.dir/src/cycplugins.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/cycplugins.c.o: ../src/cycplugins.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cycleclustering.dir/src/cycplugins.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/cycplugins.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/cycplugins.c

CMakeFiles/cycleclustering.dir/src/cycplugins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/cycplugins.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/cycplugins.c > CMakeFiles/cycleclustering.dir/src/cycplugins.c.i

CMakeFiles/cycleclustering.dir/src/cycplugins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/cycplugins.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/cycplugins.c -o CMakeFiles/cycleclustering.dir/src/cycplugins.c.s

CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o: ../src/sepa_partition.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_partition.c

CMakeFiles/cycleclustering.dir/src/sepa_partition.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/sepa_partition.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_partition.c > CMakeFiles/cycleclustering.dir/src/sepa_partition.c.i

CMakeFiles/cycleclustering.dir/src/sepa_partition.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/sepa_partition.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_partition.c -o CMakeFiles/cycleclustering.dir/src/sepa_partition.c.s

CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o: ../src/sepa_edge.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_edge.c

CMakeFiles/cycleclustering.dir/src/sepa_edge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/sepa_edge.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_edge.c > CMakeFiles/cycleclustering.dir/src/sepa_edge.c.i

CMakeFiles/cycleclustering.dir/src/sepa_edge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/sepa_edge.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_edge.c -o CMakeFiles/cycleclustering.dir/src/sepa_edge.c.s

CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o: ../src/sepa_subtour.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_subtour.c

CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_subtour.c > CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.i

CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/sepa_subtour.c -o CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.s

CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o: ../src/heur_cycgreedy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cycgreedy.c

CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cycgreedy.c > CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.i

CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cycgreedy.c -o CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.s

CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o: ../src/heur_fuzzyround.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/heur_fuzzyround.c

CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/heur_fuzzyround.c > CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.i

CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/heur_fuzzyround.c -o CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.s

CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o: ../src/heur_cyckerlin.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cyckerlin.c

CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cyckerlin.c > CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.i

CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/heur_cyckerlin.c -o CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.s

CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o: ../src/heur_redsize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/heur_redsize.c

CMakeFiles/cycleclustering.dir/src/heur_redsize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/heur_redsize.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/heur_redsize.c > CMakeFiles/cycleclustering.dir/src/heur_redsize.c.i

CMakeFiles/cycleclustering.dir/src/heur_redsize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/heur_redsize.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/heur_redsize.c -o CMakeFiles/cycleclustering.dir/src/heur_redsize.c.s

CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o: ../src/branch_multinode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/branch_multinode.c

CMakeFiles/cycleclustering.dir/src/branch_multinode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/branch_multinode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/branch_multinode.c > CMakeFiles/cycleclustering.dir/src/branch_multinode.c.i

CMakeFiles/cycleclustering.dir/src/branch_multinode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/branch_multinode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/branch_multinode.c -o CMakeFiles/cycleclustering.dir/src/branch_multinode.c.s

CMakeFiles/cycleclustering.dir/src/event_newsol.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/event_newsol.c.o: ../src/event_newsol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/cycleclustering.dir/src/event_newsol.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/event_newsol.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/event_newsol.c

CMakeFiles/cycleclustering.dir/src/event_newsol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/event_newsol.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/event_newsol.c > CMakeFiles/cycleclustering.dir/src/event_newsol.c.i

CMakeFiles/cycleclustering.dir/src/event_newsol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/event_newsol.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/event_newsol.c -o CMakeFiles/cycleclustering.dir/src/event_newsol.c.s

CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o: ../src/reader_cyc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/reader_cyc.c

CMakeFiles/cycleclustering.dir/src/reader_cyc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/reader_cyc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/reader_cyc.c > CMakeFiles/cycleclustering.dir/src/reader_cyc.c.i

CMakeFiles/cycleclustering.dir/src/reader_cyc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/reader_cyc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/reader_cyc.c -o CMakeFiles/cycleclustering.dir/src/reader_cyc.c.s

CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o: CMakeFiles/cycleclustering.dir/flags.make
CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o: ../src/probdata_cyc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o   -c /home/arthur/Documents/scip/applications/CycleClustering/src/probdata_cyc.c

CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Documents/scip/applications/CycleClustering/src/probdata_cyc.c > CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.i

CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Documents/scip/applications/CycleClustering/src/probdata_cyc.c -o CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.s

# Object files for target cycleclustering
cycleclustering_OBJECTS = \
"CMakeFiles/cycleclustering.dir/src/main.c.o" \
"CMakeFiles/cycleclustering.dir/src/cycplugins.c.o" \
"CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o" \
"CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o" \
"CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o" \
"CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o" \
"CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o" \
"CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o" \
"CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o" \
"CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o" \
"CMakeFiles/cycleclustering.dir/src/event_newsol.c.o" \
"CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o" \
"CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o"

# External object files for target cycleclustering
cycleclustering_EXTERNAL_OBJECTS =

cycleclustering: CMakeFiles/cycleclustering.dir/src/main.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/cycplugins.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/sepa_partition.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/sepa_edge.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/sepa_subtour.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/heur_cycgreedy.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/heur_fuzzyround.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/heur_cyckerlin.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/heur_redsize.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/branch_multinode.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/event_newsol.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/reader_cyc.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/src/probdata_cyc.c.o
cycleclustering: CMakeFiles/cycleclustering.dir/build.make
cycleclustering: /home/arthur/opt/scipoptsuite-6.0.1/scip/build/lib/libscip.so.6.0.1.0
cycleclustering: /usr/lib/libm.so
cycleclustering: CMakeFiles/cycleclustering.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable cycleclustering"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cycleclustering.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cycleclustering.dir/build: cycleclustering

.PHONY : CMakeFiles/cycleclustering.dir/build

CMakeFiles/cycleclustering.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cycleclustering.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cycleclustering.dir/clean

CMakeFiles/cycleclustering.dir/depend:
	cd /home/arthur/Documents/scip/applications/CycleClustering/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Documents/scip/applications/CycleClustering /home/arthur/Documents/scip/applications/CycleClustering /home/arthur/Documents/scip/applications/CycleClustering/build /home/arthur/Documents/scip/applications/CycleClustering/build /home/arthur/Documents/scip/applications/CycleClustering/build/CMakeFiles/cycleclustering.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cycleclustering.dir/depend

