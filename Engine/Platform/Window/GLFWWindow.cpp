#include "GLFWWindow.hpp"
#include <stdexcept>

namespace MilkChoco
{

    GLFWWindow::GLFWWindow(int width, int height, const char* title, bool fullscreen)
    {
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 4);

        GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

        if (fullscreen)
        {
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            if (mode == nullptr)
            {
                glfwTerminate();
                throw std::runtime_error{"Failed to query the primary monitor video mode."};
            }
            width = mode->width;
            height = mode->height;
        }

        m_width = width;
        m_height = height;

        m_window = glfwCreateWindow(width, height, title, monitor, nullptr);

        if (!m_window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1);

        // -------------------------
        // IMPORTANT: attach instance
        // -------------------------
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetFramebufferSizeCallback(m_window, FramebufferSizeCallback);



        glfwSetCursorPosCallback(m_window, MouseMoveCallback); // idk pa
        // -------------------------
        // REGISTER CALLBACKS
        // -------------------------

        glfwSetMouseButtonCallback(m_window, MouseButtonCallback);
        glfwSetKeyCallback(m_window, KeyCallback);

    }

    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void GLFWWindow::Update() const
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool GLFWWindow::ShouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    GLFWwindow* GLFWWindow::GetNative() const
    {
        return m_window;
    }

    void GLFWWindow::RequestClose() noexcept
    {
        if (m_window != nullptr)
        {
            glfwSetWindowShouldClose(m_window, GLFW_TRUE);
        }
    }

    glm::vec2 GLFWWindow::GetSize() const
    {
        return { (float)m_width, (float)m_height };
    }

    // =========================================================
    // ENGINE BINDING
    // =========================================================

    void GLFWWindow::SetMouseMoveCallback(MouseMoveCallbackFn cb)
    {
        m_mouseMoveCb = std::move(cb);
    }

    void GLFWWindow::SetMouseButtonCallback(MouseButtonCallbackFn cb)
    {
        m_mouseButtonCb = std::move(cb);
    }

    void GLFWWindow::SetKeyCallback(KeyCallbackFn cb)
    {
        m_keyCb = std::move(cb);
    }

    void GLFWWindow::SetResizeCallback(ResizeCallbackFn cb)
    {
        m_resizeCb = std::move(cb);
    }

    // =========================================================
    // STATIC CALLBACKS (GLFW → WINDOW)
    // =========================================================

    void GLFWWindow::MouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
    {
        auto* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
        if (self)
            self->OnMouseMove((float)xpos, (float)ypos);
    }

    void GLFWWindow::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        auto* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
        if (self)
            self->OnMouseButton(button, action, mods);
    }

    void GLFWWindow::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
        if (self)
            self->OnKey(key, scancode, action, mods);
    }

    void GLFWWindow::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0,0, width, height);
        auto* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));

        if (self)
            self->OnResize(width, height);
    }

    // =========================================================
    // INSTANCE HANDLERS (FORWARD TO ENGINE)
    // =========================================================

    void GLFWWindow::OnMouseMove(float x, float y)
    {
        if (m_mouseMoveCb)
            m_mouseMoveCb(x, y);
    }

    void GLFWWindow::OnMouseButton(int button, int action, int mods)
    {
        if (m_mouseButtonCb)
            m_mouseButtonCb(button, action, mods);
    }

    void GLFWWindow::OnKey(int key, int scancode, int action, int mods)
    {
        if (m_keyCb)
            m_keyCb(key, scancode, action, mods);
    }

    void GLFWWindow::OnResize(int width, int height)
    {
        m_width = width;
        m_height = height;

        if (m_resizeCb)
            m_resizeCb(width, height);
    }

}