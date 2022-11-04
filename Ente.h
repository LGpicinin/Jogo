#pragma once
#include <SFML/Graphics.hpp>

class Ente
{
    protected:
        const int id;
        //GerenciadorGrafico* gerente;
        //sf::RectangleShape corpo;
        sf::Vector2f pos;
        sf::Sprite corpo;
        sf::Texture textura;


    public:
        Ente(sf::Vector2f xy, int i);
        ~Ente();
        //virtual void executar() = 0;
        //void imprimir();
        sf::Vector2f getPos();
        sf::Sprite getCorpo();
};