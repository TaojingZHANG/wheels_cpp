cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)
project(ceres_test)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(OpenCV_DIR /usr/local/opencv320/share/OpenCV)

find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})
include_directories( "/usr/local/include/eigen3/")

add_executable(ceres_test ceres_test.cpp)

target_link_libraries( ceres_test ${OpenCV_LIBS}  ${CERES_LIBRARIES})
