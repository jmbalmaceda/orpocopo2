SET(CMAKE_SYSTEM_NAME Windows)

set(COMPILER_PREFIX "x86_64-w64-mingw32")

# which compilers to use for C and C++
find_program(CMAKE_RC_COMPILER NAMES ${COMPILER_PREFIX}-windres)
SET(CMAKE_RC_COMPILER ${COMPILER_PREFIX}-windres)
find_program(CMAKE_C_COMPILER NAMES ${COMPILER_PREFIX}-gcc)
SET(CMAKE_C_COMPILER ${COMPILER_PREFIX}-gcc)
find_program(CMAKE_CXX_COMPILER NAMES ${COMPILER_PREFIX}-g++)
SET(CMAKE_CXX_COMPILER ${COMPILER_PREFIX}-g++)


include_directories(SYSTEM /mnt/d/opencv_build/install/include)

