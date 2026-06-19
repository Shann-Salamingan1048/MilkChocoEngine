#pragma once
#include <Platform/Window/GLFWWindow.hpp>
#include <memory>
namespace MilkChoco
{
    class GLFWWindow;
    class Application
    {
    public:
        explicit Application(int width, int height, const char* title, bool fullscreen);
        virtual ~Application() = default;

        void Run();
        void Stop();

    protected:
        virtual void OnInit() = 0;
        virtual void OnUpdate(float dt) = 0;
        virtual void OnShutDown() = 0;

    private:
        std::unique_ptr<GLFWWindow> m_window;
    };
}