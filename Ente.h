#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GerenciadorGrafico;
class Ente
{
    protected:
        const int id;
        GerenciadorGrafico *gerente;
        sf::Vector2f pos;
        sf::Sprite corpo;
        sf::Texture textura;


    public:

        Ente(int i, sf::Vector2f xy);
        ~Ente();
        //virtual void executar() = 0;
        void imprimir();
        sf::Vector2f getPos();
        sf::Sprite getCorpo();
        int getId();
        void setGerente(GerenciadorGrafico* g);
};