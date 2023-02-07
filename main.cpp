#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  GLFWwindow *window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "1", nullptr, nullptr);
  if (!window) {
    std::cerr << "GLFWwindow initialize failed" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window,
                                 [](GLFWwindow *window, int width, int height) {
                                   /**
                                    * OpenGL幕后使用glViewport中定义的位置和宽高进行2D坐标的转换，将OpenGL中的位置坐标转换为你的屏幕坐标。
                                    * 例如将(-1到1)范围内的坐标映射到(0,
                                    * 800)和(0, 600)。
                                    */
                                   glViewport(0, 0, width, height);
                                 });

  // GLAD是用来管理OpenGL的函数指针的
  // glfwGetProcAddress用来加载系统相关的OpenGL函数指针地址,它根据我们编译的系统定义了正确的函数。
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "GLAD initialize failed" << std::endl;
    return EXIT_FAILURE;
  }

  // 简单的渲染循环
  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    // glClearColor函数是一个状态设置函数，设置应该清除成什么颜色
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // 交换双缓冲
    glfwSwapBuffers(window);
    // 检查有没有触发键盘鼠标的事件
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}