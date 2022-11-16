#include "Opcao.h"

Opcao::Opcao(): Ente(sf::Vector2f(0, 0)) {
	selecionada = false;
}

Opcao::Opcao(sf::Vector2f ini): Ente(ini) {
	selecionada = false;
}

Opcao::~Opcao() {}

void Opcao::setSelecionada(bool sel) { selecionada = sel; }

const bool Opcao::getSelecionada() { return selecionada; }

void Opcao::atualiza() {
	/*if (sf::Mouse::getPosition().x >= getPos().x && sf::Mouse::getPosition().y >= getPos().y && sf::Mouse::getPosition().x <= getPos().x + getPos().x && sf::Mouse::getPosition().y <= getPos().y + getPos().y) {
		selecionada = true;
	}
	else selecionada = false;*/
}

void Opcao::executar() {}