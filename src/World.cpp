#include <iostream>
#include "./headers/World.hpp"
#include "./headers/Player.hpp"
#include "./headers/Platform.hpp"
#include "./headers/Window.hpp"

namespace Raylib::World
{
    int Game::Run(int exitCode)
    {
        const int WIDTH{700}, HEIGHT{450};
        const char *TITLE{"GAME"};
        const Viewport::Window window = Viewport::Window(WIDTH, HEIGHT, TITLE);

        const Vector2 pos{WIDTH / 2, HEIGHT - 25};
        const Vector2 size{25, 25};
        const Vector2 vel{0, 0};
        const int MOVE_SPEED{300};
        const int JUMP_FORCE{1250};
        Player *player = new Player(pos, size, vel, MOVE_SPEED, JUMP_FORCE, false);

        DrawGame(player);
        delete player;
        CloseWindow();
        return exitCode;
    }

    void Game::DrawGame(Player *player)
    {
        Platform *platform = new Platform(Vector2{(float)0, (float)GetScreenHeight() - 25}, Vector2{50, 25});
        Platform *platform2 = new Platform(Vector2{(float)GetScreenWidth() - 50, (float)GetScreenHeight() - 25}, Vector2{50, 25});

        std::vector<Platform> gameObjects;
        gameObjects.push_back(*platform);
        gameObjects.push_back(*platform2);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(GRAY);
            Platform::DrawFromVector(gameObjects);
            player->Update();
            player->CheckForCollision(player, gameObjects);
            EndDrawing();
        }

        delete player;
        delete platform;
        delete platform2;
    }
} // namespace Raylib::World
