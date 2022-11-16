#include "Sair.h"

Sair::Sair(Menu* m): Opcao() {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 5.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 400.0f));
}

Sair::~Sair() {}

void Sair::atualiza() {
	if (sf::Mouse::getPosition().x >= getPos().x && sf::Mouse::getPosition().y >= getPos().y && sf::Mouse::getPosition().x <= getPos().x + getPos().x && sf::Mouse::getPosition().y <= getPos().y + getPos().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 5-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 5.png");
		setTextura(tex);
	}
}

void Sair::executar() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	graf->fecharJanela();
}