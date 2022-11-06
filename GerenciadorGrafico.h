#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>

class GerenciadorGrafico {
private:
	sf::RenderWindow* window;
	static GerenciadorGrafico* pGrafico;
	GerenciadorGrafico();

public:
	~GerenciadorGrafico();
	static GerenciadorGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();
	void limpaJanela();
	void desenhaElemento(sf::Sprite corpo);
	void mostraElementos();
	void fecharJanela();
	const bool verifJanelaAberta();
};