#pragma once
#include "Fase.h"
#include "SFML/Audio.hpp"

namespace Fases
{

    class Fase2 : public Fase
    {
    private:
        sf::Music* f1;
        sf::Music* f2;
        Curupira *chefe;
        sf::Clock aposChefe;

    public:
        Fase2();
        Fase2(GerenciadorColisao* c, GerenciadorGrafico* g, GerenciadorEvento* e);
        ~Fase2();
        void executar();
        void geraInimigos();
        void geraObstaculos();
        Curupira* geraCurupira(float x, float y);
        sf::Music* getMusica();
        Curupira* getChefe();
    };

}