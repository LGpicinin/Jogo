#pragma once
#include "Fase.h"
#include "Arara.h"
#include "SFML/Audio.hpp"

namespace Fases
{

    class Fase1: public Fase
    {
    private:
        sf::Music* f1;

        public:
            Fase1();
            Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
            ~Fase1();
            void executar();
            void geraInimigos();
            void geraArara(float x, float y);
            void geraObstaculos();
    };

}