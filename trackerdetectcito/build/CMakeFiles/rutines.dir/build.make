# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build

# Include any dependencies generated for this target.
include CMakeFiles/rutines.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rutines.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rutines.dir/flags.make

CMakeFiles/rutines.dir/rutines.cpp.o: CMakeFiles/rutines.dir/flags.make
CMakeFiles/rutines.dir/rutines.cpp.o: ../rutines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rutines.dir/rutines.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rutines.dir/rutines.cpp.o -c /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/rutines.cpp

CMakeFiles/rutines.dir/rutines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rutines.dir/rutines.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/rutines.cpp > CMakeFiles/rutines.dir/rutines.cpp.i

CMakeFiles/rutines.dir/rutines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rutines.dir/rutines.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/rutines.cpp -o CMakeFiles/rutines.dir/rutines.cpp.s

CMakeFiles/rutines.dir/rutines.cpp.o.requires:

.PHONY : CMakeFiles/rutines.dir/rutines.cpp.o.requires

CMakeFiles/rutines.dir/rutines.cpp.o.provides: CMakeFiles/rutines.dir/rutines.cpp.o.requires
	$(MAKE) -f CMakeFiles/rutines.dir/build.make CMakeFiles/rutines.dir/rutines.cpp.o.provides.build
.PHONY : CMakeFiles/rutines.dir/rutines.cpp.o.provides

CMakeFiles/rutines.dir/rutines.cpp.o.provides.build: CMakeFiles/rutines.dir/rutines.cpp.o


# Object files for target rutines
rutines_OBJECTS = \
"CMakeFiles/rutines.dir/rutines.cpp.o"

# External object files for target rutines
rutines_EXTERNAL_OBJECTS =

librutines.a: CMakeFiles/rutines.dir/rutines.cpp.o
librutines.a: CMakeFiles/rutines.dir/build.make
librutines.a: CMakeFiles/rutines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librutines.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rutines.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rutines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rutines.dir/build: librutines.a

.PHONY : CMakeFiles/rutines.dir/build

CMakeFiles/rutines.dir/requires: CMakeFiles/rutines.dir/rutines.cpp.o.requires

.PHONY : CMakeFiles/rutines.dir/requires

CMakeFiles/rutines.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rutines.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rutines.dir/clean

CMakeFiles/rutines.dir/depend:
	cd /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build/CMakeFiles/rutines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rutines.dir/depend
