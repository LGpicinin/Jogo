#pragma once
#include "Inimigo.h"
#include "ListaEntes.h"
#include "Lista.h"
#include "Projetil.h"

class Curupira: public Inimigo
{
	private:
		Projetil *fogo;
		bool atirar;
		bool ressucitar;
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
        void setFogo(Projetil *p);
		
};