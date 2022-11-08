#include "Fase.h"

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, ListaEntes *l, GerenciadorEvento *e, Lista<Hitbox>* h)
{
    pColi = c;
    pGraf = g;
    lista = l;
    pEvent = e;
    obs = h;
}

Fase::~Fase()
{
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    obs = NULL;
}