
#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    int numVidas;
    int dano;

public:
    Personagem(const int v, const int id, float x, float y);
    ~Personagem();
    virtual void move() = 0;
    int getVidas(){ return numVidas; }

};
