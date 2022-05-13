#include <iostream>
#include "./headers/Player.hpp"

namespace Raylib::Actors
{
    Player::Player(Vector2 pos, Vector2 size, Vector2 vel, int MOVE_SPEED, int JUMP_FORCE, bool grounded)
        : pos(pos), size(size), vel(vel), MOVE_SPEED(MOVE_SPEED), JUMP_FORCE(JUMP_FORCE), grounded(grounded)
    {
    }

    Player::~Player()
    {
    }

    void Player::Update()
    {
        this->Draw();
        this->ApplyPhysics();
        this->ProcessInput();
        this->SetBoundary();
        this->ToggleGrounded();
    }

    Rectangle Player::ToRect()
    {
        return Rectangle{this->pos.x - this->size.x / 2, this->pos.y - this->size.y / 2, this->size.x, this->size.y};
    }

    void Player::CheckForCollision(Player *player, std::vector<Platform> gameObjects)
    {
        for (unsigned int i = 0; i < gameObjects.size(); i++)
        {
            if (CheckCollisionRecs(player->ToRect(), gameObjects[i].ToRect()))
            {
                std::cout << "COLLISION: Hit Box\n";
                if (player->LandedOnPlatform(gameObjects[i]))
                {
                    // TODO
                }
            }
        }
    }

    bool Player::LandedOnPlatform(Platform platform)
    {
        if (this->pos.x)
        {
            // TODO
        }
    }

    void Player::Draw()
    {
        DrawRectangleRec(this->ToRect(), WHITE);
    }

    void Player::ApplyPhysics()
    {
        this->pos.x += this->vel.x;
        this->pos.y += this->vel.y;
        this->vel.y += 10 * GRAVITY * GetFrameTime();
    }

    void Player::ApplyFriction()
    {
        this->vel.x /= FRICTION;
        this->vel.y /= FRICTION;
    }

    void Player::ProcessInput()
    {
        if (IsKeyDown(KEY_A) && this->pos.x > 0 + this->size.x / 2)
            this->vel.x -= this->MOVE_SPEED * GetFrameTime();
        if (IsKeyDown(KEY_D) && this->pos.x < GetScreenWidth() - this->size.x / 2)
            this->vel.x += this->MOVE_SPEED * GetFrameTime();

        if (!IsKeyDown(KEY_A) || !IsKeyDown(KEY_D) || (IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) || IsKeyPressed(KEY_SPACE))
        {
            this->ApplyFriction();
            if (IsKeyPressed(KEY_SPACE) && grounded)
            {
                this->grounded = false;
                this->ProcessJump();
            }
        }
    }

    void Player::ProcessJump()
    {
        this->vel.y -= IsKeyPressed(KEY_SPACE) ? 10 * JUMP_FORCE * GetFrameTime() : 0;
        this->ApplyFriction();
    }

    void Player::ToggleGrounded()
    {
        if (this->pos.y == GetScreenHeight() - this->size.y / 2)
            this->grounded = true;
    }

    void Player::SetBoundary()
    {
        if (this->pos.x < 0 + this->size.x / 2) // Left side
            this->pos.x = 0 + this->size.x / 2;
        if (this->pos.x > GetScreenWidth() - this->size.x / 2) // Right side
            this->pos.x = GetScreenWidth() - this->size.x / 2;
        if (this->pos.y < 0 + this->size.y / 2) // Top side
            this->pos.y = 0 + this->size.y / 2;
        if (this->pos.y > GetScreenHeight() - this->size.y / 2) // Bottom side
            this->pos.y = GetScreenHeight() - this->size.x / 2;
    }
}