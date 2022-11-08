#include "Hitbox.h"

Hitbox::Hitbox() {
	b = sf::Vector2f(0, 0);
	bmx = sf::Vector2f(0, 0);
	bmy = sf::Vector2f(0, 0);
	bmxy = sf::Vector2f(0, 0);
}

Hitbox::Hitbox(sf::Vector2f w, sf::Vector2f x, sf::Vector2f y, sf::Vector2f z) {
	b = w;
	bmx = x;
	bmy = y;
	bmxy = z;
}

Hitbox::~Hitbox() {}

void Hitbox::setB(float x, float y) { b = sf::Vector2f(x,y); }
void Hitbox::setBmx(float x, float y) { bmx = sf::Vector2f(x, y); }
void Hitbox::setBmy(float x, float y) { bmy = sf::Vector2f(x, y); }
void Hitbox::setBmxy(float x, float y) { bmxy = sf::Vector2f(x, y); }

void Hitbox::setAll(sf::Vector2f w, sf::Vector2f x, sf::Vector2f y, sf::Vector2f z) {
	b = w;
	bmx = x;
	bmy = y;
	bmxy = z;
}

sf::Vector2f Hitbox::getB() { return b; }
sf::Vector2f Hitbox::getBmx() { return bmx; }
sf::Vector2f Hitbox::getBmy() { return bmy; }
sf::Vector2f Hitbox::getBmxy() { return bmxy; }

sf::Vector2f Hitbox::getTam() {
	float x = bmx.x - b.x;
	float y = bmy.y - b.y;
	return sf::Vector2f(x, y);
}

void Hitbox::reposX(float x) {
	b.x += x;
	bmx.x += x;
	bmy.x += x;
	bmxy.x += x;
}