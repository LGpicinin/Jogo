#include "Resumir.h"

Resumir::Resumir(Menu* m) : Opcao() {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 80.0f));
}

Resumir::~Resumir() {}

void Resumir::executar() {
	pMenu->~Menu();
}

void Resumir::atualiza() {
	if (sf::Mouse::getPosition().x >= getPos().x && sf::Mouse::getPosition().y >= getPos().y && sf::Mouse::getPosition().x <= getPos().x + getPos().x && sf::Mouse::getPosition().y <= getPos().y + getPos().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
		setTextura(tex);
	}
}