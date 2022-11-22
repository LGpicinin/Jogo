#pragma once
#include "Inimigo.h"
#include "ListaEntes.h"
#include "Lista.h"
#include "Projetil.h"

namespace Entidades
{

	namespace Personagens
	{

		class Curupira: public Inimigo
		{
			private:
				Projetil *fogo;
				bool atirar;
				bool ressucitar;
				bool corre;
				ListaEntes *animais;
				sf::Clock relogio;

			public:
				Curupira(Jogador* j, float x, float y);
				~Curupira();
				void move();
				void viradoEsq();
				void viradoDir();
				void ataqueDir();
				void ataqueEsq();
				void ataque();
				void afastar();
				void ressucitarAnimais();
				void calculaRessucitar();
				void setLista(ListaEntes *l);
				Projetil* getFogo();
				
		};

	}

}