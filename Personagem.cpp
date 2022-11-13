#include "Personagem.h"

Personagem::Personagem(const int v, const int id, float x, float y) : Entidade(sf::Vector2f(x, y), id)
{
    numVidas = v;
}

Personagem::~Personagem(){}
