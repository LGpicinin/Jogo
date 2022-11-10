#include "Fase.h"

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e)
{
    pColi = c;
    pGraf = g;
    lista = NULL;
    pEvent = e;
    obs = NULL;
    mapa = NULL;
    j1 = NULL;
    j2 = NULL;
}

Fase::~Fase()
{
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    obs = NULL;
    mapa = NULL;
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
void Fase::setMapa(Map *m)
{
    mapa = m;
}

void Fase::setEntes(ListaEntes *l)
{
    lista = l;
}

void Fase::setHitbox(Lista<Hitbox>* h)
{
    obs = h;
}

void Fase::setInimigos(ListaEntes *i)
{
    inimigos =i;
}