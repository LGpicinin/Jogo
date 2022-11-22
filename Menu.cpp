#include "Menu.h"
#include "Resumir.h"
#include "BFase1.h"
#include "BFase2.h"
#include "Sair.h"

Menu::Menu(): titulo(sf::Vector2f(30.0f, 0.0f)), carrega(sf::Vector2f(1000.0f, 1000.0f)), fundo(sf::Vector2f(0.0f, 0.0f)) {
	resumir = NULL;
	bfase1 = NULL;
	sair = NULL;
	f1 = NULL;
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setTextura("Midia/Imagens/Titulo.png");
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setPos(sf::Vector2f(30.0f, 0.0f));
	titulo.getCorpo().setPosition(30.0f, 0.0f);
	
}

Menu::~Menu() {
	opcoes.~Lista();
	delete f1;
}

void Menu::setMusica(sf::Music* m) { musica = m; }

void Menu::executar() {
	GerenciadorGrafico::getGerenciadorGrafico()->setView(sf::Vector2f(320.0f, 240.0f));
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	resumir->getCorpo().setPosition(800, 80);
	while (true) {
		resumir->atualiza();
		bfase1->atualiza();
		bfase2->atualiza();
		sair->atualiza();
		if (resumir->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			resumir->executar();
			break;
		}

		else if (bfase1->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bfase1->executar();
			break;

		}
		else if (bfase2->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bfase2->executar();
			break;

		}

		else if (sair->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sair->executar();
		}
		GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
		graf->limpaJanela();
		graf->desenhaElemento(titulo.getCorpo());
		graf->desenhaElemento(resumir->getCorpo());
		graf->desenhaElemento(bfase1->getCorpo());
		graf->desenhaElemento(bfase2->getCorpo());
		graf->desenhaElemento(sair->getCorpo());
		graf->mostraElementos();
	}
}

Fase1* Menu::getFase1() { return f1; }

void Menu::setResumir(Resumir* r) { resumir = r; }

void Menu::setBFase1(BFase1* b) { bfase1 = b; }

void Menu::setBFase2(BFase2* b) { bfase2 = b; }

void Menu::setSalvar(Salvar* s) { salvar = s; }

void Menu::setSair(Sair* s) { sair = s; }

void Menu::setFase1(Fase1* f) { f1 = f; }

Fase* Menu::getFase() 
{
	if (f1) return f1;
	else if (f2) return f2;
	else
	{
		f1 = NULL;
		return f1;
	}
}

Fase2* Menu::getFase2() { return f2; }

void Menu::setFase2(Fase2* f) { f2 = f; }