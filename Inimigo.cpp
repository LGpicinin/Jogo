#include "Inimigo.h"
#include <iostream>

Inimigo::Inimigo(Jogador *j, float x, float y) :
Personagem(1, 103, x, y)
{
    jogador = j;
    movAl = rand()%2;
    dirEsq = 1;
}

Inimigo::~Inimigo()
{
    jogador = NULL;
}

void Inimigo::move()
{
    sf::Vector2f posiJogador, posiInimigo;

    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  dirEsq = -1; }

    else if((posiJogador.x - pos.x)>0) { dirEsq = 1; }

    /*if (abs(posiJogador.x - pos.x)<200)
    {
        ataque();
        atacar = true;
    }*/
    if(abs(posiJogador.x - pos.x)<500)
    {
        persegueJogador();
        atacar = true;
    }
    else
    {
        movimentoAleatorio();
        atacar = false;
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

    
    vel.x = vel.x + (0.15*dirEsq);
    if(pos.x > 0 && pos.x < 640)
    {
        pos.x = pos.x + vel.x;
    }

}

void Inimigo::movimentoAleatorio()
{
    vel.x = 0;
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

    float dt = relogio.getElapsedTime().asSeconds();
    if(dt>=1)
    {
        relogio.restart();
        movAl = rand()%2;
    }

}

void Inimigo::ataque()
{
    vel.x = 0.0;

    
    vel.x = vel.x + (0.3*dirEsq);
    if(pos.x > 0 && pos.x < 640)
    {
        pos.x = pos.x + vel.x;
    }
        
}