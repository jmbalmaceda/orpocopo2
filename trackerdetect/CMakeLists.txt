cmake_minimum_required(VERSION 2.8)
project( trackerdetect )
set (CMAKE_MODULE_PATH /mnt/datos/Dropbox/orco/orpocopo2/trackerdetect )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
find_package( MariaDB REQUIRED)
include_directories(${MARIADB_INCLUDE_DIR})
add_library( tracker tracker.cpp )
add_library( iniparser ini.cpp )
add_library( rutines rutines.cpp)
add_library( dbconn DBConnection.cpp)
add_library( detect_mov detect_movement.cpp )
add_library( index index.cpp )

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /mnt/d/mysql-mariadb)

link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/libmariadb)

add_executable( trackerdetect trackerdetect.cpp )

IF(CMAKE_CROSSCOMPILING)
   target_link_libraries( trackerdetect dbconn rutines tracker detect_mov index libmariadb ${OpenCV_LIBS} )
ELSE(CMAKE_CROSSCOMPILING)
   target_link_libraries( trackerdetect dbconn mysqlclient rutines tracker detect_mov index ${OpenCV_LIBS} )
ENDIF(CMAKE_CROSSCOMPILING)

