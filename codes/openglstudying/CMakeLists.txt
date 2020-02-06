cmake_minimum_required(VERSION 3.1)
PROJECT(HW_OPENGL)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

#find_package(glfw REQUIRED)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR "GLUT not found")
endif(NOT GLUT_FOUND)





find_package(GLFW REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT glfw3_FOUND)
    message(ERROR "glfw3 not found")
endif(NOT GLFW_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})

add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found ")
endif(NOT OPENGL_FOUND)


add_library(GLAD "./glad.c")

#aux_source_directory(. DIR_SRCS)


add_executable(main main.cpp)

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GLFW GLAD)
