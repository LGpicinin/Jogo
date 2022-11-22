#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades
{

    namespace Personagens

    {

        class Inimigo : public Personagem
        {
        protected:
            Jogador* jogador;
            int movAl;
            bool horaAtaque;
            bool ataqueDistancia;
            bool voa;
            sf::Clock relogio;

        public:
            Inimigo(Jogador* j, float x, float y);
            ~Inimigo();
            void move();
            void persegueJogador();
            void movimentoAleatorio();
            virtual void ataque();
            void congela();
        };

    }

}