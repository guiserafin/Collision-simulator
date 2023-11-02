#ifndef J1_POLIGONO_H
#define J1_POLIGONO_H

#include "window.h"


class Poligono {

    public:
        int lados;
        int center_x;
        int center_y;
        int raio;
        SDL_Color cor;

        Poligono(int x, int y, int raio, int lados, int vx, int vy, SDL_Color cor);
        void draw(Window &w);
        void translate(Window &w, int dt);
        bool colide(Poligono &p);
        void setVelocidadeX(double variacao);
        void setVelocidadeY(double variacao);
    private:
        double aceleracao;
        double velocidadeX;
        double velocidadeY;
};

#endif
