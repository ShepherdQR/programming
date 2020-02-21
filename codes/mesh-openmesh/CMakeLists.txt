#************
#  * @Author: Shepherd Qirong
#  * @Date: 2020-02-22 00:03:02
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2020-02-22 00:08:26
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(main)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(PCL 1.5 REQUIRED)
find_package(Eigen3)


list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR} /home/jellyfish/Softwares/OpenMesh-8.0/cmake)
find_package(OpenMesh REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${OpenMesh_include_dirs})

link_directories(${PCL_LIBRARY_DIRS} )
add_definitions(${PCL_DEFINITIONS})


file(GLOB cpp_executable *.cpp)
message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable})

target_link_libraries (main ${PCL_LIBRARIES} ${EIGEN3_INCLUDE_DIR} ${OpenMesh_libs} OpenMeshCore OpenMeshTools)





