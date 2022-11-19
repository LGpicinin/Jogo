#pragma once
#include "Inimigo.h"

class Onca: public Inimigo
{
    private:
        bool agressividade;
    public:
        Onca(Jogador* j, float x, float y);
        ~Onca();
        void viradoEsq();
        void viradoDir();
        void ataqueDir();
        void ataqueEsq();
        void ataque();
        void calculaAgressividade();

};