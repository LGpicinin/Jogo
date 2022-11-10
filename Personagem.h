
#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    int numVidas;
    int dano;

public:
    Personagem(const int v, const int id);
    ~Personagem();
    virtual void move() = 0;

};
