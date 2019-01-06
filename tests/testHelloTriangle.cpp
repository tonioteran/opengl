/**
 * @file testHelloTriangle.cpp
 * @brief drawing a simple triangle
 * @date December 29, 2018
 * @author Antonio Teran, teran@mit.edu
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

  std::cout << "Hello OpenGL Triangle!!!" << std::endl;

  // -- glfw: initialize and configure
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  // -- glfw: window creation
  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, 
      "HelloWindow", NULL, NULL);
  if ( window == NULL ) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return (-1);
  }
  glfwMakeContextCurrent(window);

  // -- load all OpenGL function pointers 
  if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) ) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return (-1);
  }

  // -- build and compile our shader program
  // vertex shader
  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  int success; char infoLog[512]; // check for compile errors
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if ( !success ) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMP_FAIL\n" << infoLog << std::endl;
  }
  // fragment shader
  int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if ( !success ) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAG::COMP_FAIL\n" << infoLog << std::endl;
  }
  // link shaders
  int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if ( !success ) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROG::LINK_FAIL\n" << infoLog << std::endl;
  }
  glDeleteShader(vertexShader); glDeleteShader(fragmentShader);

  // -- set up vertex data
  float vertices[] = {
    -0.8f, -0.5f, 0.0f, 
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
     0.5f,  0.0f, 0.0f,
     0.7f,  0.2f, 0.0f,
     0.2f,  0.8f, 0.0f
  };
  
  // -- configure vertex attributes
  /* vertex buffer object */
  unsigned int VBO[2], VAO[2];
  glGenVertexArrays(2, VAO);
  glGenBuffers(2, VBO);

  // -- bind vertex array first, then bind and set vertex buffers
  glBindVertexArray(VAO[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // -- configure vertex attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // to draw wireframe

  /* render loop */
  while ( !glfwWindowShouldClose(window) ) {

    processInput(window);
    
    // -- render
    glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // -- draw triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0); // unbind 

    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  // -- deallocate resources
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  glfwTerminate();

  return (0);

}


/* ************************************************************************** */
void processInput(GLFWwindow *window) {

  if ( glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
    glfwSetWindowShouldClose(window, true);
  
}





