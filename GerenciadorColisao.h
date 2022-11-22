#pragma once
#include "ListaEntes.h"
#include "Jogador.h"
#include "Mapa.h"
using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores
{

	class GerenciadorColisao {
	private:
		Jogador* pJogador;
		ListaEntes* inimigos;
		Mapa* map;


	public:
		GerenciadorColisao(ListaEntes* ini, Mapa* m, Jogador* p);
		GerenciadorColisao();
		~GerenciadorColisao();
		const sf::Vector2f calculaColisaoIni(Ente* e1, Ente* e2);
		const sf::Vector2f calculaColisaoPlat(Ente* e, Plataforma* p);
		void executar();
		void setJogador(Jogador *p);
		void setInimigos (ListaEntes *l);
		void setMapa (Mapa *m);
	};

}