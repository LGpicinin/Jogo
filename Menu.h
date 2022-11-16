#pragma once
#include "Menu.h"
#include "Lista.h"
#include "Opcao.h"
#include "Fase1.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Menu {
private:
	Lista<Opcao> opcoes;
	Ente titulo;
	Opcao o1, o2, o3, o4, o5;
	Ente carrega, fundo;
	sf::Music* musica;

public:
	Menu();
	~Menu();
	void executar();
	void setMusica(sf::Music* m);
};