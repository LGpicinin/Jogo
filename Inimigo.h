#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
    Jogador* jogador;
    int movAl;
    bool horaAtaque;
    sf::Clock relogio, relogio2, relogio3;

public:
    Inimigo(Jogador* j, float x, float y);
    ~Inimigo();
    void move();
    void persegueJogador();
    void movimentoAleatorio();
    virtual void ataque();

};