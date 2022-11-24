#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Salvar.h"
#include <stdio.h>
#include <string.h>
using namespace std;

Salvar::Salvar(Menu* m) {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 4.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 320.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 320.0f));

	m->setSalvar(this);
}

Salvar::~Salvar() {}

void Salvar::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 4-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 4.png");
		setTextura(tex);
	}
}

void Salvar::executar() {
	FILE* fp = fopen("Ranking.txt", "a+");
	printf("Qual o nome do jogador?: ");
	char nome[30];
	scanf("%s", nome);
	//fgets(nome, 30, stdin);
	fputs(nome, fp);
	fputc(',', fp);
	int pon;
	if (pMenu->getFase1()) pon = pMenu->getFase1()->getJogador1()->getPontos();
	else if (pMenu->getFase2()) pon = pMenu->getFase2()->getJogador1()->getPontos();
	char p[5];
	_itoa(pon, p, 10);
	fputs(p, fp);
	fputc('\n', fp);
	fclose(fp);
}