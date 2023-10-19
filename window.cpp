#include "window.h"
#include <iostream>
using namespace std;

Window::Window(int width, int height):
    width{width},
    height{height}
{
    // creating a sdl window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    if (window == NULL)
    {
        // the window was not created
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        // return error level 1 to operating system
        exit(1);
    }
    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
    cout << "~Window() called" << endl;
    //Destroy window
    SDL_DestroyWindow(window);
}

void Window::drawLine(int xi, int yi, int xf, int yf, SDL_Color color)
{
    //Draw blue horizontal line, RBGA - red, green, blue, alpha
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);		
    SDL_RenderDrawLine(renderer, xi, yi, xf, yf);
}

void Window::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}

void Window::update()
{
    //Update screen
    SDL_RenderPresent(renderer);

}
