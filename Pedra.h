#pragma once
#include "Obstaculo.h"

class Pedra : public Obstaculo {
private:
	int massa;

public:
	Pedra(float x, float y);
	~Pedra();
	void move();
};