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
CMAKE_SOURCE_DIR = /home/wannabuh/Workspaces/C_Workspaces/cs488/final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/src/Camera.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/Camera.cpp.o: ../../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/src/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/Camera.cpp.o -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Camera.cpp

CMakeFiles/test.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Camera.cpp > CMakeFiles/test.dir/src/Camera.cpp.i

CMakeFiles/test.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Camera.cpp -o CMakeFiles/test.dir/src/Camera.cpp.s

CMakeFiles/test.dir/src/Mesh.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/Mesh.cpp.o: ../../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/Mesh.cpp.o -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Mesh.cpp

CMakeFiles/test.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Mesh.cpp > CMakeFiles/test.dir/src/Mesh.cpp.i

CMakeFiles/test.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Mesh.cpp -o CMakeFiles/test.dir/src/Mesh.cpp.s

CMakeFiles/test.dir/src/Model.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/Model.cpp.o: ../../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/Model.cpp.o -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Model.cpp

CMakeFiles/test.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Model.cpp > CMakeFiles/test.dir/src/Model.cpp.i

CMakeFiles/test.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/Model.cpp -o CMakeFiles/test.dir/src/Model.cpp.s

CMakeFiles/test.dir/src/glad.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/glad.c.o: ../../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test.dir/src/glad.c.o   -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/glad.c

CMakeFiles/test.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/glad.c > CMakeFiles/test.dir/src/glad.c.i

CMakeFiles/test.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/glad.c -o CMakeFiles/test.dir/src/glad.c.s

CMakeFiles/test.dir/src/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/main.cpp.o: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/main.cpp.o -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/main.cpp

CMakeFiles/test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/main.cpp > CMakeFiles/test.dir/src/main.cpp.i

CMakeFiles/test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/main.cpp -o CMakeFiles/test.dir/src/main.cpp.s

CMakeFiles/test.dir/src/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/test.cpp.o: ../../src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test.dir/src/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/test.cpp.o -c /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/test.cpp

CMakeFiles/test.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/test.cpp > CMakeFiles/test.dir/src/test.cpp.i

CMakeFiles/test.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wannabuh/Workspaces/C_Workspaces/cs488/final/src/test.cpp -o CMakeFiles/test.dir/src/test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/src/Camera.cpp.o" \
"CMakeFiles/test.dir/src/Mesh.cpp.o" \
"CMakeFiles/test.dir/src/Model.cpp.o" \
"CMakeFiles/test.dir/src/glad.c.o" \
"CMakeFiles/test.dir/src/main.cpp.o" \
"CMakeFiles/test.dir/src/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/src/Camera.cpp.o
test: CMakeFiles/test.dir/src/Mesh.cpp.o
test: CMakeFiles/test.dir/src/Model.cpp.o
test: CMakeFiles/test.dir/src/glad.c.o
test: CMakeFiles/test.dir/src/main.cpp.o
test: CMakeFiles/test.dir/src/test.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wannabuh/Workspaces/C_Workspaces/cs488/final /home/wannabuh/Workspaces/C_Workspaces/cs488/final /home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest /home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest /home/wannabuh/Workspaces/C_Workspaces/cs488/final/build/windowTest/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

