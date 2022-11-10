#include "Jogador.h"
#include <iostream>

Jogador::Jogador() : Personagem(1, 101, 50, 50){
	pMapa = NULL;
	//sf::Texture* textura = new sf::Texture;
	corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
	if(!textura.loadFromFile("Midia/Imagens/Parado.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
	corpo.setScale(sf::Vector2f(0.2f, 0.2f));
	/*else {
		std::cout << "O jogador eh azul." << std::endl;
		corpo.setTexture(textura);
		//corpo.setColor(sf::Color::Blue);
		//corpo.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}*/
}

Jogador::~Jogador() {}

void Jogador::move() {
	atualizaPos();
}

void Jogador::moveDir() {
	vel.x = 0.5;
}

void Jogador::atualizaPos() {
	//if (pos.x < 640 && pos.x > 0) {
	//}
	std::cout << "Nova pos.x: " << pos.x << std::endl;

	if (pos.y < 430 && pos.y > 0) pos.y = pos.y + vel.y;
	if ((pMapa->getincx() + vel.x >= 0 && pos.x <= 290 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||
(pMapa->getincx() + vel.x <= pMapa->getTextura().getSize().x && pos.x >= 310 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		pMapa->update(vel.x, 0);
		//pos.x -= vel.x;
	}
	else
	{
		pos.x = pos.x + vel.x;
	}
	
	pos.y += vel.y;

	corpo.setPosition(pos.x, pos.y);
}

void Jogador::moveEsq() {
	vel.x = -0.5;
}

void Jogador::parar() {
	vel.x = 0;
}

void Jogador::pular() { vel.y = -1.33; }

void Jogador::setMapa(Map* PM) { pMapa = PM; }