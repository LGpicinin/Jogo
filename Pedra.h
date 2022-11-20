#pragma once
#include "Inimigo.h"

class Pedra : public Inimigo {
private:
	int massa;

public:
	Pedra(float x, float y);
	~Pedra();
	void viradoEsq();
	void viradoDir();
	void ataqueDir();
	void ataqueEsq();
};