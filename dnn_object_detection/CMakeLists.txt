cmake_minimum_required(VERSION 2.8)
project( ssd_object_detection )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
add_executable( ssd_object_detection ssd_object_detection.cpp )
target_link_libraries( ssd_object_detection  ${OpenCV_LIBS} )

add_executable( yolo_object_detection yolo_object_detection.cpp )
target_link_libraries( yolo_object_detection  ${OpenCV_LIBS} )
