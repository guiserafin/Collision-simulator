#include "vetor2.h"

Vetor2::Vetor2(float x, float y):
    x{x},
    y{y}
{}

Vetor2 Vetor2::somaVetor(Vetor2 v)
{
    float x_soma = v.x + x;
    float y_soma = v.y + y;

    Vetor2 resultado = Vetor2(x_soma, y_soma);
    return resultado;
}

Vetor2 Vetor2::subtraiVetor(Vetor2 v)
{
    float x_soma = v.x + x;
    float y_soma = v.y + y;

    Vetor2 resultado = Vetor2(x_soma, y_soma);
    return resultado;
}

void Vetor2::multiplicacaoEscalarVetor(float s)
{

}