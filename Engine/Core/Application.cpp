#include "Application.hpp"
#include "Time.hpp"

namespace MilkChoco
{
    void Application::Run()
    {
        Time::Init();   // START TIME HERE

        OnInit();

        while (m_Running)
        {
            Time::Update();   // UPDATE EVERY FRAME

            float dt = Time::GetDeltaTime();
            OnUpdate(dt);
        }

        OnShutDown();
    }

    void Application::Stop()
    {
        m_Running = false;
    }
}
