class Vetor2 
{
    float x;
    float y;

    public:
        Vetor2(float x, float y);

        inline float getX(){ return x; }
        inline float getY(){ return y; }

        Vetor2 somaVetor(Vetor2 v);
        Vetor2 subtraiVetor(Vetor2 v);
        void multiplicacaoEscalarVetor(float s);

};