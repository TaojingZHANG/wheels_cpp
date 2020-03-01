cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)
project(g2o_simple_optimize)

set(CMAKE_CXX_FLAGS "-std=c++11")


list( APPEND CMAKE_MODULE_PATH /home/ztj/software/g2o-master/cmake_modules/ )
set(OpenCV_DIR /usr/local/opencv320/share/OpenCV)

find_package(Eigen3 REQUIRED)
find_package(G2O REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CSparse REQUIRED)
find_package(Cholmod REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories( ${G2O_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${CHOLMOD_INCLUDE_DIR})
include_directories(${CSparse_INCLUDE_DIR})

SET(G2O_LIBS g2o_cli g2o_ext_freeglut_minimal g2o_simulator g2o_solver_slam2d_linear g2o_types_icp g2o_types_slam2d g2o_core g2o_interface g2o_solver_csparse g2o_solver_structure_only g2o_types_sba g2o_types_slam3d g2o_csparse_extension g2o_opengl_helper g2o_solver_dense g2o_stuff g2o_types_sclam2d g2o_parser g2o_solver_pcg g2o_types_data g2o_types_sim3 cxsparse )

add_executable(g2o_simple_optimize g2o_simple_optimize.cpp)

target_link_libraries( g2o_simple_optimize ${OpenCV_LIBS} ${G2O_LIBS})