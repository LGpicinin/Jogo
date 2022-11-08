#pragma once
#include "ListaEntes.h"
#include "Jogador.h"
#include "Hitbox.h"

class GerenciadorColisao {
private:
	Jogador* pJogador;
	ListaEntes* inimigos;
	Lista<Hitbox>* plataformas;

public:
	GerenciadorColisao(ListaEntes* ini, Lista<Hitbox>* obs, Jogador* p);
	~GerenciadorColisao();
	const sf::Vector2f calculaColisaoIni(Ente* e1, Ente* e2);
	const sf::Vector2f calculaColisaoPlat(Ente* e, Hitbox* p);
	void executar();
};