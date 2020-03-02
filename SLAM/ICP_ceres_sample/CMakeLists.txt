cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)
project(ICP_3D)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(OpenCV_DIR /usr/local/opencv320/share/OpenCV)

find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})
include_directories( "/usr/include/eigen3/")

add_executable(ICP_3D ICP_3D_byCeres.cpp)

target_link_libraries( ICP_3D ${OpenCV_LIBS}  ${CERES_LIBRARIES})
