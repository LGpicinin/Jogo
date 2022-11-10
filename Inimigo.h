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
    Inimigo(Jogador* j);
    ~Inimigo();
    void move();
    void persegueJogador();
    void movimentoAleatorio();

};