#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorGrafico {
private:
	sf::RenderWindow* window;
	static GerenciadorGrafico* pGrafico;
	GerenciadorGrafico();
	sf::View view;

public:
	~GerenciadorGrafico();
	static GerenciadorGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();
	void limpaJanela();
	void desenhaElemento(sf::Sprite corpo);
	void mostraElementos();
	void fecharJanela();
	const bool verifJanelaAberta();
	sf::Vector2f getCoorView();
	void setView(sf::Vector2f coor);
	sf::View* getView();
};