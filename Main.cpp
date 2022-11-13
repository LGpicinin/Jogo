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
	//Elemento<Entidade>* aux;
	//list <Personagem*> listaPersonagens;
	//list <Personagem*>::iterator itPer;
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	sf::Vector2f xy(0.0f, 0.0f);
	sf::RectangleShape corp(sf::Vector2f(50.0f, 50.0f));
	Jogador jogador;
	jogador.setGerente(graf);
	lista.add(static_cast<Entidade*>(&jogador));
	gev->setJogador(&jogador);
	gev->setPGraf(graf);
	Map mapa;
	mapa.setGerente(graf);
	//mapa.setPJogador(&jogador);
	mapa.load();
	jogador.setMapa(&mapa);
	Mapa mapa2;
	jogador.setMapa2(&mapa2);

	sf::Music s8;
	if (!s8.openFromFile("Midia/Musicas/S8M4.ogg")) {
		cout << "Erro na abertura da musica." << endl;
	}
	s8.play();
	sf::Texture fundo;
	if (!fundo.loadFromFile("Midia/Imagens/Bliss.png")) {
		cout << "Erro na abertura da imagem." << endl;
	}
	sf::Sprite sfundo(fundo);
	//Plataforma plataforma(sf::Vector2f(125.0, 455.0), sf::RectangleShape(sf::Vector2f(300.0, 25.0)));
	//lista.add(static_cast<Entidade*>(&plataforma));
	sfundo.setPosition(0, 0);
	int CPular = -2;
	float legacy = 0.0, atual = 0.0;
	//Hitbox h(sf::Vector2f(0.0f, 432.0f), sf::Vector2f(128.0f, 432.0f), sf::Vector2f(0.0f, 480.0f), sf::Vector2f(128.0f, 480.0f));
	//Hitbox h2(sf::Vector2f(448.0f, 448.0f), sf::Vector2f(608.0f, 448.0f), sf::Vector2f(448.0f, 480.0f), sf::Vector2f(608.0f, 480.0f));
	//Lista<Hitbox> obs;
	//obs.incluirEl(&h);
	//obs.incluirEl(&h2);
	bool chk = 0;
	//sf::Image i;
	//if(!i.loadFromFile("Midia/Imagens/Teste Tilemap2.png")) cout << "Erro no carregamento da imagem principal.\n";
	//Plataforma::setImagem(i);
	/*for (float i = 0; i <= 3968; i = i + 32) {
		chk = 0;
		for (float j = 352.0f; j <= 1088; j = j + 32){
			Plataforma* p = new Plataforma(sf::Vector2f(i, j));
			if (p->getNula() == false) {
				chk = 1;
				cout << "Item adicionado a lista.\n";
				//p->setGerente(graf);
				lista.add(p);
			}
			else if (chk == 1) break;
		}
	}*/
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
	GerenciadorColisao gec(&inimigos, &mapa2, &jogador);
	Fase1 f1(&gec, graf, gev);

	f1.setJogador1(&jogador);
	f1.setMapa(&mapa);
	f1.setEntes(&lista);
	//f1.setHitbox(&obs);
	f1.setInimigos(&inimigos);
	f1.setMapa2(&mapa2);

	//----------------------------INICIALIZACOES------------------------------------------------------

	//----------------------------LOOP PRINCIPAL------------------------------------------------------
	while (GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) {
		f1.executar();
	}


	//----------------------------LOOP PRINCIPAL------------------------------------------------------

	//-----------------------------ENCERRAMENTO-------------------------------------------------------
	/*for (itPer = listaPersonagens.begin(); itPer != listaPersonagens.end(); itPer++) {
		listaPersonagens.erase(itPer);
	}
	listaPersonagens.clear();*/

}