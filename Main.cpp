#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Onca.h"
#include "Hitbox.h"
#include "GerenciadorGrafico.h"
#include "ListaEntes.h"
#include "Fase1.h"
#include "Map.h"
#include "Mapa.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;

int main() {

	//----------------------------INICIALIZACOES------------------------------------------------------
	GerenciadorEvento* gev = GerenciadorEvento::getGerenciadorEvento();
	ListaEntes lista;
	
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	sf::Vector2f xy(0.0f, 0.0f);
	sf::RectangleShape corp(sf::Vector2f(50.0f, 50.0f));
	Jogador jogador;
	jogador.setGerente(graf);
	lista.add(static_cast<Entidade*>(&jogador));
	gev->setJogador(&jogador);
	gev->setPGraf(graf);
	
	sf::Texture fundo;
	if (!fundo.loadFromFile("Midia/Imagens/Bliss.png")) {
		cout << "Erro na abertura da imagem." << endl;
	}
	sf::Sprite sfundo(fundo);
	
	sfundo.setPosition(0, 0);
	int CPular = -2;
	float legacy = 0.0, atual = 0.0;
	
	bool chk = 0;
	
	ListaEntes inimigos;
	srand(time(NULL));
	float x ;
	float y ;
	int numInimigos = 3 + rand()%7;
	int contador = 1;
	Onca* onca = new Onca(&jogador, 50, 50);
	inimigos.add(onca);
	lista.add(onca);
	while(contador!=numInimigos)
	{
		x = rand()%500;
		y = 48;
		Onca *inimigo;
		inimigo = new Onca(&jogador, x, y);
		inimigo->setGerente(graf);
		inimigos.add(static_cast<Entidade*>(inimigo));
		lista.add(static_cast<Entidade*>(inimigo));
		contador++;
	}
	Fase1 f1;
	jogador.setMapa2(f1.getMapa2());
	GerenciadorColisao gec(&inimigos, f1.getMapa2(), &jogador);

	/*f1.setColi(&gec);
	f1.setEvent(gev);
	f1.setGraf(graf);
	f1.setJogador1(&jogador);
	f1.setEntes(&lista);
	f1.setInimigos(&inimigos);*/

	//----------------------------INICIALIZACOES------------------------------------------------------

	//----------------------------LOOP PRINCIPAL------------------------------------------------------
	while (GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) {
		f1.executar();
	}


	//----------------------------LOOP PRINCIPAL------------------------------------------------------
}