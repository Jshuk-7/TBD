#pragma once
#include <vector>
#include "raylib.h"

namespace Raylib::GameObject
{
    class Platform
    {
    public:
        Vector2 pos, size;

    public:
        Platform(Vector2 pos, Vector2 size);
        ~Platform();
        Rectangle ToRect();
        void Draw();
        static void AddToVector(std::vector<Platform> *gameObjects, unsigned int num, ...);
        static void RemoveFromVector(std::vector<Platform> *gameObjects);
        static void DrawFromVector(std::vector<Platform> gameObjects);
    };
} // namespace Raylib::GameObject
