#include "Time.hpp"
#include <chrono>

namespace MilkChoco
{
    static std::chrono::high_resolution_clock::time_point s_LastFrame;

    float Time::s_DeltaTime = 0.0f;

    void Time::Init()
    {
        s_LastFrame = std::chrono::high_resolution_clock::now();
        s_DeltaTime = 0.0f;
    }

    void Time::Update()
    {
        using namespace std::chrono;

        auto now = high_resolution_clock::now();
        duration<float> diff = now - s_LastFrame;

        s_DeltaTime = diff.count();
        s_LastFrame = now;
    }

    float Time::GetDeltaTime()
    {
        return s_DeltaTime;
    }
}