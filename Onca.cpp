#include "Onca.h"

Onca::Onca(Jogador* j) :
Inimigo(j)
{
    dano = 1;
    numVidas = 2;
    if(!textura.loadFromFile("Midia/Imagens/Onca.png", sf::IntRect(0, 0, 50, 50))) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }

}

Onca::~Onca(){}