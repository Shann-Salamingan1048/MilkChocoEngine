#include "Application.hpp"
#include "Time.hpp"

namespace MilkChoco
{
    void Application::Run()
    {
        Time::Init();   // START TIME HERE

        OnInit();

        while (!m_window->ShouldClose())
        {
            Time::Update();   // UPDATE EVERY FRAME

            float dt = Time::GetDeltaTime();
            OnUpdate(dt);
        }

        OnShutDown();
    }

    void Application::Stop()
    {
        m_window->RequestClose();
    }

    Application::Application(int width, int height, const char *title, bool fullscreen)
    {
        m_window = std::make_unique<GLFWWindow>(width, height, title, fullscreen);
    }
}
