#pragma once

namespace MilkChoco
{
    class Time
    {
    public:
        static void Init();
        static void Update();

        static float GetDeltaTime();

    private:
        static float s_DeltaTime;
    };
}