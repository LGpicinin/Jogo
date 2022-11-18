#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

class Entidade: public Ente{
protected:
	sf::Vector2f vel;
	bool vivo;
	bool atacar;

public:
	Entidade(sf::Vector2f xy, int i);
	~Entidade();
	virtual void move() = 0;
	void cair();
	sf::Vector2f getVel() { return vel; };
	void setVelX(float x);
	void setVelY(float y);
	bool getAtacar();
    void setAtacar(bool a);
	bool getVivo();
    void setVivo(bool v);
	void repos(float x, float y) { pos.x = pos.x + x; pos.y = pos.y + y; corpo.setPosition(pos.x, pos.y); }
};