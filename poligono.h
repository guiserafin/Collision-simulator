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

        Poligono(int x, int y, int raio, int lados,SDL_Color cor);
        void draw(Window &w);
        void translate(int x, int y, Window &w);
        bool colide(Poligono p);
    private:
        double aceleracao;
        double velocidade;
};

#endif
