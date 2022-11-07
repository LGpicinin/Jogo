#pragma once
#include <SFML/Graphics.hpp>
#include "Plataforma.h"


class Map {
private:
	sf::Texture tileSheet;
	sf::Sprite sprite;
	int tamx, tamy, qtdx, qtdy;
	float incx, incy;

public:
	Map() { tamx = 16; tamy = 16; qtdx = 0; qtdy = 0; incx = 0; incy = 0; }
	~Map();
	void inicializa();
	void load();
	void update(float x, float y);
	void draw(sf::RenderWindow* window);
	float getincx() { return incx; }
	float getincy() { return incy; }
	sf::Texture getTileSheet() { return tileSheet; }
};