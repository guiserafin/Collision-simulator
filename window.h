#ifndef J1_WINDOW_H
#define J1_WINDOW_H

#include <SDL2/SDL.h>

class Window 
{
    protected:
        int width;
        int height;
        SDL_Window * window;
        SDL_Surface * screenSurface;
        SDL_Renderer * renderer = NULL;

    public:
        Window(int width, int height);
        ~Window();      
        
        void drawLine(int xi, int yi, int xf, int yf, SDL_Color color = {255, 255, 255, 255});
        void clear();
        void update();

        friend class Poligono;
};

#endif
