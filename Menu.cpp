#include "Menu.h"
#include "Resumir.h"
#include "BFase1.h"
#include "Sair.h"

Menu::Menu(): titulo(sf::Vector2f(30.0f, 0.0f)), carrega(sf::Vector2f(1000.0f, 1000.0f)), fundo(sf::Vector2f(0.0f, 0.0f)) {
	/*sf::Texture aux;
	aux.loadFromFile("Midia/Imagens/Titulo.png");
	titulo.setTextura(aux);
	aux.loadFromFile("Midia/Imagens/Preto.png");
	fundo.setTextura(aux);
	aux.loadFromFile("Midia/Imagens/Carregando.png");
	carrega.setTextura(aux);
	o1.setPos(sf::Vector2f(160.0f, 80.0f));
	aux.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
	o1.setTextura(aux);
	o2.setPos(sf::Vector2f(160.0f, 160.0f));
	aux.loadFromFile("Midia/Imagens/Menu Opc 2.png");
	o2.setTextura(aux);
	o3.setPos(sf::Vector2f(160.0f, 240.0f));
	aux.loadFromFile("Midia/Imagens/Menu Opc 3.png");
	o3.setTextura(aux);
	o4.setPos(sf::Vector2f(160.0f, 320.0f));
	aux.loadFromFile("Midia/Imagens/Menu Opc 4.png");
	o4.setTextura(aux);
	o5.setPos(sf::Vector2f(160.0f, 400.0f));
	aux.loadFromFile("Midia/Imagens/Menu Opc 5.png");
	o5.setTextura(aux);*/
	resumir = NULL;
	bfase1 = NULL;
	sair = NULL;
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setTextura("Midia/Imagens/Titulo.png");
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setPos(sf::Vector2f(30.0f, 0.0f));
	titulo.getCorpo().setPosition(30.0f, 0.0f);
	
}

Menu::~Menu() {
	opcoes.~Lista();
}

void Menu::setMusica(sf::Music* m) { musica = m; }

void Menu::executar() {
	while (true) {
		resumir->atualiza();
		bfase1->atualiza();
		sair->atualiza();
		if (resumir->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			resumir->executar();
		}

		else if (bfase1->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bfase1->executar();
			break;
		}

		else if (sair->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sair->executar();
			break;
		}
		GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
		graf->limpaJanela();
		graf->desenhaElemento(titulo.getCorpo());
		graf->desenhaElemento(resumir->getCorpo());
		graf->desenhaElemento(bfase1->getCorpo());
		graf->desenhaElemento(sair->getCorpo());
		graf->mostraElementos();
	}
	/*resumir->atualiza();
	bfase1->atualiza();
	//bfase2->atualiza();
	//salvar->atualiza();
	sair->atualiza();
	/*if (resumir->getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
		resumir->setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
		resumir->setTextura(aux);
	}

	if (bfase1->getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 2-Sel.png");
		bfase1->setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 2.png");
		bfase1->setTextura(aux);
	}

	/*if (bfase2->getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 3-Sel.png");
		bfase2->setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 3.png");
		bfase2->setTextura(aux);
	}

	if (salvar->getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 4-Sel.png");
		salvar->setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 4.png");
		salvar->setTextura(aux);
	}

	if (sair->getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 5-Sel.png");
		sair->setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 5.png");
		sair->setTextura(aux);
	}


	if (resumir->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		resumir->executar();
	}

	else if (bfase1->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bfase1->executar();
	}

	else if (sair->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sair->executar();
	}
	/*float mx = sf::Mouse::getPosition().x;
	float my = sf::Mouse::getPosition().y;
	sf::Texture aux;
	if (mx >= o1.getPos().x && mx <= o1.getPos().x + o1.getTam().x && my >= o1.getPos().y && my <= o1.getPos().y) {
		o1.setSelecionada(true);
		aux.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
		o1.setTextura(aux);
	}
	else if (mx >= o2.getPos().x && mx <= o2.getPos().x + o2.getTam().x && my >= o2.getPos().y && my <= o2.getPos().y) {
		o2.setSelecionada(true);
		aux.loadFromFile("Midia/Imagens/Menu Opc 2-Sel.png");
		o2.setTextura(aux);
	}
	else if (mx >= o3.getPos().x && mx <= o3.getPos().x + o3.getTam().x && my >= o3.getPos().y && my <= o3.getPos().y) {
		o3.setSelecionada(true);
		aux.loadFromFile("Midia/Imagens/Menu Opc 3-Sel.png");
		o3.setTextura(aux);
	}
	else if (mx >= o4.getPos().x && mx <= o4.getPos().x + o4.getTam().x && my >= o4.getPos().y && my <= o4.getPos().y) {
		o4.setSelecionada(true);
		aux.loadFromFile("Midia/Imagens/Menu Opc 4-Sel.png");
		o4.setTextura(aux);
	}
	else if (mx >= o5.getPos().x && mx <= o5.getPos().x + o5.getTam().x && my >= o5.getPos().y && my <= o5.getPos().y) {
		o5.setSelecionada(true);
		aux.loadFromFile("Midia/Imagens/Menu Opc 5-Sel.png");
		o5.setTextura(aux);
	}


	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	graf->limpaJanela();
	//graf->desenhaElemento(fundo.getCorpo());
	//if (carrega.getPos().x == 1000) {
		//graf->desenhaElemento(titulo.getCorpo());
		graf->desenhaElemento(resumir->getCorpo());
		//graf->desenhaElemento(bfase1->getCorpo());
		//graf->desenhaElemento(bfase2->getCorpo());
		//graf->desenhaElemento(salvar->getCorpo());
		graf->desenhaElemento(sair->getCorpo());
	//}
	graf->mostraElementos();*/
}

Fase1* Menu::getFase1() { return f1; }

void Menu::setResumir(Resumir* r) { resumir = r; }

void Menu::setBFase1(BFase1* b) { bfase1 = b; }

void Menu::setBFase2(BFase2* b) { bfase2 = b; }

void Menu::setSalvar(Salvar* s) { salvar = s; }

void Menu::setSair(Sair* s) { sair = s; }

void Menu::setFase1(Fase1* f) { f1 = f; }