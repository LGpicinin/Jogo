#include "Inimigo.h"
#include <iostream>

Inimigo::Inimigo(Jogador *j, float x, float y) :
Personagem(1, 103, x, y)
{
    jogador = j;
    movAl = rand()%2;
}

Inimigo::~Inimigo()
{
    jogador = NULL;
}

void Inimigo::move()
{
    sf::Vector2f posiJogador, posiInimigo;

    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<210)
    {
        persegueJogador();
    }
    else
    {
        movimentoAleatorio();
    }

    //cair();

    pos.y = pos.y + vel.y;

    corpo.setPosition(pos.x, pos.y);

    verifImg();
}

void Inimigo::persegueJogador()
{

    sf::Vector2f posiJogador, posiInimigo;
    vel.x = 0.0;

    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0)
    {
        vel.x = vel.x - 0.15;
        if(pos.x > 0)
        {
            pos.x = pos.x + vel.x;
        }

    }
    else if((posiJogador.x - pos.x)>0)
    {
        vel.x = vel.x + 0.15;
        if(pos.x < 640)
        {
            pos.x = pos.x + vel.x;
        }
        
    }

}

void Inimigo::movimentoAleatorio()
{

    if(movAl==1)
    {
        vel.x = vel.x + 0.15;
        pos.x = pos.x + vel.x;
    }
    else
    {
        vel.x = vel.x - 0.15;
        pos.x = pos.x + vel.x;
    }
    vel.x = 0;

    float dt = relogio.getElapsedTime().asSeconds();
    if(dt>=1)
    {
        relogio.restart();
        movAl = rand()%2;
    }

}