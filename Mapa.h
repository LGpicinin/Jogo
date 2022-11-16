#pragma once
#include "ListaEntes.h"
#include "Plataforma.h"

class Mapa {
private:
	Lista<Plataforma> lista;
	Lista<Plataforma> colidiveis;

public:
	Mapa();
	Mapa(sf::Vector2f ini, sf::Vector2f fim);
	~Mapa();
	void inicializaAuto(sf::Vector2f ini, sf::Vector2f fim);
	Lista<Plataforma>* getLista();
	void reposMapa(float x, float y);
	void imprimir();
	Lista<Plataforma>* getColidiveis();
};