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
CMAKE_SOURCE_DIR = /mnt/datos/Dropbox/orco/codigo/trackerdetect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/datos/Dropbox/orco/codigo/trackerdetect/build

# Include any dependencies generated for this target.
include CMakeFiles/tracker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tracker.dir/flags.make

CMakeFiles/tracker.dir/tracker.cpp.o: CMakeFiles/tracker.dir/flags.make
CMakeFiles/tracker.dir/tracker.cpp.o: ../tracker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/Dropbox/orco/codigo/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tracker.dir/tracker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tracker.dir/tracker.cpp.o -c /mnt/datos/Dropbox/orco/codigo/trackerdetect/tracker.cpp

CMakeFiles/tracker.dir/tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tracker.dir/tracker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/Dropbox/orco/codigo/trackerdetect/tracker.cpp > CMakeFiles/tracker.dir/tracker.cpp.i

CMakeFiles/tracker.dir/tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tracker.dir/tracker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/Dropbox/orco/codigo/trackerdetect/tracker.cpp -o CMakeFiles/tracker.dir/tracker.cpp.s

CMakeFiles/tracker.dir/tracker.cpp.o.requires:

.PHONY : CMakeFiles/tracker.dir/tracker.cpp.o.requires

CMakeFiles/tracker.dir/tracker.cpp.o.provides: CMakeFiles/tracker.dir/tracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/tracker.dir/build.make CMakeFiles/tracker.dir/tracker.cpp.o.provides.build
.PHONY : CMakeFiles/tracker.dir/tracker.cpp.o.provides

CMakeFiles/tracker.dir/tracker.cpp.o.provides.build: CMakeFiles/tracker.dir/tracker.cpp.o


# Object files for target tracker
tracker_OBJECTS = \
"CMakeFiles/tracker.dir/tracker.cpp.o"

# External object files for target tracker
tracker_EXTERNAL_OBJECTS =

libtracker.a: CMakeFiles/tracker.dir/tracker.cpp.o
libtracker.a: CMakeFiles/tracker.dir/build.make
libtracker.a: CMakeFiles/tracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/Dropbox/orco/codigo/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtracker.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tracker.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tracker.dir/build: libtracker.a

.PHONY : CMakeFiles/tracker.dir/build

CMakeFiles/tracker.dir/requires: CMakeFiles/tracker.dir/tracker.cpp.o.requires

.PHONY : CMakeFiles/tracker.dir/requires

CMakeFiles/tracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tracker.dir/clean

CMakeFiles/tracker.dir/depend:
	cd /mnt/datos/Dropbox/orco/codigo/trackerdetect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/Dropbox/orco/codigo/trackerdetect /mnt/datos/Dropbox/orco/codigo/trackerdetect /mnt/datos/Dropbox/orco/codigo/trackerdetect/build /mnt/datos/Dropbox/orco/codigo/trackerdetect/build /mnt/datos/Dropbox/orco/codigo/trackerdetect/build/CMakeFiles/tracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tracker.dir/depend

