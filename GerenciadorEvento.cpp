#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEvento = NULL;

GerenciadorEvento::GerenciadorEvento() {
	pJogador = NULL;
}

GerenciadorEvento::~GerenciadorEvento() {
	delete pEvento;
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
	if (pEvento == NULL) {
		pEvento = new GerenciadorEvento();
	}
	return pEvento;
}

void GerenciadorEvento::setPGraf(GerenciadorGrafico* p) { pGraf = p; }

void GerenciadorEvento::setJogador(Jogador* p) { pJogador = p; }

void GerenciadorEvento::verifTeclaPressionada(sf::Keyboard::Key tecla) {
	if (tecla == sf::Keyboard::A) {
		pJogador->setVelX(-0.5);
		//pJogador->atualizaPos();
	}
	else if (tecla == sf::Keyboard::D) {
		pJogador->setVelX(0.5);
		//pJogador->atualizaPos();
	}
	if (tecla == sf::Keyboard::Space) {
		pJogador->pular();
		//pJogador->atualizaPos();
	}
	else if (tecla == sf::Keyboard::Escape) {
		pGraf->fecharJanela();
	}
}

void GerenciadorEvento::verifTeclaSolta(sf::Keyboard::Key tecla) {
	if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D) {
		pJogador->parar();
	}
}

void GerenciadorEvento::executar() {
	sf::Event evento;
	while (pGraf->getWindow()->pollEvent(evento)) {
		if (evento.type == sf::Event::KeyPressed) verifTeclaPressionada(evento.key.code);
		else if (evento.type == sf::Event::KeyReleased) verifTeclaSolta(evento.key.code);
		else if (evento.type == sf::Event::Closed) pGraf->fecharJanela();
	}
}