#include "Fase.h"

Fase::Fase() {
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
}

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e)
{
    pColi = c;
    pGraf = g;
    lista = NULL;
    pEvent = e;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
}

Fase::~Fase()
{
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    j1 = NULL;
    j2 = NULL;
}

void Fase::setJogador1(Jogador *j)
{
    j1 = j;
}
void Fase::setJogador2(Jogador *j)
{
    j2 = j;
}

void Fase::setEntes(ListaEntes *l)
{
    lista = l;
}

void Fase::setInimigos(ListaEntes *i)
{
    inimigos =i;
}

void Fase::setMapa2(Mapa* m) { mapa2 = m; }

Mapa* Fase::getMapa2() { return mapa2; }

void Fase::setColi(GerenciadorColisao* c) { pColi = c; }

void Fase::setEvent(GerenciadorEvento* e) { pEvent = e; }

void Fase::setGraf(GerenciadorGrafico* g) { pGraf = g; }