#include "Pedra.h"
#include <time.h>

Pedra::Pedra(float x, float y) : Inimigo(NULL, x, y) {
	srand(time(NULL));
	int opc = rand() % 2;
	//if (opc == 0) setTextura("Midia/Imagens/Pedra1.png");
	//else setTextura("Midia/Imagens/Pedra2.png");
	setPos(x, y);
	corpo.setPosition(x, y);

	corpo.setTextureRect(sf::IntRect(0, 0, 491, 338));
	if (opc == 0) if (!textura.loadFromFile("Midia/Imagens/Pedra1.jpg")) std::cout << "Erro na abertura da textura da pedra." << std::endl;
	else {
		corpo.setTexture(textura);
	}
	else if (!textura.loadFromFile("Midia/Imagens/Pedra2.jpg")) std::cout << "Erro na abertura da textura da pedra." << std::endl;
	else {
		corpo.setTexture(textura);
	}
	corpo.setScale(0.2, 0.2);
}

Pedra::~Pedra() {}

void Pedra::ataqueDir() {}

void Pedra::ataqueEsq() {}

void Pedra::viradoEsq() {}

void Pedra::viradoDir() {}