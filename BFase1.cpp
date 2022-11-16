#include "BFase1.h"

BFase1::BFase1(Menu* m): Opcao() {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 2.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 160.0f));
}

BFase1::~BFase1() {}

void BFase1::atualiza() {
	if (sf::Mouse::getPosition().x >= getPos().x && sf::Mouse::getPosition().y >= getPos().y && sf::Mouse::getPosition().x <= getPos().x + getPos().x && sf::Mouse::getPosition().y <= getPos().y + getPos().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 2-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 2.png");
		setTextura(tex);
	}
}

void BFase1::executar() {
	if (pMenu->getFase1()) pMenu->~Menu();
	else {
		Fase1* f1 = new Fase1();
		pMenu->setFase1(f1);
	}
}