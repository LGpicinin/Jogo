#pragma once
#include "ListaEntes.h"
#include "Plataforma.h"

class Mapa {
private:
	Lista<Plataforma> lista;
	sf::Vector2f inc;

public:
	Mapa();
	~Mapa();
	void inicializaAuto();
	Lista<Plataforma>* getLista();
	void reposMapa(float x, float y);
	void imprimir();
};