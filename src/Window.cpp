#include "./headers/Window.hpp"

namespace Raylib::Viewport
{
    Window::Window(const int width, const int height, const char *TITLE)
        : width(width), height(height), TITLE(TITLE)
    {
        Init();
    }

    void Window::Init()
    {
        InitWindow(this->width, this->height, this->TITLE);
        SetWindowState(this->VSYNC);
    }

    Window::~Window()
    {
    }
}