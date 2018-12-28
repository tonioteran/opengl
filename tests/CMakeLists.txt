set ( EXECUTABLE_OUTPUT_PATH ../bin )

add_executable(testHelloWorld testHelloWorld.cpp)
target_link_libraries(testHelloWorld)

add_executable(testIncludeLibraries testIncludeLibraries.cpp)
target_link_libraries(testIncludeLibraries)
