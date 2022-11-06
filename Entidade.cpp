#include "Entidade.h"
#include <iostream>
using namespace std;

Entidade::Entidade(float mass, sf::Vector2f xy, int i):
Ente(i, xy)
{
	massa = mass;
	pos = xy;
	//corpo.setFillColor(sf::Color::Blue);
	vel.x = 0.0;
	vel.y = 0.0;
}

Entidade::~Entidade() {}

/*void Ente::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) if (pos.y > 0) pos.y = pos.y - vel.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) if (pos.y < 480) pos.y = pos.y + vel.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vel.x = vel.x - 0.25;
		if (pos.x > 0) pos.x = pos.x + vel.x;
		vel.x = vel.x + 0.25;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		vel.x = vel.x + 0.25;
		if (pos.x < 640) pos.x = pos.x + vel.x;
		vel.x = vel.x - 0.25;
	}
	
	//cout << "(x, y) = (" << pos.x << ", " << pos.y << ")" << endl;
	corpo.setPosition(pos.x, pos.y);
}*/


void Entidade::setVelX(float x) { vel.x = x; }

void Entidade::cair() {
	if (pos.y < 430) {
		vel.y = vel.y + 4.9 / CLOCKS_PER_SEC;
	}
	else if (pos.y >= 430) vel.y = 0;
}
