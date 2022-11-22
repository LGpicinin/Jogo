#include "Pedra.h"
#include <time.h>

using namespace Entidades;

Pedra::Pedra(float x, float y) : Obstaculo(x, y) {
	srand(time(NULL));
	massa = 10;
	setAtacar(true);
	int opc = rand() % 2;
	//if (opc == 0) setTextura("Midia/Imagens/Pedra1.png");
	//else setTextura("Midia/Imagens/Pedra2.png");
	setPos(x, y);
	corpo.setPosition(x, y);

	corpo.setTextureRect(sf::IntRect(0, 0, 491, 338));
	if (opc == 0) if (!textura.loadFromFile("Midia/Imagens/Pedra1.png")) std::cout << "Erro na abertura da textura da pedra." << std::endl;
	else {
		corpo.setTexture(textura);
	}
	else if (!textura.loadFromFile("Midia/Imagens/Pedra2.png")) std::cout << "Erro na abertura da textura da pedra." << std::endl;
	else {
		corpo.setTexture(textura);
	}
	corpo.setScale(0.2, 0.2);
}

Pedra::~Pedra() {}

void Pedra::move() { 
	//cair();
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pos.x > graf->getCoorView().x + 320 || pos.x < graf->getCoorView().x - 320 || pos.y > graf->getCoorView().y + 240 || pos.y < graf->getCoorView().y - 240) {
        setVelX(0.0f);
		setVelY(-0.3f);
		cair();
    }
	else
	{
		pos.y += 4*vel.y;
		corpo.setPosition(pos.x, pos.y);
	}
}