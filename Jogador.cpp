#include "Jogador.h"
#include <iostream>

Jogador::Jogador() : Personagem(1, 101, 50, 50){
	pMapa = NULL;
	pMapa2 = NULL;
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
	std::cout << "vel.y = " << vel.y << std::endl;
	std::cout << "pos.y = " << pos.y << std::endl;

	//if (pos.y < 430 && pos.y > 0) pos.y = pos.y + vel.y;
	
	if (gerente->getCoorView().x >= 320 && gerente->getCoorView().y >= 240 && (pos.x <= gerente->getCoorView().x - 100 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||
(pMapa->getincx() + vel.x <= pMapa->getTextura().getSize().x && pos.x >= gerente->getCoorView().x + 100 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		//pMapa->update(vel.x, 0);
		//pMapa2->reposMapa(vel.x, 0);
		//std::cout << "reposMapa foi chamada com vel.x = " << vel.x << std::endl;
		//pos.x -= vel.x;
		gerente->setView(sf::Vector2f(gerente->getCoorView().x + vel.x, gerente->getCoorView().y));
	}
	//else
	//{
		pos.x = pos.x + vel.x;
	//}
	if ((pos.y >= gerente->getCoorView().y + 240 - getTam().y - 64 && vel.y > 0) || (pos.y <= gerente->getCoorView().y - 176 && vel.y < 0)) {
		//pMapa2->reposMapa(0, 2 * vel.y);
		gerente->setView(sf::Vector2f(gerente->getCoorView().x, gerente->getCoorView().y + vel.y));
		//pos.y -= vel.y;
	}
	pos.y = pos.y + vel.y;
	gerente->getWindow()->setView(*(gerente->getView()));
	
	//else pos.y += vel.y;

	corpo.setPosition(pos.x, pos.y);
	
}

void Jogador::moveEsq() {
	vel.x = -0.5;
}

void Jogador::parar() {
	vel.x = 0;
}

void Jogador::pular() { vel.y = -10; }

void Jogador::setMapa(Map* PM) { pMapa = PM; }