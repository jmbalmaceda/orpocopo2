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
CMAKE_SOURCE_DIR = /mnt/datos/Dropbox/orco/orpocopo2/roigondola

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/datos/Dropbox/orco/orpocopo2/roigondola/build

# Include any dependencies generated for this target.
include CMakeFiles/roigondola.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roigondola.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roigondola.dir/flags.make

CMakeFiles/roigondola.dir/roigondola.cpp.o: CMakeFiles/roigondola.dir/flags.make
CMakeFiles/roigondola.dir/roigondola.cpp.o: ../roigondola.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/roigondola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roigondola.dir/roigondola.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roigondola.dir/roigondola.cpp.o -c /mnt/datos/Dropbox/orco/orpocopo2/roigondola/roigondola.cpp

CMakeFiles/roigondola.dir/roigondola.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roigondola.dir/roigondola.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/datos/Dropbox/orco/orpocopo2/roigondola/roigondola.cpp > CMakeFiles/roigondola.dir/roigondola.cpp.i

CMakeFiles/roigondola.dir/roigondola.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roigondola.dir/roigondola.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/datos/Dropbox/orco/orpocopo2/roigondola/roigondola.cpp -o CMakeFiles/roigondola.dir/roigondola.cpp.s

CMakeFiles/roigondola.dir/roigondola.cpp.o.requires:

.PHONY : CMakeFiles/roigondola.dir/roigondola.cpp.o.requires

CMakeFiles/roigondola.dir/roigondola.cpp.o.provides: CMakeFiles/roigondola.dir/roigondola.cpp.o.requires
	$(MAKE) -f CMakeFiles/roigondola.dir/build.make CMakeFiles/roigondola.dir/roigondola.cpp.o.provides.build
.PHONY : CMakeFiles/roigondola.dir/roigondola.cpp.o.provides

CMakeFiles/roigondola.dir/roigondola.cpp.o.provides.build: CMakeFiles/roigondola.dir/roigondola.cpp.o


# Object files for target roigondola
roigondola_OBJECTS = \
"CMakeFiles/roigondola.dir/roigondola.cpp.o"

# External object files for target roigondola
roigondola_EXTERNAL_OBJECTS =

roigondola: CMakeFiles/roigondola.dir/roigondola.cpp.o
roigondola: CMakeFiles/roigondola.dir/build.make
roigondola: /usr/local/lib/libopencv_stitching.so.3.2.0
roigondola: /usr/local/lib/libopencv_superres.so.3.2.0
roigondola: /usr/local/lib/libopencv_videostab.so.3.2.0
roigondola: /usr/local/lib/libopencv_aruco.so.3.2.0
roigondola: /usr/local/lib/libopencv_bgsegm.so.3.2.0
roigondola: /usr/local/lib/libopencv_bioinspired.so.3.2.0
roigondola: /usr/local/lib/libopencv_ccalib.so.3.2.0
roigondola: /usr/local/lib/libopencv_cvv.so.3.2.0
roigondola: /usr/local/lib/libopencv_dpm.so.3.2.0
roigondola: /usr/local/lib/libopencv_face.so.3.2.0
roigondola: /usr/local/lib/libopencv_freetype.so.3.2.0
roigondola: /usr/local/lib/libopencv_fuzzy.so.3.2.0
roigondola: /usr/local/lib/libopencv_hdf.so.3.2.0
roigondola: /usr/local/lib/libopencv_line_descriptor.so.3.2.0
roigondola: /usr/local/lib/libopencv_optflow.so.3.2.0
roigondola: /usr/local/lib/libopencv_reg.so.3.2.0
roigondola: /usr/local/lib/libopencv_rgbd.so.3.2.0
roigondola: /usr/local/lib/libopencv_saliency.so.3.2.0
roigondola: /usr/local/lib/libopencv_stereo.so.3.2.0
roigondola: /usr/local/lib/libopencv_structured_light.so.3.2.0
roigondola: /usr/local/lib/libopencv_surface_matching.so.3.2.0
roigondola: /usr/local/lib/libopencv_tracking.so.3.2.0
roigondola: /usr/local/lib/libopencv_xfeatures2d.so.3.2.0
roigondola: /usr/local/lib/libopencv_ximgproc.so.3.2.0
roigondola: /usr/local/lib/libopencv_xobjdetect.so.3.2.0
roigondola: /usr/local/lib/libopencv_xphoto.so.3.2.0
roigondola: /usr/local/lib/libopencv_shape.so.3.2.0
roigondola: /usr/local/lib/libopencv_photo.so.3.2.0
roigondola: /usr/local/lib/libopencv_calib3d.so.3.2.0
roigondola: /usr/local/lib/libopencv_viz.so.3.2.0
roigondola: /usr/local/lib/libopencv_phase_unwrapping.so.3.2.0
roigondola: /usr/local/lib/libopencv_video.so.3.2.0
roigondola: /usr/local/lib/libopencv_datasets.so.3.2.0
roigondola: /usr/local/lib/libopencv_dnn.so.3.2.0
roigondola: /usr/local/lib/libopencv_plot.so.3.2.0
roigondola: /usr/local/lib/libopencv_text.so.3.2.0
roigondola: /usr/local/lib/libopencv_features2d.so.3.2.0
roigondola: /usr/local/lib/libopencv_flann.so.3.2.0
roigondola: /usr/local/lib/libopencv_objdetect.so.3.2.0
roigondola: /usr/local/lib/libopencv_highgui.so.3.2.0
roigondola: /usr/local/lib/libopencv_ml.so.3.2.0
roigondola: /usr/local/lib/libopencv_videoio.so.3.2.0
roigondola: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
roigondola: /usr/local/lib/libopencv_imgproc.so.3.2.0
roigondola: /usr/local/lib/libopencv_core.so.3.2.0
roigondola: CMakeFiles/roigondola.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/datos/Dropbox/orco/orpocopo2/roigondola/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roigondola"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roigondola.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roigondola.dir/build: roigondola

.PHONY : CMakeFiles/roigondola.dir/build

CMakeFiles/roigondola.dir/requires: CMakeFiles/roigondola.dir/roigondola.cpp.o.requires

.PHONY : CMakeFiles/roigondola.dir/requires

CMakeFiles/roigondola.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roigondola.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roigondola.dir/clean

CMakeFiles/roigondola.dir/depend:
	cd /mnt/datos/Dropbox/orco/orpocopo2/roigondola/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/datos/Dropbox/orco/orpocopo2/roigondola /mnt/datos/Dropbox/orco/orpocopo2/roigondola /mnt/datos/Dropbox/orco/orpocopo2/roigondola/build /mnt/datos/Dropbox/orco/orpocopo2/roigondola/build /mnt/datos/Dropbox/orco/orpocopo2/roigondola/build/CMakeFiles/roigondola.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roigondola.dir/depend

