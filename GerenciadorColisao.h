#pragma once
#include "ListaEntes.h"
#include "Jogador.h"
#include "Hitbox.h"
#include "Mapa.h"

class GerenciadorColisao {
private:
	Jogador* pJogador;
	ListaEntes* inimigos;
	Mapa* map;


public:
	GerenciadorColisao(ListaEntes* ini, Mapa* m, Jogador* p);
	~GerenciadorColisao();
	const sf::Vector2f calculaColisaoIni(Ente* e1, Ente* e2);
	const sf::Vector2f calculaColisaoPlat(Ente* e, Plataforma* p);
	void executar();
};