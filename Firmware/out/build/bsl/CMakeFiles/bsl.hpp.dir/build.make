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
CMAKE_SOURCE_DIR = /home/ed/github/Reflow/Firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ed/github/Reflow/Firmware/out/build

# Include any dependencies generated for this target.
include bsl/CMakeFiles/bsl.hpp.dir/depend.make

# Include the progress variables for this target.
include bsl/CMakeFiles/bsl.hpp.dir/progress.make

# Include the compile flags for this target's objects.
include bsl/CMakeFiles/bsl.hpp.dir/flags.make

bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.o: bsl/CMakeFiles/bsl.hpp.dir/flags.make
bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.o: ../../bsl/bsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ed/github/Reflow/Firmware/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.o"
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bsl.hpp.dir/bsl.cpp.o -c /home/ed/github/Reflow/Firmware/bsl/bsl.cpp

bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bsl.hpp.dir/bsl.cpp.i"
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ed/github/Reflow/Firmware/bsl/bsl.cpp > CMakeFiles/bsl.hpp.dir/bsl.cpp.i

bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bsl.hpp.dir/bsl.cpp.s"
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ed/github/Reflow/Firmware/bsl/bsl.cpp -o CMakeFiles/bsl.hpp.dir/bsl.cpp.s

# Object files for target bsl.hpp
bsl_hpp_OBJECTS = \
"CMakeFiles/bsl.hpp.dir/bsl.cpp.o"

# External object files for target bsl.hpp
bsl_hpp_EXTERNAL_OBJECTS =

bsl/libbsl.hpp.a: bsl/CMakeFiles/bsl.hpp.dir/bsl.cpp.o
bsl/libbsl.hpp.a: bsl/CMakeFiles/bsl.hpp.dir/build.make
bsl/libbsl.hpp.a: bsl/CMakeFiles/bsl.hpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ed/github/Reflow/Firmware/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbsl.hpp.a"
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && $(CMAKE_COMMAND) -P CMakeFiles/bsl.hpp.dir/cmake_clean_target.cmake
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bsl.hpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bsl/CMakeFiles/bsl.hpp.dir/build: bsl/libbsl.hpp.a

.PHONY : bsl/CMakeFiles/bsl.hpp.dir/build

bsl/CMakeFiles/bsl.hpp.dir/clean:
	cd /home/ed/github/Reflow/Firmware/out/build/bsl && $(CMAKE_COMMAND) -P CMakeFiles/bsl.hpp.dir/cmake_clean.cmake
.PHONY : bsl/CMakeFiles/bsl.hpp.dir/clean

bsl/CMakeFiles/bsl.hpp.dir/depend:
	cd /home/ed/github/Reflow/Firmware/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ed/github/Reflow/Firmware /home/ed/github/Reflow/Firmware/bsl /home/ed/github/Reflow/Firmware/out/build /home/ed/github/Reflow/Firmware/out/build/bsl /home/ed/github/Reflow/Firmware/out/build/bsl/CMakeFiles/bsl.hpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bsl/CMakeFiles/bsl.hpp.dir/depend

