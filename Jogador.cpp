#include "Jogador.h"
#include <iostream>
#include <cmath>

using namespace Entidades;
using namespace Personagens;

int Jogador::segueJogador = 1;

Jogador::Jogador(const int j): Personagem(3, 101, 50, 50), jogador(j){
	pMapa2 = NULL;
	verifTempo = true;
	pontos = 0;

	if(j==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
		if(!textura.loadFromFile("Midia/Imagens/J1Direita.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 289, 371));
		if(!textura.loadFromFile("Midia/Imagens/J2Direita.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
		setVidas(0);
	}
	corpo.setScale(sf::Vector2f(0.2f, 0.2f));
	
}

Jogador::~Jogador() {}

void Jogador::move() 
{
	std::cout << "Nova pos.x: " << pos.x << std::endl;
	std::cout << "vel.y = " << vel.y << std::endl;
	std::cout << "pos.y = " << pos.y << std::endl;
	
	if((jogador==1 && segueJogador==1)||(jogador==2 && segueJogador==2))
		atualizaPos();

	pos.x = pos.x + vel.x;
	pos.y = pos.y + vel.y;
	corpo.setPosition(pos.x, pos.y);

	verifImg();
}

void Jogador::atualizaPos() {
	//if (pos.x < 640 && pos.x > 0) {
	//}

	//if (pos.y < 430 && pos.y > 0) pos.y = pos.y + vel.y;
	if (gerente->getCoorView().x >= 320 && (pos.x <= gerente->getCoorView().x - 40 && vel.x<0) ||
	(gerente->getCoorView().x + vel.x <= pMapa2->getLista()->getElX(pMapa2->getLista()->getTam())->getInfo()->getPos().x && pos.x >= gerente->getCoorView().x + 40 && vel.x>0)) {
			
		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x + vel.x, gerente->getCoorView().y));
	}
		//else
		//{
		//}
	if ((pos.y >= gerente->getCoorView().y + 240 - getTam().y - 90 && vel.y > 0) || (pos.y <= gerente->getCoorView().y - 150 && vel.y < 0)) {

		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x, gerente->getCoorView().y + vel.y));

	}
	gerente->getWindow()->setView(*(gerente->getView()));
	
}

void Jogador::parar() {
	vel.x = 0;
}

void Jogador::pular() { vel.y = -10; }


void Jogador::viradoDir()
{
	if(jogador==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
		textura.loadFromFile("Midia/Imagens/J1Direita.png");
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 289, 371));
		textura.loadFromFile("Midia/Imagens/J2Direita.png");
	}
}
void Jogador::viradoEsq()
{
	if(jogador==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 289, 368));
		textura.loadFromFile("Midia/Imagens/J1Esquerda.png");
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 291, 369));
		textura.loadFromFile("Midia/Imagens/J2Esquerda.png");
	}
}

void Jogador::ataqueDir()
{
	if(jogador==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
		textura.loadFromFile("Midia/Imagens/J1AtaqueDireita.png");
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 480, 369));
		textura.loadFromFile("Midia/Imagens/J2AtaqueDireita.png");
	}
}

void Jogador::ataqueEsq()
{
	if(jogador==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
		textura.loadFromFile("Midia/Imagens/J1AtaqueEsquerda.png");
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 480, 369));
		textura.loadFromFile("Midia/Imagens/J2AtaqueEsquerda.png");
	}
}

void Jogador::colisaoInimigo(Entidade *i)
{

	if(verifTempo==true)
	{
		if(atacar==true)
		{
			i->setVidas(i->getVidas()-1);
			if (i->getVivo() == false) pontos += 100;
		}
		else if(i->getAtacar()==true)
		{
			operator--();
			if(getVidas()<=0)
			{
				if(jogador==1 && segueJogador==1)
					setSegue(2);
				else if(jogador==2 && segueJogador==2)
					setSegue(1);
			}
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
		if(getVidas()<=0)
		{
			if(jogador==1 && segueJogador==1)
				setSegue(2);
			else if(jogador==2 && segueJogador==2)
				setSegue(1);
		}
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

int Jogador::getPontos() { return pontos; }

void Jogador::setSegue(int i)
{
	segueJogador = i;
}

int Jogador::getSegue()
{
	return segueJogador;
}