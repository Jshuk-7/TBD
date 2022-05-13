#pragma once
#include <vector>
#include "raylib.h"
#include "./Platform.hpp"

#define FRICTION 2
#define GRAVITY 100

using namespace Raylib::GameObject;

namespace Raylib::Actors
{
    class Player
    {
    public:
        Vector2 pos;

    private:
        Vector2 size, vel;
        const int MOVE_SPEED, JUMP_FORCE;
        bool grounded;

    public:
        Player(Vector2 pos, Vector2 size, Vector2 vel, int MOVE_SPEED, int JUMP_FORCE, bool grounded);
        ~Player();
        void Update();
        Rectangle ToRect();
        void CheckForCollision(Player *player, std::vector<Platform> gameObjects);

    private:
        bool LandedOnPlatform(Platform platform);
        void Draw();
        void ApplyPhysics();
        void ApplyFriction();
        void ProcessInput();
        void ProcessJump();
        void ToggleGrounded();
        void SetBoundary();
    };
}