#include "Jogador.h"
#include <iostream>
#include <cmath>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() : Personagem(3, 101, 50, 50){
	pMapa2 = NULL;
	verifTempo = true;
	//sf::Texture* textura = new sf::Texture;
	corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
	if(!textura.loadFromFile("Midia/Imagens/Parado.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
	corpo.setScale(sf::Vector2f(0.2f, 0.2f));
	/*else {
		std::cout << "O jogador eh azul." << std::endl;
		corpo.setTexture(textura);
		//corpo.setColor(sf::Color::Blue);
		//corpo.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}*/
}

Jogador::~Jogador() {}

void Jogador::move() {
	atualizaPos();
	verifImg();
}

void Jogador::atualizaPos() {
	//if (pos.x < 640 && pos.x > 0) {
	//}
	std::cout << "Nova pos.x: " << pos.x << std::endl;
	std::cout << "vel.y = " << vel.y << std::endl;
	std::cout << "pos.y = " << pos.y << std::endl;

	//if (pos.y < 430 && pos.y > 0) pos.y = pos.y + vel.y;
	
	if (gerente->getCoorView().x >= 320 && (pos.x <= gerente->getCoorView().x - 40 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||
(gerente->getCoorView().x + vel.x <= pMapa2->getLista()->getElX(pMapa2->getLista()->getTam())->getInfo()->getPos().x && pos.x >= gerente->getCoorView().x + 40 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		//pMapa->update(vel.x, 0);
		//pMapa2->reposMapa(vel.x, 0);
		//std::cout << "reposMapa foi chamada com vel.x = " << vel.x << std::endl;
		//pos.x -= vel.x;
		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x + vel.x, gerente->getCoorView().y));
	}
	//else
	//{
		pos.x = pos.x + vel.x;
	//}
	if ((pos.y >= gerente->getCoorView().y + 240 - getTam().y - 90 && vel.y > 0) || (pos.y <= gerente->getCoorView().y - 150 && vel.y < 0)) {
		//pMapa2->reposMapa(0, 2 * vel.y);
		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x, gerente->getCoorView().y + vel.y));
		//pos.y -= vel.y;
	}
	pos.y = pos.y + vel.y;
	gerente->getWindow()->setView(*(gerente->getView()));
	
	//else pos.y += vel.y;
	corpo.setPosition(pos.x, pos.y);
	
}

void Jogador::parar() {
	vel.x = 0;
}

void Jogador::pular() { vel.y = -10; }


void Jogador::viradoDir()
{
	corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
	textura.loadFromFile("Midia/Imagens/Parado.png");
}
void Jogador::viradoEsq()
{
	corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
	textura.loadFromFile("Midia/Imagens/Virado.png");
}

void Jogador::ataqueDir()
{
	corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
	textura.loadFromFile("Midia/Imagens/Ataque.png");
}

void Jogador::ataqueEsq()
{
	corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
	textura.loadFromFile("Midia/Imagens/Ataque2.png");
}

void Jogador::colisaoInimigo(Entidade *i)
{

	if(verifTempo==true)
	{
		if(atacar==true)
		{
			i->setVivo(false);
		}
		else if(i->getAtacar()==true)
		{
			operator--();
		}
		verifTempo = false;
	}

	float dt = tempoDano.getElapsedTime().asSeconds();
	if(dt>=3)
	{
		verifTempo = true;
		tempoDano.restart();
	}
}

int Jogador::colisaoMapaObs(Entidade *hbx)
{
	bool flag = 0;
	if (trunc(getPos().x + getTam().x) <= hbx->getPos().x + 16 && getPos().y >= hbx->getPos().y - getTam().y + 8) {
		setPos(sf::Vector2f(hbx->getPos().x - getTam().x, getPos().y));
		//pJogador->setVelY(-0.3f);
		std::cout << "Colisao com a direita.\n";
		setVelY(getVel().y / 1.1f);
		flag = 1;
	}
	else if (getPos().x - 8 >= hbx->getPos().x + hbx->getTam().x - 16 && getPos().y >= hbx->getPos().y - getTam().y + 8) {
		setPos(sf::Vector2f(hbx->getPos().x + hbx->getTam().x, getPos().y));
		std::cout << "Colisao com a esquerda.\n";
		//if (pJogador->getVel().y <= 0.6 && pJogador->getVel().y >= 0.2) pJogador->setVelY(-0.3f);
		//else pJogador->setVelY(pJogador->getVel().y / 2.0f);
		setVelY(getVel().y / 1.1f);
		flag = 1;
	}


	else if (trunc(getPos().y + getTam().y) + 8 >= trunc(hbx->getPos().y) && getVel().y >= 0) {
		std::cout << "Colisao abaixo.\n";
		//int py = pJogador->getPos().y / 32;
		//py = py * 32;
		if (getVel().y > 0) {
			setPos(sf::Vector2f(getPos().x, hbx->getPos().y - 73));
		}
		setVelY(0.0f);
		//pJogador->setPos(sf::Vector2f(pJogador->getPos().x, trunc(hbx->getPos().y - pJogador->getTam().y)));
		flag = 1;
	}
	else if (getPos().y >= hbx->getPos().y + hbx->getTam().y - 16) {
		std::cout << "Colisao acima.\n";
		setVelY(-getVel().y);
		setPos(getPos().x, hbx->getPos().y + hbx->getTam().y);
	}
	
	if(verifTempo==true && hbx->getAtacar()==true)
	{
		operator--();
		verifTempo = false;
	}

	float dt = tempoDano.getElapsedTime().asSeconds();
	if(dt>=3)
	{
		verifTempo = true;
		tempoDano.restart();
	}

	return flag;
}