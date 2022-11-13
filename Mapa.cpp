#include "Mapa.h"
#include <iostream>

Mapa::Mapa() : lista() {
	inc = sf::Vector2f(0.0f, 0.0f);
	inicializaAuto();
	std::cout << "inicializaAuto executada.\n";
}

Mapa::~Mapa() {

}

void Mapa::inicializaAuto() {
	bool chk = 0;
	for (float i = 0; i <= 3968; i = i + 32) {
		chk = 0;
		for (float j = 320.0f; j <= 1088; j = j + 32) {
			Plataforma* p = new Plataforma(sf::Vector2f(i, j));
			if (p->getNula() == false) {
				chk = 1;
				cout << "Item adicionado a lista.\n";
				//p->setGerente(graf);
				lista.incluirEl(p);
			}
			else if (chk == 1) break;
		}
	}
}

Lista<Plataforma>* Mapa::getLista() { return &lista; }

void Mapa::reposMapa(float x, float y) {
	Elemento<Plataforma>* it = lista.getPrimeiro();
	while (it != NULL) {
		it->getInfo()->repos(-x, -y);
		it = it->getProximo();
	}
}

void Mapa::imprimir() {
	Elemento<Plataforma>* it = lista.getPrimeiro();
	while (it != NULL) {
		it->getInfo()->imprimir();
		it = it->getProximo();
	}
}