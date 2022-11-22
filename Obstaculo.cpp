#include "Obstaculo.h"

using namespace Entidades;

Obstaculo::Obstaculo(float x, float y) : Entidade(3, sf::Vector2f(x, y), 0) {
	SimonSays = true;
}

Obstaculo::~Obstaculo() {}