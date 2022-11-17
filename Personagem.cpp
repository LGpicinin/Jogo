#include "Personagem.h"

Personagem::Personagem(const int v, const int id, float x, float y) : Entidade(sf::Vector2f(x, y), id)
{
    numVidas = v;
}

Personagem::~Personagem(){}

void Personagem::verifImg()
{
    if(vel.x>0)
    {
        this->viradoDir();
    }
    else if(vel.x<0)
    {
        this->viradoEsq();
    }
}
