#include "Personagem.h"

Personagem::Personagem(const int v, const int id) : Entidade(10, sf::Vector2f(50.0f, 50.0f), id)
{
    numVidas = v;
}

Personagem::~Personagem(){}
