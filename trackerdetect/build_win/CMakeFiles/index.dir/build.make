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
CMAKE_BINARY_DIR = /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win

# Include any dependencies generated for this target.
include CMakeFiles/index.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/index.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/index.dir/flags.make

CMakeFiles/index.dir/index.cpp.obj: CMakeFiles/index.dir/flags.make
CMakeFiles/index.dir/index.cpp.obj: CMakeFiles/index.dir/includes_CXX.rsp
CMakeFiles/index.dir/index.cpp.obj: ../index.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/index.dir/index.cpp.obj"
	/usr/bin/x86_64-w64-mingw32-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/index.dir/index.cpp.obj -c /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/index.cpp

CMakeFiles/index.dir/index.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/index.dir/index.cpp.i"
	/usr/bin/x86_64-w64-mingw32-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/index.cpp > CMakeFiles/index.dir/index.cpp.i

CMakeFiles/index.dir/index.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/index.dir/index.cpp.s"
	/usr/bin/x86_64-w64-mingw32-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/index.cpp -o CMakeFiles/index.dir/index.cpp.s

CMakeFiles/index.dir/index.cpp.obj.requires:

.PHONY : CMakeFiles/index.dir/index.cpp.obj.requires

CMakeFiles/index.dir/index.cpp.obj.provides: CMakeFiles/index.dir/index.cpp.obj.requires
	$(MAKE) -f CMakeFiles/index.dir/build.make CMakeFiles/index.dir/index.cpp.obj.provides.build
.PHONY : CMakeFiles/index.dir/index.cpp.obj.provides

CMakeFiles/index.dir/index.cpp.obj.provides.build: CMakeFiles/index.dir/index.cpp.obj


# Object files for target index
index_OBJECTS = \
"CMakeFiles/index.dir/index.cpp.obj"

# External object files for target index
index_EXTERNAL_OBJECTS =

libindex.a: CMakeFiles/index.dir/index.cpp.obj
libindex.a: CMakeFiles/index.dir/build.make
libindex.a: CMakeFiles/index.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libindex.a"
	$(CMAKE_COMMAND) -P CMakeFiles/index.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/index.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/index.dir/build: libindex.a

.PHONY : CMakeFiles/index.dir/build

CMakeFiles/index.dir/requires: CMakeFiles/index.dir/index.cpp.obj.requires

.PHONY : CMakeFiles/index.dir/requires

CMakeFiles/index.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/index.dir/cmake_clean.cmake
.PHONY : CMakeFiles/index.dir/clean

CMakeFiles/index.dir/depend:
	cd /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect/build_win/CMakeFiles/index.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/index.dir/depend

