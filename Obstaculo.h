#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade {
private:
	bool SimonSays;

public:
	Obstaculo(float x, float y);
	~Obstaculo();
};