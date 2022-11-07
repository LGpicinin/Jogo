#pragma once
#include "ListaEntes.h"
#include "Hitbox.h"

class GerenciadorColisao {
private:
	ListaEntes* inimigos;
	Lista<Hitbox>* plataformas;

public:
	GerenciadorColisao(ListaEntes* ini, Lista<Hitbox>* obs);
	~GerenciadorColisao();
	const sf::Vector2f calculaColisaoIni(Ente* e1, Ente* e2);
	const sf::Vector2f calculaColisaoPlat(Ente* e, Hitbox* p);
	void executar();
};