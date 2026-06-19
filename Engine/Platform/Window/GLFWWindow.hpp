#pragma once
#include <GLFW/glfw3.h>

namespace MilkChoco
{
    class GLFWWindow
    {
    public:
        GLFWWindow(int width, int height, const char* title);
        ~GLFWWindow();

        void Update();

        bool ShouldClose() const
        {
            return glfwWindowShouldClose(m_window);
        }

    private:
        GLFWwindow* m_window = nullptr;
    };
}