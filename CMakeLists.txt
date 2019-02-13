cmake_minimum_required(VERSION 3.12)
project(learnOpenGL)

set(CMAKE_BUILD_TYPE Debug)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(GLAD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/includes/")
add_library("glad" "${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_INCLUDE_DIR}")

set(NAVVIZ_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes/")
set(STB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/stb/")

add_definitions( -DREPO_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory(apps)





