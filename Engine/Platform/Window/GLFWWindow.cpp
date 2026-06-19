
#include "GLFWWindow.hpp"


namespace MilkChoco
{
    GLFWWindow::GLFWWindow(int width, int height, const char *title)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        glfwMakeContextCurrent(m_window);

        glfwSetWindowUserPointer(m_window, this);
    }
    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    void GLFWWindow::Update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}