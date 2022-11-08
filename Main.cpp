#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Hitbox.h"
#include "GerenciadorGrafico.h"
#include "ListaEntes.h"
#include "Map.h"
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
	//listaPersonagens.push_back(static_cast<Personagem*>(&jogador));
	Inimigo inimigo(&jogador);
	inimigo.setGerente(graf);
	lista.add(static_cast<Entidade*>(&inimigo));
	//listaPersonagens.push_back(static_cast<Personagem*>(&inimigo));
	Map mapa;
	mapa.setGerente(graf);
	//mapa.setPJogador(&jogador);
	mapa.load();
	jogador.setMapa(&mapa);

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
	Hitbox h(sf::Vector2f(0.0f, 432.0f), sf::Vector2f(128.0f, 432.0f), sf::Vector2f(0.0f, 480.0f), sf::Vector2f(128.0f, 480.0f));
	//Hitbox h2(sf::Vector2f(448.0f, 448.0f), sf::Vector2f(608.0f, 448.0f), sf::Vector2f(448.0f, 480.0f), sf::Vector2f(608.0f, 480.0f));
	Lista<Hitbox> obs;
	obs.incluirEl(&h);
	//obs.incluirEl(&h2);
	ListaEntes inimigos;
	inimigos.add(&inimigo);
	inimigos.add(&jogador);
	GerenciadorColisao gec(&inimigos, &obs, &jogador);
	Elemento<Hitbox>* itobs = obs.getPrimeiro();
	
	//----------------------------INICIALIZACOES------------------------------------------------------

	//----------------------------LOOP PRINCIPAL------------------------------------------------------
	while (GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) {
		gec.executar();
		//jogador.cair();
		legacy = jogador.getMapa()->getincx();
		gev->executar();
		inimigo.move();
		jogador.atualizaPos();
		atual = jogador.getMapa()->getincx();
		if (atual != legacy) {
			lista.reposLista(-jogador.getVel().x, 0);
			while (itobs != NULL) {
				itobs->getInfo()->reposX(-jogador.getVel().x);
				itobs = itobs->getProximo();
			}
		}
		
		graf->limpaJanela();
		mapa.imprimir();
		lista.desenhaLista();
		graf->mostraElementos();
	}
	//----------------------------LOOP PRINCIPAL------------------------------------------------------

	//-----------------------------ENCERRAMENTO-------------------------------------------------------
	/*for (itPer = listaPersonagens.begin(); itPer != listaPersonagens.end(); itPer++) {
		listaPersonagens.erase(itPer);
	}
	listaPersonagens.clear();*/

}