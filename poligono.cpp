#include "poligono.h"
#include "math.h"

Poligono::Poligono(int x, int y, int raio, int lados,SDL_Color cor) :
    lados{lados},
    center_x{x},
    center_y{y},
    raio{raio},
    cor{cor}
{}

void Poligono::draw(Window &w) {

    //ultimo X e Y
    //Como começa em 0, cos(0) = 1, sen(0) = 1;

    double angulo = 2* M_PI/lados;

    int last_x = center_x + raio * cos(0);
    int last_y = center_y + raio * sin(0);


    for (double i = 0; i <= lados; i++) {
        
        double novo_x = center_x + raio * cos(angulo * i);
        double novo_y = center_y + raio * sin(angulo * i);

        w.drawLine(last_x, last_y, novo_x, novo_y, cor);

        last_x = novo_x;
        last_y = novo_y;

    }

}

void Poligono::translate(int x, int y, Window &w) {

    //Ifs server para limitar ao tamanho da janela
    if (center_x + raio + x < w.width && center_x - raio + x > 0){
        center_x += x;
    }

    if (center_y + raio + y < w.height && center_y - raio + y > 0){
        center_y += y;
    }
}

bool Poligono::colide(Poligono p)
{
    if ( 
        p.center_x + center_x <= p.raio + raio ||
        p.center_y + center_y <= p.raio + raio 
    ) {
        return true;
    }

    return false;
}