#set ( EXECUTABLE_OUTPUT_PATH ../bin )
cmake_minimum_required(VERSION 3.12)

set(MY_TESTS
    testHelloWorld;
    testIncludeLibraries;)
    #testHelloWindow;
    #testHelloTriangle)

foreach(my_test IN LISTS MY_TESTS)
    add_executable(${my_test} "${my_test}.cpp")
    target_link_libraries(${my_test} PUBLIC OpenGL ${GLFW_LIBRARIES})
endforeach(my_test)

#add_executable(testHelloWorld testHelloWorld.cpp)
#target_link_libraries(testHelloWorld)

#add_executable(testIncludeLibraries testIncludeLibraries.cpp)
#target_link_libraries(testIncludeLibraries "${GLFW3_LIBRARIES}")

#add_executable(testHelloWindow testHelloWindow.cpp)
#target_link_libraries(testHelloWindow glfw "${GLFW_LIBRARIES}"
    #${LIBS})

#add_executable(testHelloTriangle testHelloTriangle.cpp)
#target_link_libraries(testHelloTriangle glfw "${GLFW_LIBRARIES}"
    #${LIBS})


