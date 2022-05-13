#pragma once
#include "raylib.h"

namespace Raylib::Viewport
{
    class Window
    {
    private:
        const int width, height;
        const char *TITLE;
        const ConfigFlags VSYNC = FLAG_VSYNC_HINT;

    public:
        Window(const int width, const int height, const char *TITLE);
        void Init();
        ~Window();
    };
}