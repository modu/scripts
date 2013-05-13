# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation

# Include any dependencies generated for this target.
include CMakeFiles/region_growing_rgb_segmentation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/region_growing_rgb_segmentation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/region_growing_rgb_segmentation.dir/flags.make

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o: CMakeFiles/region_growing_rgb_segmentation.dir/flags.make
CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o -c /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation/main.cpp

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation/main.cpp > CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.i

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation/main.cpp -o CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.s

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.requires

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.provides: CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/region_growing_rgb_segmentation.dir/build.make CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.provides

CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.provides.build: CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o

# Object files for target region_growing_rgb_segmentation
region_growing_rgb_segmentation_OBJECTS = \
"CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o"

# External object files for target region_growing_rgb_segmentation
region_growing_rgb_segmentation_EXTERNAL_OBJECTS =

region_growing_rgb_segmentation: CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o
region_growing_rgb_segmentation: CMakeFiles/region_growing_rgb_segmentation.dir/build.make
region_growing_rgb_segmentation: /usr/lib/libboost_system-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_filesystem-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_thread-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_date_time-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_iostreams-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_mpi-mt.so
region_growing_rgb_segmentation: /usr/lib/libboost_serialization-mt.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_common.so
region_growing_rgb_segmentation: /usr/lib/libflann_cpp_s.a
region_growing_rgb_segmentation: /usr/local/lib/libpcl_kdtree.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_octree.so
region_growing_rgb_segmentation: /usr/lib/libOpenNI.so
region_growing_rgb_segmentation: /usr/lib/libvtkCommon.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkRendering.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkHybrid.so.5.8.0
region_growing_rgb_segmentation: /usr/local/lib/libpcl_io.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_search.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_sample_consensus.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_filters.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_features.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_ml.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_segmentation.so
region_growing_rgb_segmentation: /usr/lib/libqhull.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_surface.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_registration.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_recognition.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_keypoints.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_visualization.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_outofcore.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_tracking.so
region_growing_rgb_segmentation: /usr/local/lib/libpcl_stereo.so
region_growing_rgb_segmentation: /usr/lib/libvtkParallel.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkRendering.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkGraphics.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkImaging.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkIO.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkFiltering.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtkCommon.so.5.8.0
region_growing_rgb_segmentation: /usr/lib/libvtksys.so.5.8.0
region_growing_rgb_segmentation: CMakeFiles/region_growing_rgb_segmentation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable region_growing_rgb_segmentation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/region_growing_rgb_segmentation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/region_growing_rgb_segmentation.dir/build: region_growing_rgb_segmentation
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/build

CMakeFiles/region_growing_rgb_segmentation.dir/requires: CMakeFiles/region_growing_rgb_segmentation.dir/main.cpp.o.requires
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/requires

CMakeFiles/region_growing_rgb_segmentation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/region_growing_rgb_segmentation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/clean

CMakeFiles/region_growing_rgb_segmentation.dir/depend:
	cd /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation /home/kirill/coding/MyPy/scripts/cppexp/pcl/color_seg_grow_segmentation/CMakeFiles/region_growing_rgb_segmentation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/region_growing_rgb_segmentation.dir/depend
