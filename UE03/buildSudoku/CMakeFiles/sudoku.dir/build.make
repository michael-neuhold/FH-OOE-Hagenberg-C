# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku

# Include any dependencies generated for this target.
include CMakeFiles/sudoku.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku.dir/flags.make

CMakeFiles/sudoku.dir/sudoku/sudoku.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/sudoku/sudoku.c.o: ../sudoku/sudoku.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sudoku.dir/sudoku/sudoku.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/sudoku/sudoku.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudoku.c

CMakeFiles/sudoku.dir/sudoku/sudoku.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/sudoku/sudoku.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudoku.c > CMakeFiles/sudoku.dir/sudoku/sudoku.c.i

CMakeFiles/sudoku.dir/sudoku/sudoku.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/sudoku/sudoku.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudoku.c -o CMakeFiles/sudoku.dir/sudoku/sudoku.c.s

CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o: ../sudoku/sudokulib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudokulib.c

CMakeFiles/sudoku.dir/sudoku/sudokulib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/sudoku/sudokulib.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudokulib.c > CMakeFiles/sudoku.dir/sudoku/sudokulib.c.i

CMakeFiles/sudoku.dir/sudoku/sudokulib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/sudoku/sudokulib.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/sudoku/sudokulib.c -o CMakeFiles/sudoku.dir/sudoku/sudokulib.c.s

# Object files for target sudoku
sudoku_OBJECTS = \
"CMakeFiles/sudoku.dir/sudoku/sudoku.c.o" \
"CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o"

# External object files for target sudoku
sudoku_EXTERNAL_OBJECTS =

bin/sudoku: CMakeFiles/sudoku.dir/sudoku/sudoku.c.o
bin/sudoku: CMakeFiles/sudoku.dir/sudoku/sudokulib.c.o
bin/sudoku: CMakeFiles/sudoku.dir/build.make
bin/sudoku: CMakeFiles/sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bin/sudoku"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sudoku.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku.dir/build: bin/sudoku

.PHONY : CMakeFiles/sudoku.dir/build

CMakeFiles/sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sudoku.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sudoku.dir/clean

CMakeFiles/sudoku.dir/depend:
	cd /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03 /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03 /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE03/buildSudoku/CMakeFiles/sudoku.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sudoku.dir/depend

