# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project2.dir/flags.make

CMakeFiles/Project2.dir/src/main.cpp.obj: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/src/main.cpp.obj: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project2.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project2.dir\src\main.cpp.obj -c "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\main.cpp"

CMakeFiles/Project2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\main.cpp" > CMakeFiles\Project2.dir\src\main.cpp.i

CMakeFiles/Project2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\main.cpp" -o CMakeFiles\Project2.dir\src\main.cpp.s

CMakeFiles/Project2.dir/src/Image.cpp.obj: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/src/Image.cpp.obj: src/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project2.dir/src/Image.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project2.dir\src\Image.cpp.obj -c "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\Image.cpp"

CMakeFiles/Project2.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/src/Image.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\Image.cpp" > CMakeFiles\Project2.dir\src\Image.cpp.i

CMakeFiles/Project2.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/src/Image.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\src\Image.cpp" -o CMakeFiles\Project2.dir\src\Image.cpp.s

# Object files for target Project2
Project2_OBJECTS = \
"CMakeFiles/Project2.dir/src/main.cpp.obj" \
"CMakeFiles/Project2.dir/src/Image.cpp.obj"

# External object files for target Project2
Project2_EXTERNAL_OBJECTS =

Project2.exe: CMakeFiles/Project2.dir/src/main.cpp.obj
Project2.exe: CMakeFiles/Project2.dir/src/Image.cpp.obj
Project2.exe: CMakeFiles/Project2.dir/build.make
Project2.exe: CMakeFiles/Project2.dir/linklibs.rsp
Project2.exe: CMakeFiles/Project2.dir/objects1.rsp
Project2.exe: CMakeFiles/Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project2.dir/build: Project2.exe

.PHONY : CMakeFiles/Project2.dir/build

CMakeFiles/Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project2.dir/clean

CMakeFiles/Project2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2" "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2" "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug" "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug" "D:\Zach\Documents\Computer-Science-Labs-and-Projects\Project 2\cmake-build-debug\CMakeFiles\Project2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project2.dir/depend
