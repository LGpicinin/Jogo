#include "Resumir.h"
#include <iostream>
using namespace std;

Resumir::Resumir(Menu* m) : Opcao() {
	pMenu = m;
	//sf::Texture tex;
	//tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
	//setTextura(tex);
	//setTextura("Midia/Imagens/Menu Opc 1a.png");
	if(!textura.loadFromFile("Midia/Imagens/Menu Opc 1a.png")) cout << "Erro na abertura da imagem";
	float x = GerenciadorGrafico::getGerenciadorGrafico()->getCoorView().x - 160;
	float y = GerenciadorGrafico::getGerenciadorGrafico()->getCoorView().y - 160;
	setPos(sf::Vector2f(x, y));
	corpo.setPosition(sf::Vector2f(x, y));
	cout << "Resumir criado.\npos.x = " << getPos().x << "\npos.y = " << getPos().y << endl;

	m->setResumir(this);
}

Resumir::~Resumir() {}

void Resumir::executar() {
	//pMenu->~Menu();
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pMenu->getFase1()) {
		pMenu->getFase1()->getJogador1()->setVidas(3);
		graf->setView(sf::Vector2f(pMenu->getFase1()->getJogador1()->getPos().x, pMenu->getFase1()->getJogador1()->getPos().y));
		pMenu->getFase1()->getMusica()->play();
	}
	else if (pMenu->getFase2()) {
		pMenu->getFase2()->getJogador1()->setVidas(3);
		graf->setView(sf::Vector2f(pMenu->getFase2()->getJogador1()->getPos().x, pMenu->getFase2()->getJogador1()->getPos().y));
		pMenu->getFase2()->getMusica()->play();
	}
}

void Resumir::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	cout << "Posicao do mouse:\npos.x = " << sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x << "\npos.y = " << sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y << endl;
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		cout << "Mouse na opcao Resumir.\n";
		selecionada = true;
		textura.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
		setTextura(tex);
	}
}