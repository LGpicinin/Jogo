#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
    Jogador* jogador;
    int movAl;
    float dirEsq;
    sf::Clock relogio;

public:
    Inimigo(Jogador* j, float x, float y);
    ~Inimigo();
    void move();
    void persegueJogador();
    void movimentoAleatorio();
    virtual void ataque();

};