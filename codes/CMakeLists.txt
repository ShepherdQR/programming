#************
#  * @Author: Shepherd Qirong
#  * @Date: 2020-02-19 15:04:20
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2020-02-19 22:29:32
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************


# modified on 2020021915:11
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(HW_OPENGL) # 声明cmake 工程

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






#   find_package(PCL 1.2 REQUIRED)
#    include_directories(${PCL_INCLUDE_DIRS})
 #   link_directories(${PCL_LIBRARY_DIRS})
 #   add_definitions(${PCL_DEFINITIONS})





#添加一个库
#语法：add_library( 库名称 源代码文件 ），会生成 lib库名称.a（静态库),like .c .cpp  ...
#语法：add_library( 库名称 SHARED 源代码文件 ），会生成 lib库名称.so （共享库

add_library(GLAD "./openglstudying/include/glad.c")

file(GLOB cpp_executable *.cpp)
file(GLOB cpp_class ./ClassCollections/*.cpp)

include_directories(./ClassCollections) #指定头文件目录

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable} ./openglstudying/include/stb_image.cpp ${cpp_class})
#


#将可执行程序链接到库
target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD )#${PCL_LIBRARIES}
