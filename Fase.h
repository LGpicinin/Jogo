#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "ListaEntes.h"
#include "Hitbox.h"
#include "Elemento.h"
#include "Mapa.h"
#include "Onca.h"
#include "Curupira.h"
#include "Obstaculo.h"

class Fase
{
    protected:
        GerenciadorColisao *pColi;
        GerenciadorGrafico *pGraf;
        GerenciadorEvento *pEvent;
        ListaEntes *lista;
        ListaEntes *inimigos;
        Jogador* j1;
        Jogador* j2;
        Mapa* mapa2;
        Lista<Obstaculo>* obs;

    public:
        Fase();
        Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
        ~Fase();
        virtual void executar() = 0;
        void setJogador1(Jogador *j);
        void setJogador2(Jogador *j);
        void setEntes(ListaEntes *l);
        void setInimigos(ListaEntes *i);
        void setMapa2(Mapa* m);
        Mapa* getMapa2();
        void setColi(GerenciadorColisao* c);
        void setGraf(GerenciadorGrafico* g);
        void setEvent(GerenciadorEvento* e);
        ListaEntes* getLista();
        ListaEntes* getInimigos();
        Jogador* getJogador1();
        void geraOnca(float x, float y);
        Curupira* geraCurupira(float x, float y);
        Projetil* geraProjetil(float x, float y);
};