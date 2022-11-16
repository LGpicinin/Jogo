#pragma once
#include "Menu.h"
#include "Lista.h"
#include "Opcao.h"
#include "Fase1.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Resumir;

class BFase1;

class BFase2;

class Salvar;

class Sair;

class Menu {
private:
	Lista<Opcao> opcoes;
	Ente titulo;
	Opcao o1, o2, o3, o4, o5;
	Ente carrega, fundo;
	sf::Music* musica;
	Fase1* f1;
	Resumir* resumir;
	BFase1* bfase1;
	BFase2* bfase2;
	Salvar* salvar;
	Sair* sair;

public:
	Menu();
	~Menu();
	void executar();
	void setMusica(sf::Music* m);
	void setResumir(Resumir* r);
	Fase1* getFase1();
	void setFase1(Fase1* f);
};