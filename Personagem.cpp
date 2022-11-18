#include "Personagem.h"

Personagem::Personagem(const int v, const int id, float x, float y) : Entidade(v, sf::Vector2f(x, y), id)
{
    dano = 0;
}

Personagem::~Personagem(){}

void Personagem::verifImg()
{
    if(vel.x>0)
    {
        if(atacar==true)
        {
            ataqueDir();
        }
        else
        {
            viradoDir();
        }
    }
    else if(vel.x<0)
    {
        if(atacar==true)
        {
            ataqueEsq();
        }
        else
        {
            viradoEsq();
        }
    }
}
