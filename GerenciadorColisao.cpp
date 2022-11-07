#include "GerenciadorColisao.h"
#include <cmath>

GerenciadorColisao::GerenciadorColisao(ListaEntes* ini, Lista<Hitbox>* obs) {
	inimigos = ini;
	plataformas = obs;
}

GerenciadorColisao::~GerenciadorColisao() {}

const sf::Vector2f GerenciadorColisao::calculaColisaoIni(Ente* e1, Ente* e2) {
	sf::Vector2f pos1 = e1->getPos();
	sf::Vector2f pos2 = e2->getPos();
	sf::Vector2f tam1 = e1->getTam();
	sf::Vector2f tam2 = e2->getTam();
	sf::Vector2f distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

const sf::Vector2f GerenciadorColisao::calculaColisaoPlat(Ente* e, Hitbox* p) {
	sf::Vector2f pos1 = e->getPos();
	sf::Vector2f pos2 = p->getB();
	sf::Vector2f tam1 = e->getTam();
	sf::Vector2f tam2 = p->getTam();
	sf::Vector2f distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

void GerenciadorColisao::executar() {
	for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++) {
		Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		for (int j = i + 1; j < inimigos->getLista()->getTam(); j++) {
			Entidade* ent2 = inimigos->getLista()->getElX(j)->getInfo();
			sf::Vector2f ds = calculaColisaoIni(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f) {
				//ent1->colisao(ent2);
			}
		}
	}


	for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++) {
		Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		for (int j = i + 1; j < plataformas->getTam(); j++) {
			Hitbox* hbx = plataformas->getElX(j)->getInfo();
			sf::Vector2f ds = calculaColisaoPlat(ent1, hbx);
			if (ds.x < 0.0f && ds.y < 0.0f) {
				//ent1->colisao(ent2);
			}
		}
	}
}