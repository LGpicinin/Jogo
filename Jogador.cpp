#include "Jogador.h"
#include <iostream>

Jogador::Jogador() : Personagem(1, 101){
	pMapa = NULL;
	//sf::Texture* textura = new sf::Texture;
	if(!textura.loadFromFile("Midia/Imagens/Jogador.png", sf::IntRect(0, 0, 50, 50))) std::cout << "Erro na abertura da textura do jogador." << std::endl;
	else {
		std::cout << "O jogador eh azul." << std::endl;
		corpo.setTexture(textura);
		//corpo.setColor(sf::Color::Blue);
		//corpo.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
}

Jogador::~Jogador() {}

void Jogador::move() {
	cair();
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) if (pos.y > 0) pos.y = pos.y - vel.y;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) if (pos.y < 480) pos.y = pos.y + vel.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x = vel.x - 0.25;
		if (pos.x > 0) pos.x = pos.x + vel.x;
		vel.x = vel.x + 0.25;
		if (pMapa->getincx() - 0.25 >= 0 && pos.x <= 160) {
			pMapa->update(-0.25, 0);
		}
		/*else {
			vel.x = vel.x - 0.25;
			if (pos.x > 0) pos.x = pos.x + vel.x;
			vel.x = vel.x + 0.25;
		}*/
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x = vel.x + 0.25;
		if (pos.x < 640) pos.x = pos.x + vel.x;
		vel.x = vel.x - 0.25;
		if (pMapa->getincx() + 0.25 <= pMapa->getTileSheet().getSize().x && pos.x >= 480) {
			pMapa->update(0.25, 0.0);
		}
	}

	//cout << "(x, y) = (" << pos.x << ", " << pos.y << ")" << endl;
	corpo.setPosition(pos.x, pos.y);
}

void Jogador::pular() { vel.y = -1.33; pos.y = pos.y + vel.y; }

void Jogador::setMapa(Map* PM) { pMapa = PM; }