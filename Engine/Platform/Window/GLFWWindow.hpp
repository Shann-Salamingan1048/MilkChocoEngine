#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <functional>

namespace MilkChoco
{
    class GLFWWindow
    {
    public:
        using MouseMoveCallbackFn   = std::function<void(float, float)>;
        using MouseButtonCallbackFn = std::function<void(int, int, int)>;
        using KeyCallbackFn         = std::function<void(int, int, int, int)>;
        using ResizeCallbackFn      = std::function<void(int, int)>;

    public:
        GLFWWindow(int width, int height, const char* title, bool fullscreen);
        ~GLFWWindow();

        void Update() const;
        void RequestClose() noexcept;
        [[nodiscard]] bool ShouldClose() const;

        [[nodiscard]] GLFWwindow* GetNative() const;

        [[nodiscard]] glm::vec2 GetSize() const;

        // -------------------------
        // ENGINE BINDING FUNCTIONS
        // -------------------------
        void SetMouseMoveCallback(MouseMoveCallbackFn cb);
        void SetMouseButtonCallback(MouseButtonCallbackFn cb);
        void SetKeyCallback(KeyCallbackFn cb);
        void SetResizeCallback(ResizeCallbackFn cb);

    private:
        GLFWwindow* m_window = nullptr;
        int m_width = 0;
        int m_height = 0;

        // -------------------------
        // CALLBACK STORAGE
        // -------------------------
        MouseMoveCallbackFn   m_mouseMoveCb;
        MouseButtonCallbackFn m_mouseButtonCb;
        KeyCallbackFn         m_keyCb;
        ResizeCallbackFn      m_resizeCb;


        static void FramebufferSizeCallback(GLFWwindow* window, int width, int height); // safe
        // -------------------------
        // GLFW STATIC CALLBACKS
        // -------------------------
        static void MouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


        // -------------------------
        // INSTANCE HANDLERS
        // -------------------------
        void OnMouseMove(float x, float y);
        void OnMouseButton(int button, int action, int mods);
        void OnKey(int key, int scancode, int action, int mods);
        void OnResize(int width, int height);
    };
}