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
CMAKE_SOURCE_DIR = /Users/Nathan/CLionProjects/project-9-WFUNathan18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project9.dir/flags.make

CMakeFiles/Project9.dir/main.cpp.o: CMakeFiles/Project9.dir/flags.make
CMakeFiles/Project9.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project9.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project9.dir/main.cpp.o -c /Users/Nathan/CLionProjects/project-9-WFUNathan18/main.cpp

CMakeFiles/Project9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project9.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Nathan/CLionProjects/project-9-WFUNathan18/main.cpp > CMakeFiles/Project9.dir/main.cpp.i

CMakeFiles/Project9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project9.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Nathan/CLionProjects/project-9-WFUNathan18/main.cpp -o CMakeFiles/Project9.dir/main.cpp.s

CMakeFiles/Project9.dir/Data.cpp.o: CMakeFiles/Project9.dir/flags.make
CMakeFiles/Project9.dir/Data.cpp.o: ../Data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project9.dir/Data.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project9.dir/Data.cpp.o -c /Users/Nathan/CLionProjects/project-9-WFUNathan18/Data.cpp

CMakeFiles/Project9.dir/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project9.dir/Data.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Nathan/CLionProjects/project-9-WFUNathan18/Data.cpp > CMakeFiles/Project9.dir/Data.cpp.i

CMakeFiles/Project9.dir/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project9.dir/Data.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Nathan/CLionProjects/project-9-WFUNathan18/Data.cpp -o CMakeFiles/Project9.dir/Data.cpp.s

# Object files for target Project9
Project9_OBJECTS = \
"CMakeFiles/Project9.dir/main.cpp.o" \
"CMakeFiles/Project9.dir/Data.cpp.o"

# External object files for target Project9
Project9_EXTERNAL_OBJECTS =

Project9: CMakeFiles/Project9.dir/main.cpp.o
Project9: CMakeFiles/Project9.dir/Data.cpp.o
Project9: CMakeFiles/Project9.dir/build.make
Project9: CMakeFiles/Project9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project9.dir/build: Project9

.PHONY : CMakeFiles/Project9.dir/build

CMakeFiles/Project9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project9.dir/clean

CMakeFiles/Project9.dir/depend:
	cd /Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Nathan/CLionProjects/project-9-WFUNathan18 /Users/Nathan/CLionProjects/project-9-WFUNathan18 /Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug /Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug /Users/Nathan/CLionProjects/project-9-WFUNathan18/cmake-build-debug/CMakeFiles/Project9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project9.dir/depend

