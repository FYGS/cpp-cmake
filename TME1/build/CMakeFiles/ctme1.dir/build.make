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
CMAKE_SOURCE_DIR = /home/fernand/Bureau/Cpp/TME1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fernand/Bureau/Cpp/TME1/build

# Include any dependencies generated for this target.
include CMakeFiles/ctme1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ctme1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ctme1.dir/flags.make

CMakeFiles/ctme1.dir/cMain.c.o: CMakeFiles/ctme1.dir/flags.make
CMakeFiles/ctme1.dir/cMain.c.o: /home/fernand/Bureau/Cpp/TME1/src/cMain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fernand/Bureau/Cpp/TME1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ctme1.dir/cMain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctme1.dir/cMain.c.o   -c /home/fernand/Bureau/Cpp/TME1/src/cMain.c

CMakeFiles/ctme1.dir/cMain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctme1.dir/cMain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fernand/Bureau/Cpp/TME1/src/cMain.c > CMakeFiles/ctme1.dir/cMain.c.i

CMakeFiles/ctme1.dir/cMain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctme1.dir/cMain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fernand/Bureau/Cpp/TME1/src/cMain.c -o CMakeFiles/ctme1.dir/cMain.c.s

CMakeFiles/ctme1.dir/cMain.c.o.requires:

.PHONY : CMakeFiles/ctme1.dir/cMain.c.o.requires

CMakeFiles/ctme1.dir/cMain.c.o.provides: CMakeFiles/ctme1.dir/cMain.c.o.requires
	$(MAKE) -f CMakeFiles/ctme1.dir/build.make CMakeFiles/ctme1.dir/cMain.c.o.provides.build
.PHONY : CMakeFiles/ctme1.dir/cMain.c.o.provides

CMakeFiles/ctme1.dir/cMain.c.o.provides.build: CMakeFiles/ctme1.dir/cMain.c.o


CMakeFiles/ctme1.dir/cBox.c.o: CMakeFiles/ctme1.dir/flags.make
CMakeFiles/ctme1.dir/cBox.c.o: /home/fernand/Bureau/Cpp/TME1/src/cBox.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fernand/Bureau/Cpp/TME1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ctme1.dir/cBox.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctme1.dir/cBox.c.o   -c /home/fernand/Bureau/Cpp/TME1/src/cBox.c

CMakeFiles/ctme1.dir/cBox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctme1.dir/cBox.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fernand/Bureau/Cpp/TME1/src/cBox.c > CMakeFiles/ctme1.dir/cBox.c.i

CMakeFiles/ctme1.dir/cBox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctme1.dir/cBox.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fernand/Bureau/Cpp/TME1/src/cBox.c -o CMakeFiles/ctme1.dir/cBox.c.s

CMakeFiles/ctme1.dir/cBox.c.o.requires:

.PHONY : CMakeFiles/ctme1.dir/cBox.c.o.requires

CMakeFiles/ctme1.dir/cBox.c.o.provides: CMakeFiles/ctme1.dir/cBox.c.o.requires
	$(MAKE) -f CMakeFiles/ctme1.dir/build.make CMakeFiles/ctme1.dir/cBox.c.o.provides.build
.PHONY : CMakeFiles/ctme1.dir/cBox.c.o.provides

CMakeFiles/ctme1.dir/cBox.c.o.provides.build: CMakeFiles/ctme1.dir/cBox.c.o


# Object files for target ctme1
ctme1_OBJECTS = \
"CMakeFiles/ctme1.dir/cMain.c.o" \
"CMakeFiles/ctme1.dir/cBox.c.o"

# External object files for target ctme1
ctme1_EXTERNAL_OBJECTS =

ctme1: CMakeFiles/ctme1.dir/cMain.c.o
ctme1: CMakeFiles/ctme1.dir/cBox.c.o
ctme1: CMakeFiles/ctme1.dir/build.make
ctme1: CMakeFiles/ctme1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fernand/Bureau/Cpp/TME1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ctme1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ctme1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ctme1.dir/build: ctme1

.PHONY : CMakeFiles/ctme1.dir/build

CMakeFiles/ctme1.dir/requires: CMakeFiles/ctme1.dir/cMain.c.o.requires
CMakeFiles/ctme1.dir/requires: CMakeFiles/ctme1.dir/cBox.c.o.requires

.PHONY : CMakeFiles/ctme1.dir/requires

CMakeFiles/ctme1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ctme1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ctme1.dir/clean

CMakeFiles/ctme1.dir/depend:
	cd /home/fernand/Bureau/Cpp/TME1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fernand/Bureau/Cpp/TME1/src /home/fernand/Bureau/Cpp/TME1/src /home/fernand/Bureau/Cpp/TME1/build /home/fernand/Bureau/Cpp/TME1/build /home/fernand/Bureau/Cpp/TME1/build/CMakeFiles/ctme1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ctme1.dir/depend
