cmake_minimum_required(VERSION 2.8)
project( trackerdetect )
set (CMAKE_MODULE_PATH /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
include_directories(/mnt/d/mariadb-connector-c/include/mariadb)
add_library( inireader INIReader.cpp)
add_library (inireaderc ini.c)
add_library( tracker tracker.cpp )
add_library( rutines rutines.cpp)
add_library( dbconn DBConnection.cpp)
add_library( detect_mov detect_movement.cpp )
add_library( index index.cpp )

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /mnt/d/mysql-mariadbx64)

link_directories(/mnt/d/mariadb-connector-c/lib/mariadb/)

add_executable( trackerdetect trackerdetect.cpp )

IF(CMAKE_CROSSCOMPILING)
   target_link_libraries( trackerdetect dbconn rutines tracker detect_mov index libmariadb inireader inireaderc ${OpenCV_LIBS} )
ELSE(CMAKE_CROSSCOMPILING)
   target_link_libraries( trackerdetect dbconn mysqlclient rutines tracker detect_mov index inireader inireaderc ${OpenCV_LIBS} )
ENDIF(CMAKE_CROSSCOMPILING)

