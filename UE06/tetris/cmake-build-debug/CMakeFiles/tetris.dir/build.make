# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tetris.dir/flags.make

CMakeFiles/tetris.dir/tetris/gameboard.c.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/tetris/gameboard.c.o: ../tetris/gameboard.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tetris.dir/tetris/gameboard.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tetris.dir/tetris/gameboard.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/gameboard.c

CMakeFiles/tetris.dir/tetris/gameboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tetris.dir/tetris/gameboard.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/gameboard.c > CMakeFiles/tetris.dir/tetris/gameboard.c.i

CMakeFiles/tetris.dir/tetris/gameboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tetris.dir/tetris/gameboard.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/gameboard.c -o CMakeFiles/tetris.dir/tetris/gameboard.c.s

CMakeFiles/tetris.dir/tetris/main.c.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/tetris/main.c.o: ../tetris/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tetris.dir/tetris/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tetris.dir/tetris/main.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/main.c

CMakeFiles/tetris.dir/tetris/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tetris.dir/tetris/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/main.c > CMakeFiles/tetris.dir/tetris/main.c.i

CMakeFiles/tetris.dir/tetris/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tetris.dir/tetris/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/main.c -o CMakeFiles/tetris.dir/tetris/main.c.s

CMakeFiles/tetris.dir/tetris/timer.c.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/tetris/timer.c.o: ../tetris/timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tetris.dir/tetris/timer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tetris.dir/tetris/timer.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/timer.c

CMakeFiles/tetris.dir/tetris/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tetris.dir/tetris/timer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/timer.c > CMakeFiles/tetris.dir/tetris/timer.c.i

CMakeFiles/tetris.dir/tetris/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tetris.dir/tetris/timer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/timer.c -o CMakeFiles/tetris.dir/tetris/timer.c.s

CMakeFiles/tetris.dir/tetris/types.c.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/tetris/types.c.o: ../tetris/types.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/tetris.dir/tetris/types.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tetris.dir/tetris/types.c.o   -c /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/types.c

CMakeFiles/tetris.dir/tetris/types.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tetris.dir/tetris/types.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/types.c > CMakeFiles/tetris.dir/tetris/types.c.i

CMakeFiles/tetris.dir/tetris/types.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tetris.dir/tetris/types.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/tetris/types.c -o CMakeFiles/tetris.dir/tetris/types.c.s

# Object files for target tetris
tetris_OBJECTS = \
"CMakeFiles/tetris.dir/tetris/gameboard.c.o" \
"CMakeFiles/tetris.dir/tetris/main.c.o" \
"CMakeFiles/tetris.dir/tetris/timer.c.o" \
"CMakeFiles/tetris.dir/tetris/types.c.o"

# External object files for target tetris
tetris_EXTERNAL_OBJECTS =

bin/tetris: CMakeFiles/tetris.dir/tetris/gameboard.c.o
bin/tetris: CMakeFiles/tetris.dir/tetris/main.c.o
bin/tetris: CMakeFiles/tetris.dir/tetris/timer.c.o
bin/tetris: CMakeFiles/tetris.dir/tetris/types.c.o
bin/tetris: CMakeFiles/tetris.dir/build.make
bin/tetris: /usr/local/lib/libglfw.3.3.dylib
bin/tetris: /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
bin/tetris: /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
bin/tetris: /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
bin/tetris: CMakeFiles/tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable bin/tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tetris.dir/build: bin/tetris

.PHONY : CMakeFiles/tetris.dir/build

CMakeFiles/tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tetris.dir/clean

CMakeFiles/tetris.dir/depend:
	cd /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug /Users/michaelneuhold/Documents/FH/Semester/03_Semester/02_SWO_UE/Uebungen/UE06/tetris/cmake-build-debug/CMakeFiles/tetris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tetris.dir/depend
