# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Piscine\Piscine_CPP\day01\ex07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex07.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex07.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex07.dir/flags.make

CMakeFiles/ex07.dir/main.cpp.obj: CMakeFiles/ex07.dir/flags.make
CMakeFiles/ex07.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex07.dir/main.cpp.obj"
	E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex07.dir\main.cpp.obj -c E:\Piscine\Piscine_CPP\day01\ex07\main.cpp

CMakeFiles/ex07.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex07.dir/main.cpp.i"
	E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Piscine\Piscine_CPP\day01\ex07\main.cpp > CMakeFiles\ex07.dir\main.cpp.i

CMakeFiles/ex07.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex07.dir/main.cpp.s"
	E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Piscine\Piscine_CPP\day01\ex07\main.cpp -o CMakeFiles\ex07.dir\main.cpp.s

CMakeFiles/ex07.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/ex07.dir/main.cpp.obj.requires

CMakeFiles/ex07.dir/main.cpp.obj.provides: CMakeFiles/ex07.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ex07.dir\build.make CMakeFiles/ex07.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/ex07.dir/main.cpp.obj.provides

CMakeFiles/ex07.dir/main.cpp.obj.provides.build: CMakeFiles/ex07.dir/main.cpp.obj


# Object files for target ex07
ex07_OBJECTS = \
"CMakeFiles/ex07.dir/main.cpp.obj"

# External object files for target ex07
ex07_EXTERNAL_OBJECTS =

ex07.exe: CMakeFiles/ex07.dir/main.cpp.obj
ex07.exe: CMakeFiles/ex07.dir/build.make
ex07.exe: CMakeFiles/ex07.dir/linklibs.rsp
ex07.exe: CMakeFiles/ex07.dir/objects1.rsp
ex07.exe: CMakeFiles/ex07.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex07.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex07.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex07.dir/build: ex07.exe

.PHONY : CMakeFiles/ex07.dir/build

CMakeFiles/ex07.dir/requires: CMakeFiles/ex07.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/ex07.dir/requires

CMakeFiles/ex07.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex07.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex07.dir/clean

CMakeFiles/ex07.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Piscine\Piscine_CPP\day01\ex07 E:\Piscine\Piscine_CPP\day01\ex07 E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug E:\Piscine\Piscine_CPP\day01\ex07\cmake-build-debug\CMakeFiles\ex07.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex07.dir/depend

