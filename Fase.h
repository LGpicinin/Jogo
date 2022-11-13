#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "ListaEntes.h"
#include "Hitbox.h"
#include "Elemento.h"
#include "Map.h"
#include "Mapa.h"

class Fase
{
    protected:
        GerenciadorColisao *pColi;
        GerenciadorGrafico *pGraf;
        GerenciadorEvento *pEvent;
        ListaEntes *lista;
        ListaEntes *inimigos;
        Lista<Hitbox>* obs;
        Jogador* j1;
        Jogador* j2;
        Map *mapa;
        Mapa* mapa2;

    public:
        Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
        ~Fase();
        virtual void executar() = 0;
        void setJogador1(Jogador *j);
        void setJogador2(Jogador *j);
        void setMapa(Map *m);
        void setEntes(ListaEntes *l);
        void setHitbox(Lista<Hitbox>* h);
        void setInimigos(ListaEntes *i);
        void setMapa2(Mapa* m);
};