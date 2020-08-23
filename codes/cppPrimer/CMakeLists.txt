#************
#  * @Author: Shepherd Qirong
#  * @Date: 2020-02-19 15:04:20
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2020-06-01 15:41:57
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(CPP_Primer)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")



#add_library(GLAD "./openglstudying/include/glad.c")

file(GLOB cpp_executable *.cpp)
#file(GLOB cpp_class ./ClassCollections/*.cpp)
include_directories(./ClassCollections) #指定头文件目录

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable})


