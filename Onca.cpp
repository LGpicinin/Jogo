#include "Onca.h"

Onca::Onca(Jogador* j) :
Inimigo(j)
{
    dano = 1;
    numVidas = 2;
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 512));
    if(!textura.loadFromFile("Midia/Imagens/Onca.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.15, 0.15);
}

Onca::~Onca(){}