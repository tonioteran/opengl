/**
 * @file maxVertexAttribs.cpp
 * @brief get the max number of vertex attributes available
 * @date Feb 12, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void) {

  std::cout << "Getting your machine's max num of vrtx attribs!" << std::endl;

  int n_attributes;
  glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n_attributes);
  std::cout << "Max vrtx attributes supported: " << n_attributes << std::endl;

  return (0);

}

