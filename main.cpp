#include <cmath>
#include <iostream>
#include <string.h>
#include <ctime>
#include "window.h"
#include "sdl.h"
#include "poligono.h"

using namespace std;

#define WIDTH 800
#define HEIGHT 800

int main(int argc, char *argv[])
{
    //Gera seed pseudo-aleatoria para a velocidade aletoria dos circulos
    srand(time(NULL));

    SDL sdl;
    bool quit = false;

    // Gera números aleatórios para vx e vy (velocidade X e velocidadeY) entre -10 e 10 
    int vx = (rand() % 10) - 10;
    int vy = (rand() % 10) - 10;

    Poligono p{400, 400, 30, 30, vx, vy, {47, 4, 179, 255}};


    int vxq = (rand() % 10) - 10;
    int vyq = (rand() % 10) - 10;
    Poligono q{200, 100, 30, 30, vxq, vyq, {30, 200, 200, 255}};
    
    SDL_Event e;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    
    Window w(WIDTH, HEIGHT);
    // main loop
    int tempo = 0;
    while (!quit) 
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
                quit = true;
            
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
            /* PARTE DA MOVIMENTAÇÃO QUE IREI REMOVER QUANDO A MOVIMENTAÇÃO ESTIVER "AUTOMATICA"
            {       
                switch( e.key.keysym.sym ) 
                {
                    case SDLK_q: p.setVelocidadeY(5); break;
                    case SDLK_DOWN: p.setVelocidadeY(-5); break;
                    case SDLK_LEFT: p.setVelocidadeX(-5); break;
                    case SDLK_RIGHT: p.setVelocidadeX(5); break;
                    case SDLK_q: quit = true; break;
                }
            }
            */
        }

        w.clear();

        p.draw(w);
        q.draw(w);

        // Aplica a translação aleatória
        tempo++;
        
        if (!q.colide(p))
        {
            p.translate(w, tempo);
            q.translate(w, tempo);
            // q.setVelocidadeX(0);
            // q.setVelocidadeY(0);

            // p.setVelocidadeX(0);
            // q.setVelocidadeY(0);

        }

        w.update();

        SDL_Delay( frameDelay );

        
    }
    

    return 0;
}
