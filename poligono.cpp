#include "poligono.h"
#include "math.h"
#include <iostream>

Poligono::Poligono(int x, int y, int raio, int lados, int vx, int vy, SDL_Color cor) :
    lados{lados},
    center_x{x},
    center_y{y},
    raio{raio},
    cor{cor},
    velocidadeX{vx},
    velocidadeY{vy},
    aceleracao{0}
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

void Poligono::translate(Window &w, int dt) {

    center_x += velocidadeX * 1; //dt
    center_y += velocidadeY * 1; //dt


    //Ifs server para limitar ao tamanho da janela / bater com o limite
    if (center_x - raio < 0 || center_x + raio > w.width) {
        // Inverta a velocidade no eixo X para simular a reflexão na parede
        velocidadeX *= -1;
    }
    
    // Verifique a colisão com as paredes superior e inferior
    if (center_y - raio < 0 || center_y + raio > w.height) {
        // Inverta a velocidade no eixo Y para simular a reflexão na parede
        velocidadeY *= -1;
    }
}

bool Poligono::colide(Poligono &p)
{
    float delta_x = center_x - p.center_x;
    float delta_y = center_y - p.center_y;

    float distancia = sqrt(delta_x * delta_x + delta_y * delta_y);

    return distancia <= (p.raio + raio);
}


void Poligono::setVelocidadeX(double v){
    velocidadeX *= -1;
}
void Poligono::setVelocidadeY(double v){
    velocidadeY *= -1;
}