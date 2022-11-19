#include "Arara.h"

Arara::Arara(Jogador* j, float x, float y) :
Inimigo(j, x, y)
{
    dano = 1;
    numVidas = 2;
    aumentaVel = 0;
    voa = true;

    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
    if(!textura.loadFromFile("Midia/Imagens/Arara.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);
}

Arara::~Arara() {}

void Arara::viradoEsq()
{
    textura.loadFromFile("Midia/Imagens/Arara2.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 225));  
}
void Arara::viradoDir()
{
    textura.loadFromFile("Midia/Imagens/Arara.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
}

void Arara::ataqueDir()
{
	textura.loadFromFile("Midia/Imagens/AraraAtaque2.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 321));
}

void Arara::ataqueEsq()
{
	textura.loadFromFile("Midia/Imagens/AraraAtaque1.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 322));
}

void Arara::ataque()
{
    int verif, v=1.5;

    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

    srand(time(NULL));
    verif = rand()%2;
    
    if(verif==2)
    {
        calculaAvanco();
        v = v + aumentaVel;
    }

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - v; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + v; }

    if((posiJogador.y - pos.y)>0) { vel.y = v; }

    else if((posiJogador.y - pos.y)<=0) { vel.y = 0; } 

}

void Arara::calculaAvanco()
{
    srand(time(NULL));
    aumentaVel = rand()%3;
}