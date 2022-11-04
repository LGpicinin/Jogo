#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

class Entidade: public Ente{
protected:
	float massa;
	sf::Vector2f vel;

public:
	Entidade(float mass, sf::Vector2f xy, int i);
	~Entidade();
	//void move();
	void cair();
	void setVel(float x, float y);
	void repos(float x, float y) { pos.x = pos.x + x; pos.y = pos.y + y; corpo.setPosition(pos.x, pos.y); }
};