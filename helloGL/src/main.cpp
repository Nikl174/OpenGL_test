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
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

    std::cout << "Failed to initialise GLAD!" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  float red = 1.0f, green = 0.0f, blue = 0.0f, d_red = -0.01f, d_green = 0.01f,
        d_blue = 0.0f;

  while (!glfwWindowShouldClose(window)) {

    // Input
    processInput(window);

    // Rendering:
    glClearColor(red, green, blue, 1.0f);
    red += d_red;
    green += d_green;
    blue += d_blue;

    if (green >= 1.0f) {
      d_red = 0.0f, d_green = -0.01f, d_blue = 0.01f;
    } else if (red >= 1.0f) {
      d_red = -0.01f, d_green = 0.01f, d_blue = 0.0f;
    } else if (blue >= 1.0f) {
      d_red = 0.01f, d_green = 0.0f, d_blue = -0.01f;
    }

    //std::cout << "Red;Green;Blue : "<<red<<";"<<green<<";"<<blue  << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);

    // check, call events and swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
