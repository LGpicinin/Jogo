#pragma once
#include "SFML/Graphics.hpp"

class Hitbox {
private:
	sf::Vector2f b, bmx, bmy, bmxy;

public:
	Hitbox();
	Hitbox(sf::Vector2f w, sf::Vector2f x, sf::Vector2f y, sf::Vector2f z);
	~Hitbox();
	void setB(float x, float y);
	void setBmx(float x, float y);
	void setBmy(float x, float y);
	void setBmxy(float x, float y);
	void setAll(sf::Vector2f w, sf::Vector2f x, sf::Vector2f y, sf::Vector2f z);
	sf::Vector2f getB();
	sf::Vector2f getBmx();
	sf::Vector2f getBmy();
	sf::Vector2f getBmxy();
	sf::Vector2f getTam();
	void reposX(float x);
};