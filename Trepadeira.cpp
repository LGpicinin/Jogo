#include "Trepadeira.h"

using namespace Entidades;

Trepadeira::Trepadeira(float x, float y): Obstaculo(x,y)
{
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 512));
    if (!textura.loadFromFile("Midia/Imagens/Trepadeira.png")) std::cout << "Erro na abertura da textura da pedra." << std::endl;
	else {
		corpo.setTexture(textura);
	}
    corpo.setScale(0.2, 0.2);
    
}

Trepadeira::~Trepadeira() {}