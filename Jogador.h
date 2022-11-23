#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Mapa.h"

namespace Entidades
{

	namespace Personagens
	{

		class Jogador : public Personagem {
		private:
			Mapa* pMapa2;
			sf::Clock tempoDano;
			bool verifTempo;

		public:
			Jogador();
			~Jogador();
			void move();
			void pular();
			void atualizaPos();
			void parar();
			void setMapa2(Mapa* m2) { pMapa2 = m2; }
			Mapa* getMapa2() { return pMapa2; }
			void viradoDir();
			void viradoEsq();
			void ataqueDir();
			void ataqueEsq();
			void colisaoInimigo(Entidade *i);
			int colisaoMapaObs(Entidade *hbx);
		};

	}

}
