cmake_minimum_required (VERSION 2.8)
cmake_policy (VERSION 2.8)

project ( LearnOpenGL )

# Custom FindXXX.cmake modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

link_directories ( ${CMAKE_SOURCE_DIR}/lib )

list (APPEND CMAKE_CXX_FLAGS "-std=c++11")

find_package ( GLM REQUIRED )
find_package ( GLFW3 REQUIRED )
find_package ( OpenGL REQUIRED )
find_package ( X11 REQUIRED )

include_directories ( tests )
add_subdirectory ( tests )

