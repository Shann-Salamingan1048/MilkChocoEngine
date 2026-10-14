//
// Created by shann on 6/19/26.
//

#include "SampleGame.hpp"
#include <Core/Time.hpp>

namespace Game
{
    SampleGame::SampleGame(int width, int height, const char *title)
        : Application(width, height, title)
    {
        MilkChoco::Time::Init();
    }

    void SampleGame::OnInit()
    {
        
    }
}
