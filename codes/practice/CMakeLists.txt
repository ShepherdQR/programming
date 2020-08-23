#************
#  * @Author: Shepherd Qirong
#  * @Date: 2020-02-19 15:04:20
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2020-08-02 22:01:14
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************


# modified on 2020021915:11
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(HW_OPENGL) # 声明cmake 工程

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")











#添加一个库
#语法：add_library( 库名称 源代码文件 ），会生成 lib库名称.a（静态库),like .c .cpp  ...
#语法：add_library( 库名称 SHARED 源代码文件 ），会生成 lib库名称.so （共享库




file(GLOB cpp_executable *.cpp)


file(GLOB cpp_class ./ClassCollections/*.cpp)
include_directories(./ClassCollections) #指定头文件目录

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable} ${cpp_class} )
#


#将可执行程序链接到库
target_link_libraries(main  )#${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD#${PCL_LIBRARIES}
