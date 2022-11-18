#include "Inimigo.h"
#include <iostream>

Inimigo::Inimigo(Jogador *j, float x, float y) :
Personagem(1, 103, x, y)
{
    jogador = j;
    movAl = rand()%2;
    horaAtaque = true;
}

Inimigo::~Inimigo()
{
    jogador = NULL;
}

void Inimigo::move()
{
    sf::Vector2f posiJogador;

    posiJogador = jogador->getPos();

    if (abs(posiJogador.x - pos.x)<200 && horaAtaque == true)
    {
        ataque();
        atacar = true;
    }
    else if(abs(posiJogador.x - pos.x)<400)
    {
        persegueJogador();
        atacar = false;
    }
    else
    {
        movimentoAleatorio();
        atacar = false;
    }

    //cair();

    pos.y = pos.y + (vel.y * 7);

    corpo.setPosition(pos.x, pos.y);
    verifImg();

    vel.y = 0;
    vel.x = 0;

    float dt = relogio3.getElapsedTime().asSeconds();
    if(dt>=2)
    {
        relogio3.restart();
        horaAtaque = true;
    }
}

void Inimigo::persegueJogador()
{

    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 0.8; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 0.8; }
    
    pos.x = pos.x + vel.x;

}

void Inimigo::movimentoAleatorio()
{
    vel.x = 0;
    if(movAl==1)
    {
        vel.x = vel.x + 0.4;
    }
    else
    {
        vel.x = vel.x - 0.4;
    }
    pos.x = pos.x + vel.x;

    float dt = relogio.getElapsedTime().asSeconds();
    if(dt>=1)
    {
        relogio.restart();
        movAl = rand()%2;
    }

}

void Inimigo::ataque()
{
    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 0.8; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 0.8; }
    
    pos.x = pos.x + vel.x;

    float dt = relogio2.getElapsedTime().asSeconds();
    if(dt>=1.5)
    {
        relogio2.restart();
        horaAtaque = false;
    }
        
}