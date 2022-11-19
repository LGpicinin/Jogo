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
    GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
    if (pos.x > graf->getCoorView().x + 320 || pos.x < graf->getCoorView().x - 320 || pos.y > graf->getCoorView().y + 240 || pos.y < graf->getCoorView().y - 240) {
        congela();
    }
    else {
        sf::Vector2f posiJogador;

            posiJogador = jogador->getPos();

            if (abs(posiJogador.x - pos.x)<200)
            {
                ataque();
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

            if (abs(posiJogador.x - pos.x)<200) { atacar = true; }

            //cair();

            pos.y = pos.y + (vel.y * 2);
            pos.x = pos.x + vel.x;

            corpo.setPosition(pos.x, pos.y);
            verifImg();

            vel.x = 0;

            float dt = relogio3.getElapsedTime().asSeconds();
            if(dt>=2)
            {
                relogio3.restart();
                horaAtaque = true;
            }
        }
    
}

void Inimigo::persegueJogador()
{

    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 0.8; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 0.8; }
    

}

void Inimigo::movimentoAleatorio()
{
    if(movAl==1)
    {
        vel.x = vel.x + 0.4;
    }
    else
    {
        vel.x = vel.x - 0.4;
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
    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 1.5; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 1.5; }


    float dt = relogio2.getElapsedTime().asSeconds();
    if(dt>=1.5)
    {
        relogio2.restart();
        horaAtaque = false;
    }
        
}

void Inimigo::congela() {
    setVelX(0.0f);
    setVelY(-0.3f);
    cair();
}