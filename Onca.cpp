#include "Onca.h"

Onca::Onca(Jogador* j, float x, float y) :
Inimigo(j, x, y)
{
    dano = 1;
    numVidas = 2;
    corpo.setTextureRect(sf::IntRect(0, 0, 497, 337));
    if(!textura.loadFromFile("Midia/Imagens/Onca.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);
}

Onca::~Onca(){}