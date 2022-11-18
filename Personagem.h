
#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    int numVidas;
    int dano;

public:
    Personagem(const int v, const int id, float x, float y);
    ~Personagem();
    virtual void move() = 0;
    int getVidas(){ return numVidas; }
    void verifImg();
    void operator++();
	void operator--();
    virtual void viradoEsq()=0;
    virtual void viradoDir()=0;
    virtual void ataqueDir()=0;
    virtual void ataqueEsq()=0;


};
