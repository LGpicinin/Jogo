#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Mapa.h"


class Jogador : public Personagem {
private:
	Mapa* pMapa2;

public:
	Jogador();
	~Jogador();
	void move();
	void pular();
	void atualizaPos();
	void parar();
	void setMapa2(Mapa* m2) { pMapa2 = m2; }
	Mapa* getMapa2() { return pMapa2; }
	void operator++();
	void operator--();
	void viradoDir();
	void viradoEsq();
};
