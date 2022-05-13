#pragma once
#include "./Player.hpp"

using namespace Raylib::Actors;

namespace Raylib::World
{
    typedef struct Game
    {
        static int Run(int exitCode);
        static void DrawGame(Player *player);
    } Game;
} // namespace Raylib::World