#include "Inimigo.h"
#include <iostream>

Inimigo::Inimigo(Jogador *j) :
Personagem(1, 103)
{
    jogador = j;
    //sf::Texture* textura = new sf::Texture;
    if(!textura.loadFromFile("Midia/Imagens/Inimigo.png", sf::IntRect(0, 0, 50, 50))) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        std::cout << "O inimigo eh vermelho." << std::endl;
        corpo.setTexture(textura);
        //corpo.setColor(sf::Color::Red);
        //corpo.setTextureRect(sf::IntRect(0, 0, 50, 50));
    }
}

Inimigo::~Inimigo()
{
    jogador = NULL;
}

void Inimigo::move()
{
    sf::Vector2f posiJogador, posiInimigo;

    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0)
    {
        vel.x = vel.x - 0.10;
        if(pos.x > 0)
        {
            pos.x = pos.x + vel.x;
        }
        vel.x = 0.0;

    }
    else if((posiJogador.x - pos.x)>0)
    {
        vel.x = vel.x + 0.10;
        if(pos.x < 640)
        {
            pos.x = pos.x + vel.x;
        }
        vel.x = 0.0;
    }
    corpo.setPosition(pos.x, pos.y);
}