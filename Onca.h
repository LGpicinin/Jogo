#pragma once
#include "Inimigo.h"

class Onca: public Inimigo
{
    public:
        Onca(Jogador* j, float x, float y);
        ~Onca();

};