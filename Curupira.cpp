#include "Curupira.h"

using namespace Entidades;
using namespace Personagens;


Curupira::Curupira(Jogador* j, float x, float y):
Inimigo(j, x, y)
{
	dano = 1;
	numVidas = 4;
	ressucitar = false;
    ataqueDistancia = true;
	atirar = true;
	corre = false;
	fogo = new Projetil(x, y);
	fogo->setAtirador(static_cast<Inimigo*>(this));

	corpo.setTextureRect(sf::IntRect(0,0,237,448));
	if(!textura.loadFromFile("Midia/Imagens/CurupiraEsquerda.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    	else {
        	corpo.setTexture(textura);
    	}
	corpo.setScale(0.2, 0.2);
}

Curupira::~Curupira()
{
	fogo = NULL;
	animais->~ListaEntes();
}
void Curupira::viradoEsq()
{
	textura.loadFromFile("Midia/Imagens/CurupiraEsquerda.png");
	corpo.setTextureRect(sf::IntRect(0,0,237,448));
}
void Curupira::viradoDir()
{
	textura.loadFromFile("Midia/Imagens/CurupiraDireita.png");
	corpo.setTextureRect(sf::IntRect(0,0,242,448));
}
void Curupira::ataqueDir()
{
	textura.loadFromFile("Midia/Imagens/CurupiraAtaqueDireita.png");
	corpo.setTextureRect(sf::IntRect(0,0,302,433));
}
void Curupira::ataqueEsq()
{
	textura.loadFromFile("Midia/Imagens/CurupiraAtaqueEsquerda.png");
	corpo.setTextureRect(sf::IntRect(0,0,303,430));
}

void Curupira::move()
{

	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
    if (pos.x > graf->getCoorView().x + 320 || pos.x < graf->getCoorView().x - 320 || pos.y > graf->getCoorView().y + 240 || pos.y < graf->getCoorView().y - 240) {
        congela();
    }
	else
	{
		sf::Vector2f posiJogador;


		posiJogador = jogador->getPos();
		if (abs(posiJogador.x - pos.x)<200 && abs(posiJogador.y - pos.y)<200)
		{
			afastar();
			atacar = false;
			corre = true;
		}
		else if(((abs(posiJogador.x - pos.x)<600 && abs(posiJogador.y - pos.y)<600)) && corre == false)
		{
			ataque();
			atacar = true;
		}
		else if ((abs(posiJogador.x - pos.x)<1000 && abs(posiJogador.y - pos.y)<1000) && corre == true)
		{
			corre = false;
		}
		else
		{
			movimentoAleatorio();
			atacar = false;
		}


				//cair();

		pos.y = pos.y + vel.y;
		pos.x = pos.x + vel.x;

		corpo.setPosition(pos.x, pos.y);
		verifImg();

		vel.x = 0;

	}

}

void Curupira::ataque()
{
    sf::Vector2f posiJogador;
    posiJogador = jogador->getPos();

	if(atirar==true && fogo->getAtivado()==false)
	{
		fogo->setAtivado(true);
        if((posiJogador.x - pos.x)<0) 
        { 
            fogo->setDireita(false);
        }
        else if((posiJogador.x - pos.x)>0) 
        { 
            fogo->setDireita(true);
        }
	}
    else
    {
        persegueJogador();
    }

	atirar = false;
	ressucitar = false;

	calculaRessucitar();
	if(ressucitar == true) { ressucitarAnimais(); }

	float dt = relogio.getElapsedTime().asSeconds();
    	if(dt>=3)
    	{
        	relogio.restart();
        	atirar = true;
    	}
}

void Curupira::afastar()
{
	int v;
	v = 3;

    sf::Vector2f posiJogador;
    vel.x = 0.0;
    posiJogador = jogador->getPos();

	if((posiJogador.x - pos.x)<0) {  vel.x = vel.x + v; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x - v; }

	if(vel.y==0) { vel.y = -2; }
}
void Curupira::calculaRessucitar()
{
	srand(time(NULL));
	
	int verif = rand()%15;
	if (verif == 10)
	{
		ressucitar = true;
	}
}

void Curupira::ressucitarAnimais()
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade *tipo;
	aux = animais->getLista()->getPrimeiro();
	
	while(aux->getProximo()->getProximo()!=NULL)
	{
		tipo = aux->getInfo();
		tipo->setVivo(true);
		tipo++;
		aux = aux->getProximo();
	}

}

void Curupira::setLista(ListaEntes *l)
{
    animais = l;
}

Projetil* Curupira::getFogo()
{
	return fogo;
}