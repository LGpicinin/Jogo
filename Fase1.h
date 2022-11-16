#pragma once
#include "Fase.h"
#include "Onca.h"
#include "Elemento.h"
#include "SFML/Audio.hpp"


class Fase1: public Fase
{
private:
    sf::Music* f1;

    public:
        Fase1();
        Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
        ~Fase1();
        void executar();

};