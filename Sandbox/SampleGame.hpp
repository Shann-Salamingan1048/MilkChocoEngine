#pragma once
#include <Core/Application.hpp>
namespace Game
{
    class SampleGame : MilkChoco::Application
    {
    public:
        explicit SampleGame(int width, int height, const char* title);


    private:
        void OnInit() override;
        void OnUpdate(float dt) override;
        void OnShutDown() override;
    };


}