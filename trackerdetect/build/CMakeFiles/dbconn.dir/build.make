# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /mnt/datos/orco/orpocopo2/trackerdetect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/datos/orco/orpocopo2/trackerdetect/build

# Include any dependencies generated for this target.
include CMakeFiles/dbconn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dbconn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dbconn.dir/flags.make

CMakeFiles/dbconn.dir/DBConnection.cpp.o: CMakeFiles/dbconn.dir/flags.make
CMakeFiles/dbconn.dir/DBConnection.cpp.o: ../DBConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/orco/orpocopo2/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dbconn.dir/DBConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dbconn.dir/DBConnection.cpp.o -c /mnt/datos/orco/orpocopo2/trackerdetect/DBConnection.cpp

CMakeFiles/dbconn.dir/DBConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dbconn.dir/DBConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/orco/orpocopo2/trackerdetect/DBConnection.cpp > CMakeFiles/dbconn.dir/DBConnection.cpp.i

CMakeFiles/dbconn.dir/DBConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dbconn.dir/DBConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/orco/orpocopo2/trackerdetect/DBConnection.cpp -o CMakeFiles/dbconn.dir/DBConnection.cpp.s

CMakeFiles/dbconn.dir/DBConnection.cpp.o.requires:

.PHONY : CMakeFiles/dbconn.dir/DBConnection.cpp.o.requires

CMakeFiles/dbconn.dir/DBConnection.cpp.o.provides: CMakeFiles/dbconn.dir/DBConnection.cpp.o.requires
	$(MAKE) -f CMakeFiles/dbconn.dir/build.make CMakeFiles/dbconn.dir/DBConnection.cpp.o.provides.build
.PHONY : CMakeFiles/dbconn.dir/DBConnection.cpp.o.provides

CMakeFiles/dbconn.dir/DBConnection.cpp.o.provides.build: CMakeFiles/dbconn.dir/DBConnection.cpp.o


# Object files for target dbconn
dbconn_OBJECTS = \
"CMakeFiles/dbconn.dir/DBConnection.cpp.o"

# External object files for target dbconn
dbconn_EXTERNAL_OBJECTS =

libdbconn.a: CMakeFiles/dbconn.dir/DBConnection.cpp.o
libdbconn.a: CMakeFiles/dbconn.dir/build.make
libdbconn.a: CMakeFiles/dbconn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/orco/orpocopo2/trackerdetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdbconn.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dbconn.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dbconn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dbconn.dir/build: libdbconn.a

.PHONY : CMakeFiles/dbconn.dir/build

CMakeFiles/dbconn.dir/requires: CMakeFiles/dbconn.dir/DBConnection.cpp.o.requires

.PHONY : CMakeFiles/dbconn.dir/requires

CMakeFiles/dbconn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dbconn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dbconn.dir/clean

CMakeFiles/dbconn.dir/depend:
	cd /mnt/datos/orco/orpocopo2/trackerdetect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/orco/orpocopo2/trackerdetect /mnt/datos/orco/orpocopo2/trackerdetect /mnt/datos/orco/orpocopo2/trackerdetect/build /mnt/datos/orco/orpocopo2/trackerdetect/build /mnt/datos/orco/orpocopo2/trackerdetect/build/CMakeFiles/dbconn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dbconn.dir/depend

