cmake_minimum_required(VERSION 3.12)

add_executable(drawTriangles drawTriangles.cpp)
target_link_libraries(drawTriangles PUBLIC OpenGL glad glfw)
target_include_directories(drawTriangles PUBLIC "${GLAD_INCLUDE_DIR}")
