#include "Menu.h"

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

}

Menu::~Menu() {
	opcoes.~Lista();
}

void Menu::setMusica(sf::Music* m) { musica = m; }

void Menu::executar() {
	o1.atualiza();
	o2.atualiza();
	o3.atualiza();
	o4.atualiza();
	o5.atualiza();
	sf::Texture aux;
	if (o1.getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
		o1.setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
		o1.setTextura(aux);
	}

	if (o2.getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 2-Sel.png");
		o2.setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 2.png");
		o2.setTextura(aux);
	}

	if (o3.getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 3-Sel.png");
		o3.setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 3.png");
		o3.setTextura(aux);
	}

	if (o4.getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 4-Sel.png");
		o4.setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 4.png");
		o4.setTextura(aux);
	}

	if (o5.getSelecionada() == true) {
		aux.loadFromFile("Midia/Imagens/Menu Opc 5-Sel.png");
		o5.setTextura(aux);
	}
	else {
		aux.loadFromFile("Midia/Imagens/Menu Opc 5.png");
		o5.setTextura(aux);
	}


	if (o1.getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Menu::~Menu();
	}

	else if (o2.getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

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
	}*/


	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	graf->desenhaElemento(fundo.getCorpo());
	if (carrega.getPos().x == 1000) {
		graf->desenhaElemento(titulo.getCorpo());
		graf->desenhaElemento(o1.getCorpo());
		graf->desenhaElemento(o2.getCorpo());
		graf->desenhaElemento(o3.getCorpo());
		graf->desenhaElemento(o4.getCorpo());
		graf->desenhaElemento(o5.getCorpo());
	}
}

Fase1* Menu::getFase1() { return f1; }

void Menu::setResumir(Resumir* r) { resumir = r; }

void Menu::setFase1(Fase1* f) { f1 = f; }