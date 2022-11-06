#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Map.h"


class Jogador : public Personagem {
private:
	Map* pMapa;

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
};
