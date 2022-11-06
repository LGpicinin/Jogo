#include "Map.h"
#include <iostream>

//Map::Map() : tamx(16), tamy(16), qtdx(0), qtdy(0) {}

Map::~Map() {}

void Map::inicializa() {}

void Map::load() {
	if (!tileSheet.loadFromFile("Midia/Imagens/Teste Tilemap.png")) {
		std::cout << "Erro na abertura do tilemap." << std::endl;
	}
	else {
		sprite.setTexture(tileSheet);
		sprite.setTextureRect(sf::IntRect(incx, incy, 640, 480));
		//sprite.setScale(2, 2);
		sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
		qtdx = tileSheet.getSize().x / tamx;
		qtdy = tileSheet.getSize().y / tamy;
	}
}

void Map::update(float x, float y) { incx = incx + x; incy = incy + y; sprite.setTextureRect(sf::IntRect(incx, incy, 640, 480)); }

void Map::draw(sf::RenderWindow* window) { window->draw(sprite); }