cmake_minimum_required(VERSION 3.1)
PROJECT(HW_OPENGL)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR "GLUT not found")
endif(NOT GLUT_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found ")
endif(NOT OPENGL_FOUND)


#aux_source_directory(. SRC_LIST)


add_executable(main gl001opengl_teapot.cpp)

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
