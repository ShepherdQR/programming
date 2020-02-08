
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
#include_directories(${glfw3_INCLUDE_DIRS})
#link_directories(${glfw3_LIBRARY_DIRS})
#add_definitions(${glfw3_DEFINITIONS})
#if(NOT glfw3_FOUND)
#    message(ERROR "glfw3 not found")
#endif(NOT glfw3_FOUND)



add_library(GLAD "./glad.c")

file(GLOB allll *.cpp)
message("Building the main cpp: "${allll})
add_executable(main ${allll})

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD)
