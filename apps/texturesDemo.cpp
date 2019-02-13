/**
 * @file texturesDemo.cpp
 * @brief create and play around with textured objects
 * @date Feb 12, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

#include "Shader.h"

#define str(s) #s

/* function declarations */
void processInput(GLFWwindow *window);

/* settings */
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

int main(void) {

  std::cout << "Drawing some test triangles!" << std::endl;

  // initialize
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // create the window
  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
                                        "HelloWindow", NULL, NULL);
  if ( window == NULL ) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return (-1);
  }
  glfwMakeContextCurrent(window);

  // load OpenGL function pointers
  if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) ) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return (-1);
  }

  // load shaders from source file
  // Shader ourShader("/home/tonio/repos/opengl/apps/triangle.vs",
  //                  "/home/tonio/repos/opengl/apps/triangle.fs");
  Shader ourShader("/home/tonio/repos/opengl/apps/3.3.shader.vs",
                   "/home/tonio/repos/opengl/apps/3.3.shader.fs");

  // setup vertex data
  float vertices[] = {
    -0.8f, -0.5f, 0.0f, 
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f,
    0.5f,  0.0f, 0.0f,
    0.7f,  0.2f, 0.0f,
    0.2f,  0.8f, 0.0f
  };

  // generate buffer and arrays for 'n' triangles
  int num_elems = 2;
  unsigned int VBO[num_elems], VAO[num_elems];
  glGenVertexArrays(num_elems, VAO);
  glGenBuffers(num_elems, VBO);

  // configure the array objects
  for (int i = 0; i < num_elems; i++) {
    glBindVertexArray(VAO[i]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // point to the corresponding vertices:
    int offset = i*3;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),
                          (void*)(offset* sizeof(float)));
    glEnableVertexAttribArray(0);
  }

  // draw in wireframe mode:
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // render loop:
  while (!glfwWindowShouldClose(window)) {
    // input
    processInput(window);

    //render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ourShader.use();
    // draw triangles:
    for (int i = 0; i < num_elems; i++) {
      glBindVertexArray(VAO[i]);
      glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  glDeleteVertexArrays(2, VAO);
  glDeleteBuffers(2, VBO);

  glfwTerminate();
  return (0);

}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
