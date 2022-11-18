#include "Onca.h"

Onca::Onca(Jogador* j, float x, float y) :
Inimigo(j, x, y)
{
    dano = 1;
    numVidas = 2;
    corpo.setTextureRect(sf::IntRect(0, 0, 497, 340));
    if(!textura.loadFromFile("Midia/Imagens/Onca.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);
}

Onca::~Onca(){}

void Onca::viradoEsq()
{
    textura.loadFromFile("Midia/Imagens/Onca.png");   
}
void Onca::viradoDir()
{
    textura.loadFromFile("Midia/Imagens/OncaVirada.png");
}

void Onca::ataqueDir()
{
	textura.loadFromFile("Midia/Imagens/OncaAtaque.png");
}

void Onca::ataqueEsq()
{
	textura.loadFromFile("Midia/Imagens/OncaAtaque2.png");
}

 void Onca::ataque()
 {
    vel.x = 1;

    pos.x = pos.x + (vel.x*dirEsq);

 }