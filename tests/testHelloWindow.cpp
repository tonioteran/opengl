/**
 * @file testHelloWindow.cpp
 * @brief spawning a window 
 * @date December 28, 2018
 * @author Antonio Teran, teran@mit.edu
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void) {

  std::cout << "Hello OpenGL Window!!!" << std::endl;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "HelloWindow", NULL, NULL);
  if ( window == NULL ) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return (-1);
  }
  glfwMakeContextCurrent(window);

  /* load all OpenGL function pointers */
  if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) ) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return (-1);
  }

  /* render loop */
  while ( !glfwWindowShouldClose(window) ) {

    //processInput(window);

    glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  glfwTerminate();

  return (0);

}
