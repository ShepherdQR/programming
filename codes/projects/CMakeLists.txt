#************
#  * @Author: Shepherd Qirong
#  * @Date: 2020-02-19 21:25:37
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2020-02-19 21:51:22
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************

# modified on 2020021915:11

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(HW_OPENGL)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})

add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found ")
endif(NOT OPENGL_FOUND)


find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR "GLUT not found")
endif(NOT GLUT_FOUND)



find_package(glfw3 REQUIRED)
message(STATUS "Found glfw in ${GLFW_INCLUDE_DIR}")






find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})






add_library(GLAD "../openglstudying/include/glad.c")

file(GLOB cpp_executable *.cpp)
#file(GLOB cpp_class ../ClassCollections/*.cpp)

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable} ../openglstudying/include/stb_image.cpp )#${cpp_class}
#

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD ${PCL_LIBRARIES})
