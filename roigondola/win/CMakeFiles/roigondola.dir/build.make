# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Dropbox\orco\orpocopo2\roigondola

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Dropbox\orco\orpocopo2\roigondola\win

# Include any dependencies generated for this target.
include CMakeFiles/roigondola.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roigondola.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roigondola.dir/flags.make

CMakeFiles/roigondola.dir/roigondola.cpp.obj: CMakeFiles/roigondola.dir/flags.make
CMakeFiles/roigondola.dir/roigondola.cpp.obj: CMakeFiles/roigondola.dir/includes_CXX.rsp
CMakeFiles/roigondola.dir/roigondola.cpp.obj: ../roigondola.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Dropbox\orco\orpocopo2\roigondola\win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roigondola.dir/roigondola.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roigondola.dir\roigondola.cpp.obj -c G:\Dropbox\orco\orpocopo2\roigondola\roigondola.cpp

CMakeFiles/roigondola.dir/roigondola.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roigondola.dir/roigondola.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Dropbox\orco\orpocopo2\roigondola\roigondola.cpp > CMakeFiles\roigondola.dir\roigondola.cpp.i

CMakeFiles/roigondola.dir/roigondola.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roigondola.dir/roigondola.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Dropbox\orco\orpocopo2\roigondola\roigondola.cpp -o CMakeFiles\roigondola.dir\roigondola.cpp.s

CMakeFiles/roigondola.dir/roigondola.cpp.obj.requires:

.PHONY : CMakeFiles/roigondola.dir/roigondola.cpp.obj.requires

CMakeFiles/roigondola.dir/roigondola.cpp.obj.provides: CMakeFiles/roigondola.dir/roigondola.cpp.obj.requires
	$(MAKE) -f CMakeFiles\roigondola.dir\build.make CMakeFiles/roigondola.dir/roigondola.cpp.obj.provides.build
.PHONY : CMakeFiles/roigondola.dir/roigondola.cpp.obj.provides

CMakeFiles/roigondola.dir/roigondola.cpp.obj.provides.build: CMakeFiles/roigondola.dir/roigondola.cpp.obj


# Object files for target roigondola
roigondola_OBJECTS = \
"CMakeFiles/roigondola.dir/roigondola.cpp.obj"

# External object files for target roigondola
roigondola_EXTERNAL_OBJECTS =

roigondola.exe: CMakeFiles/roigondola.dir/roigondola.cpp.obj
roigondola.exe: CMakeFiles/roigondola.dir/build.make
roigondola.exe: D:/opencv_build/lib/libopencv_shape320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_stitching320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_superres320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_videostab320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_objdetect320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_calib3d320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_features2d320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_flann320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_highgui320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_ml320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_photo320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_video320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_videoio320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_imgcodecs320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_imgproc320.dll.a
roigondola.exe: D:/opencv_build/lib/libopencv_core320.dll.a
roigondola.exe: CMakeFiles/roigondola.dir/linklibs.rsp
roigondola.exe: CMakeFiles/roigondola.dir/objects1.rsp
roigondola.exe: CMakeFiles/roigondola.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Dropbox\orco\orpocopo2\roigondola\win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roigondola.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\roigondola.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roigondola.dir/build: roigondola.exe

.PHONY : CMakeFiles/roigondola.dir/build

CMakeFiles/roigondola.dir/requires: CMakeFiles/roigondola.dir/roigondola.cpp.obj.requires

.PHONY : CMakeFiles/roigondola.dir/requires

CMakeFiles/roigondola.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\roigondola.dir\cmake_clean.cmake
.PHONY : CMakeFiles/roigondola.dir/clean

CMakeFiles/roigondola.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Dropbox\orco\orpocopo2\roigondola G:\Dropbox\orco\orpocopo2\roigondola G:\Dropbox\orco\orpocopo2\roigondola\win G:\Dropbox\orco\orpocopo2\roigondola\win G:\Dropbox\orco\orpocopo2\roigondola\win\CMakeFiles\roigondola.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roigondola.dir/depend

