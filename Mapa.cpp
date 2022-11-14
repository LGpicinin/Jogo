#include "Mapa.h"
#include <iostream>

Mapa::Mapa() : lista(), colidiveis() {
	inc = sf::Vector2f(0.0f, 0.0f);
	//inicializaAuto();
	//std::cout << "inicializaAuto executada.\n";
}

Mapa::~Mapa() {
	lista.~Lista();
	colidiveis.~Lista();
}

Mapa::Mapa(sf::Vector2f ini, sf::Vector2f fim) : lista() {
	inc = sf::Vector2f(0.0f, 0.0f);
	inicializaAuto(ini, fim);
}

void Mapa::inicializaAuto(sf:: Vector2f ini, sf::Vector2f fim) {
	bool chk = 0;
	for (float i = ini.x; i <= fim.x; i = i + 32) {
		chk = 0;
		for (float j = ini.y; j <= fim.y; j = j + 32) {
			Plataforma* p = new Plataforma(sf::Vector2f(i, j));
			if (p->getNula() == false) {
				chk = 1;
				cout << "Item adicionado a lista.\n";
				//p->setGerente(graf);
				lista.incluirEl(p);
				if (p->verifNula(sf::Vector2f(i + 32, j)) || p->verifNula(sf::Vector2f(i - 32, j)) ||
p->verifNula(sf::Vector2f(i, j + 32)) || p->verifNula(sf::Vector2f(i, j - 32))) colidiveis.incluirEl(p);
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

Lista<Plataforma>* Mapa::getColidiveis() { return &colidiveis; }