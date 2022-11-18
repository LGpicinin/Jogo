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
    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 0.8; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 0.8; }

    vel.y = vel.y - 1;
    
    pos.y = pos.y + vel.y;
    pos.x = pos.x + vel.x;

    float dt = relogio2.getElapsedTime().asSeconds();
    if(dt>=1.0)
    {
        relogio2.restart();
        horaAtaque = false;
    }

 }