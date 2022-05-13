#include <stdarg.h>
#include "./headers/Platform.hpp"

namespace Raylib::GameObject
{
    Platform::Platform(Vector2 pos, Vector2 size)
        : pos(pos), size(size)
    {
    }

    Platform::~Platform()
    {
    }

    Rectangle Platform::ToRect()
    {
        return Rectangle{this->pos.x, this->pos.y, this->size.x, this->size.y};
    }

    void Platform::Draw()
    {
        DrawRectangleRec(this->ToRect(), BLACK);
    }

    void Platform::DrawFromVector(std::vector<Platform> gameObjects)
    {
        for (unsigned int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i].Draw();
        }
    }
}