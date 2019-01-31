cmake_minimum_required (VERSION 3.12)

project ( LearnOpenGL )

# Custom FindXXX.cmake modules
#set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
    #"${CMAKE_SOURCE_DIR}/cmake/modules")

#link_directories ( ${CMAKE_SOURCE_DIR}/lib )

#list (APPEND CMAKE_CXX_FLAGS "-std=c++11")

find_package(PkgConfig REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS}) # horrible practice, but that's what
                                          # the glfw website says to do


#find_package ( GLM REQUIRED )
#find_package ( GLFW3 REQUIRED )
find_package ( OpenGL REQUIRED )
#find_package ( X11 REQUIRED )

#set (TESTS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
#set (SOURCES "${TESTS_SRC_DIR}/*.cpp")
#set ( CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl" )

add_library (GLAD "src/glad.c")
include_directories ( ${CMAKE_SOURCE_DIR}/includes )
set ( LIBS ${LIBS} GLAD )

#include_directories ( tests )
add_subdirectory ( tests )

