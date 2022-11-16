#pragma once
#include "Ente.h"
#include <string>
using namespace std;
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"

class Opcao : public Ente {
private:
	bool selecionada;

public: 
	Opcao();
	Opcao(sf::Vector2f ini);
	~Opcao();
	void setSelecionada(bool sel);
	const bool getSelecionada();
	void atualiza();
};