#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Map.h"
#include "Mapa.h"


class Jogador : public Personagem {
private:
	Map* pMapa;
	Mapa* pMapa2;

public:
	Jogador();
	~Jogador();
	void move();
	void moveDir();
	void moveEsq();
	void pular();
	void atualizaPos();
	void parar();
	void setMapa(Map* PM);
	Map* getMapa() { return pMapa; }
	void setMapa2(Mapa* m2) { pMapa2 = m2; }
	Mapa* getMapa2() { return pMapa2; }
};
