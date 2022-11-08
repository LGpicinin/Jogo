#include "Fase.h"

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, ListaEntes *l, GerenciadorEvento *e)
{
    pColi = c;
    pGraf = g;
    lista = l;
    pEvent = e;
}

Fase::~Fase()
{
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
}