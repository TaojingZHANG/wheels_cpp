cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)
project(g2o)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(OpenCV_DIR /usr/local/opencv320/share/OpenCV)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(g2o g2o.cpp)

target_link_libraries( g2o ${OpenCV_LIBS} )