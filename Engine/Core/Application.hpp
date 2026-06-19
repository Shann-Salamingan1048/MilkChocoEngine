#pragma once

namespace MilkChoco
{
    class Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;

        void Run();
        void Stop();

    protected:
        virtual void OnInit() = 0;
        virtual void OnUpdate(float dt) = 0;
        virtual void OnShutDown() = 0;

    private:
        bool m_Running = false;
    };
}