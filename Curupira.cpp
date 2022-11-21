#include "Curupira.h"


Curupira::Curupira(Jogador* j, float x, float y):
Inimigo(j, x, y)
{
	dano = 1;
	numVidas = 4;
	ressucitar = false;
    ataqueDistancia = true;
	atirar = true;

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

    sf::Vector2f posiJogador;


    posiJogador = jogador->getPos();
    if (abs(posiJogador.x - pos.x)<200 && abs(posiJogador.y - pos.y)<200)
    {
        afastar();
        atacar = false;
    }
    else if(abs(posiJogador.x - pos.x)<600 && abs(posiJogador.y - pos.y)<600)
    {
        ataque();
        atacar = true;
    }
    else
    {
        movimentoAleatorio();
        atacar = false;
    }


            //cair();

    pos.y = pos.y + (vel.y * 2);
    pos.x = pos.x + vel.x;

    corpo.setPosition(pos.x, pos.y);
    verifImg();

    vel.x = 0;

    

}

void Curupira::ataque()
{
    sf::Vector2f posiJogador;
    posiJogador = jogador->getPos();

	if(atirar==true)
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
	
	while(aux->getProximo()!=NULL)
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
void Curupira::setFogo(Projetil *p)
{
    fogo = p;
    p->setAtirador(static_cast<Inimigo*>(this));
}