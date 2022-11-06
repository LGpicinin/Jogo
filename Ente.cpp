#include "Ente.h"
#include "GerenciadorGrafico.h"

Ente::Ente(int i, sf::Vector2f xy):
id(i)
{
    pos = xy;
    //textura = new sf::Texture;
    if(!textura.loadFromFile("Midia/Imagens/Roxo.png")) std::cout << "Erro na abertura da textura roxa para o ente." << std::endl;
    else {
        std::cout << "Foi criado um ente com a textura roxa." << std::endl;
        corpo.setTexture(textura);
    }
    corpo.setTextureRect(sf::IntRect(0, 0, 50, 50));
    corpo.setPosition(sf::Vector2f(xy.x, xy.y));
}

Ente::~Ente() {  }

void Ente::imprimir()
{
    gerente->desenhaElemento(corpo);
}

sf::Vector2f Ente::getPos() { return pos; }

sf::Sprite Ente::getCorpo() { return corpo; }

int Ente::getId(){ return id; }

void Ente::setGerente(GerenciadorGrafico* g)
{
    gerente = g;
}
