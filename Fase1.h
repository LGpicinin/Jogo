#pragma once
#include "Fase.h"
#include "Onca.h"
#include "Elemento.h"


class Fase1: public Fase
{
    public:
        Fase1();
        Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
        ~Fase1();
        void executar();

};