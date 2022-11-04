#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include "ListaEntes.h"
#include "Map.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;

int main() {

	//----------------------------INICIALIZA��ES------------------------------------------------------
	ListaEntes lista;
	list <Entidade*>::iterator it;
	list <Personagem*> listaPersonagens;
	list <Personagem*>::iterator itPer;
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	sf::Vector2f xy(0.0f, 0.0f);
	sf::RectangleShape corp(sf::Vector2f(50.0f, 50.0f));
	Jogador jogador;
	lista.add(&jogador);
	listaPersonagens.push_back(static_cast<Personagem*>(&jogador));
	Inimigo inimigo(&jogador);
	lista.add(static_cast<Entidade*>(&inimigo));
	listaPersonagens.push_back(static_cast<Personagem*>(&inimigo));
	Map mapa;
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
	float legacy=0.0, atual=0.0;
	//----------------------------INICIALIZACOES------------------------------------------------------

	//----------------------------LOOP PRINCIPAL------------------------------------------------------
	while (GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) {
		clock_t TExecucao = clock();
		legacy = jogador.getMapa()->getincx();
		itPer = listaPersonagens.begin();
		while(itPer!=listaPersonagens.end())
		{
			(**itPer).move();
			itPer++;
		}
		atual = jogador.getMapa()->getincx();
		if (atual > legacy) {
			for (it = lista.getLista()->begin(); it != lista.getLista()->end(); it++) {
				(**it).repos(-0.25, 0);
			}
		}
		else if (legacy > atual) {
			for (it = lista.getLista()->begin(); it != lista.getLista()->end(); it++) {
				(**it).repos(0.25, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if ((TExecucao - CPular) / CLOCKS_PER_SEC >= 1) {
				jogador.pular();
				CPular = clock();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) graf->fecharJanela();
		graf->limpaJanela();
		mapa.draw(graf->getWindow());
		
		for (it = lista.getLista()->begin(); it != lista.getLista()->end(); it++) {
			graf->desenhaElemento(static_cast<Ente>(**it));
		}
		graf->mostraElementos();
	}
	//----------------------------LOOP PRINCIPAL------------------------------------------------------

	//-----------------------------ENCERRAMENTO-------------------------------------------------------
	for (itPer = listaPersonagens.begin(); itPer != listaPersonagens.end(); itPer++) {
		listaPersonagens.erase(itPer);
	}
	listaPersonagens.clear();

}