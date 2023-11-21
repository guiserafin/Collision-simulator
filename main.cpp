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
    Poligono c{200, 100, 45, 30, vx, vy, {200, 255, 0, 255}};
    
    SDL_Event e;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    int xMouse, yMouse;

    int frameTime;

    Window w(WIDTH, HEIGHT);

    bool mouseOver = false;
    bool segurando = false;

    while (!quit) 
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
                quit = true;
            
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }

            if (e.type == SDL_MOUSEMOTION){

                //Pegar a posição do mouse

                SDL_GetMouseState(&xMouse, &yMouse);

                if (xMouse <= (c.center_x + c.raio) && xMouse >= (c.center_x - c.raio) && yMouse <= (c.center_y + c.raio) && yMouse >= (c.center_y - c.raio)){
                    mouseOver = true;
                }
                else
                {
                    mouseOver = false;
                }
            }

            if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) && mouseOver){
                c.cor = {255,255,255,255};
                segurando = true;

                int xClique = xMouse;
                int yClique = yMouse;
            }
            else{
                c.cor = {255,0,0,255};

                if (segurando) {
                    c.setVelocidadeX(vx);
                    c.setVelocidadeY(vy);
                    segurando = false;
                }
            }
        }

        w.clear();

        // for (int i = 0; i<=1; i++){
        //     aCircle[i].draw(w);
        //     aCircle[i].translate(w,0);
        // }


        c.draw(w);

        c.translate(w, 0);
        // if (q.colide(&p))
        // {
            
        //     if (q.getDistancia(&p) > 0) {
        //         q.setX(q.getDistancia(&p));
        //         q.setY(q.getDistancia(&p));
        //     }

        //     // if (p.getDistancia(&q) > 0) {
        //     //     p.setX(p.getDistancia(&q));
        //     //     p.setY(p.getDistancia(&q));
        //     // }

        //     q.setVelocidadeX(0);
        //     q.setVelocidadeY(0);

        //     p.setVelocidadeX(0);
        //     q.setVelocidadeY(0);

        // }

        w.update();

        SDL_Delay( frameDelay );
        
    }
    

    return 0;
}
