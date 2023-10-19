#include <cmath>
#include <iostream>
#include <string.h>
#include "window.h"
#include "sdl.h"
#include "poligono.h"

using namespace std;

#define WIDTH 800
#define HEIGHT 800

bool keys[SDL_NUM_SCANCODES] = {false};  // Um array para rastrear o estado das teclas

int main(int argc, char *argv[])
{
    SDL sdl;
    bool quit = false;

    Poligono p{400, 400, 30, 30, {47, 4, 179, 255}};
    
    SDL_Event e;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    
    Window w(WIDTH, HEIGHT);
    // main loop
    while (!quit) 
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_KEYDOWN)
            {       
                if (e.key.keysym.sym == SDLK_LEFT)
                    p.translate(-10, 0,w);
                if (e.key.keysym.sym == SDLK_DOWN)
                    p.translate(0, +10,w);
                if (e.key.keysym.sym == SDLK_RIGHT)
                    p.translate(+10, 0, w);
                if (e.key.keysym.sym == SDLK_UP)
                    p.translate(0, -10, w);
                if (e.key.keysym.sym == SDLK_q)
                    quit = true;
            }
        }

        w.clear();

        p.draw(w);

        // Gera números aleatórios para dx e dy (entre -2 e 2)
        int dx = static_cast<int>(std::rand()) / RAND_MAX * 4 - 2;
        int dy = static_cast<int>(std::rand()) / RAND_MAX * 4 - 2;

        // Aplica a tradução aleatória
        // p.translate(dx, dy);

        w.update();
    }
    

    return 0;
}
