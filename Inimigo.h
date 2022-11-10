#pragma once
#include "Personagem.h"
#include "Entidade.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
    Jogador* jogador;
    int movAl;
    sf::Clock relogio;

public:
    Inimigo(Jogador* j, float x, float y);
    ~Inimigo();
    void move();
    void persegueJogador();
    void movimentoAleatorio();

};