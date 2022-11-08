#pragma once
#include <SFML/Graphics.hpp>
#include "Plataforma.h"
#include "Ente.h"


class Map: public Ente{
private:
	int tamx, tamy, qtdx, qtdy;
	float incx, incy;

public:
	Map();
	~Map();
	void inicializa();
	void load();
	void update(float x, float y);
	float getincx() { return incx; }
	float getincy() { return incy; }
};