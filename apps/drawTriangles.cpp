/**
 * @file drawTriangles.cpp
 * @brief draw simple triangles
 * @date Feb 11, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* function declarations */
void processInput(GLFWwindow *window);

/* settings */
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

/* shaders */
const char *vertexShaderSource = 
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main() {\n"
  "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
  "}\0";
const char *fragmentShaderSource = 
  "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main() {\n"
  "  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\n\0";

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

  // build and compile custom shaders
  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // link shaders
  int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glDeleteShader(vertexShader); glDeleteShader(fragmentShader); // del after use

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











  return (0);

}
