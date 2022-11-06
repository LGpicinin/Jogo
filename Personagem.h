
#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    int numVidas;

public:
    Personagem(const int v, const int id);
    ~Personagem();
    virtual void move() = 0;

};
