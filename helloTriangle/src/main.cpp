#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main(int argc, char *argv[]) {
    // Init glfw
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {

    std::cout << "Failed to create Window with GLFW!" << std::endl;
    glfwTerminate();
    return -1;
  }
  //Set as window
  glfwMakeContextCurrent(window);

  //Init GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

    std::cout << "Failed to initialise GLAD!" << std::endl;
    return -1;
  }

  //Make visible
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // vertices and shader
  float vertices[] = {
      -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      0.0f, 0.5f, 0.0f
  };
  const char *vertexShaderSource =
      "#version 330 core\n"	//OpenGL version
      "layout (location = 0) in vec3 aPos;\n" //var declaration as in(put) -> vector(3,1)
      "void main()\n"
      "{\n"
      " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" //convert to vector(4,1)
      "}\0";
  unsigned int VBO;

  //Write Vertices to Buffer (VRAM)
  glGenBuffers(1,&VBO);
  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices, GL_STATIC_DRAW);

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);

  if (!success) {
      glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog << std::endl;
  }

  while (!glfwWindowShouldClose(window)) {

    // Input
    processInput(window);

    // Rendering:

    //std::cout << "Red;Green;Blue : "<<red<<";"<<green<<";"<<blue  << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);

    // check, call events and swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
