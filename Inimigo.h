#pragma once
#include "Personagem.h"
#include "Entidade.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
    Jogador* jogador;

public:
    Inimigo(Jogador* j);
    ~Inimigo();
    void move();

};