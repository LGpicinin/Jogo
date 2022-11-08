#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "ListaEntes.h"
#include "Hitbox.h"

class Fase
{
    protected:
        GerenciadorColisao *pColi;
        GerenciadorGrafico *pGraf;
        GerenciadorEvento *pEvent;
        ListaEntes *lista;
        Lista<Hitbox>* obs;

    public:
        virtual void executar() = 0;
        Fase(GerenciadorColisao *c, GerenciadorGrafico *g, ListaEntes *l, GerenciadorEvento *e, Lista<Hitbox>* h);
        ~Fase();

};