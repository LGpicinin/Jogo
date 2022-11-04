#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Jogo");
}

GerenciadorGrafico::~GerenciadorGrafico() {
	if (window) {
		delete window;
		window = NULL;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == NULL) {
		pGrafico =  new GerenciadorGrafico();
	}
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow() { return window;  }

void GerenciadorGrafico::limpaJanela() { window->clear(); }

void GerenciadorGrafico::desenhaElemento(Ente x) { window->draw(x.getCorpo()); }

void GerenciadorGrafico::mostraElementos() { window->display(); }

void GerenciadorGrafico::fecharJanela() { window->close(); }

const bool GerenciadorGrafico::verifJanelaAberta() {
	if (window->isOpen() == 1) return true;
	else return false;
}