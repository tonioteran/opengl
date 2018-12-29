set ( EXECUTABLE_OUTPUT_PATH ../bin )

add_executable(testHelloWorld testHelloWorld.cpp)
target_link_libraries(testHelloWorld)

add_executable(testIncludeLibraries testIncludeLibraries.cpp)
target_link_libraries(testIncludeLibraries "${GLFW3_LIBRARIES}")

add_executable(testHelloWindow testHelloWindow.cpp)
target_link_libraries(testHelloWindow glfw "${GLFW_LIBRARIES}"
    ${LIBS})

add_executable(testHelloTriangle testHelloTriangle.cpp)
target_link_libraries(testHelloTriangle glfw "${GLFW_LIBRARIES}"
    ${LIBS})


