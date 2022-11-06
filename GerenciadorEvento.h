#pragma once
#include "Jogador.h"
#include "GerenciadorGrafico.h"

class GerenciadorEvento {
private:
	GerenciadorGrafico* pGraf;
	Jogador* pJogador;
	GerenciadorEvento();
	static GerenciadorEvento* pEvento;

public:
	static GerenciadorEvento* getGerenciadorEvento();
	~GerenciadorEvento();
	void setJogador(Jogador* p);
	void setPGraf(GerenciadorGrafico* p);
	void verifTeclaPressionada(sf::Keyboard::Key tecla);
	void verifTeclaSolta(sf::Keyboard::Key tecla);
	void executar();
};