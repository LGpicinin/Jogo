#include "GerenciadorColisao.h"
#include <cmath>

GerenciadorColisao::GerenciadorColisao(ListaEntes* ini, Mapa* m, Jogador* p) {
	inimigos = ini;
	map = m;
	pJogador = p;
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

const sf::Vector2f GerenciadorColisao::calculaColisaoPlat(Ente* e, Plataforma* p) {
	sf::Vector2f pos1 = e->getPos();
	sf::Vector2f pos2 = p->getPos();
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
	Entidade* ent1 = pJogador;
	//for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++) {
		//Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		for (int j = 0; j <= inimigos->getLista()->getTam(); j++) {
			Entidade* ent2 = inimigos->getLista()->getElX(j)->getInfo();
			if(ent2->getVivo()==true)
			{
				sf::Vector2f ds = calculaColisaoIni(ent1, ent2);
				if (ds.x < 0.0f && ds.y < 0.0f) {
					std::cout << "Ocorre uma colisao 1.\n";
					
					pJogador->colisaoInimigo(ent2);
					
				}
			}
		}
	


	//for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++) {
		//Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		GerenciadorGrafico *graf = GerenciadorGrafico::getGerenciadorGrafico();
		bool flag = 0;
		for (int j = 0; j < map->getColidiveis()->getTam(); j++) {
			Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
			if (hbx->getPos().x > graf->getCoorView().x + 320 || hbx->getPos().x < graf->getCoorView().x - 320 || hbx->getPos().y > graf->getCoorView().y + 240 || hbx->getPos().y < graf->getCoorView().y - 240) continue;
			sf::Vector2f ds = calculaColisaoPlat(ent1, hbx);
			if (ds.x < 0.0f && ds.y < 0.0f) {

				std::cout << "Ocorre uma colisao 2 - Jogador.\n";

				if (trunc(pJogador->getPos().x + pJogador->getTam().x) <= hbx->getPos().x + 16 && pJogador->getPos().y >= hbx->getPos().y - pJogador->getTam().y + 8) {
					pJogador->setPos(sf::Vector2f(hbx->getPos().x - pJogador->getTam().x, pJogador->getPos().y));
					//pJogador->setVelY(-0.3f);
					std::cout << "Colisao com a direita.\n";
					pJogador->setVelY(pJogador->getVel().y / 1.1f);
					flag = 1;
				}
				else if (pJogador->getPos().x - 8 >= hbx->getPos().x + hbx->getTam().x - 16 && pJogador->getPos().y >= hbx->getPos().y - pJogador->getTam().y + 8) {
					pJogador->setPos(sf::Vector2f(hbx->getPos().x + hbx->getTam().x, pJogador->getPos().y));
					std::cout << "Colisao com a esquerda.\n";
					//if (pJogador->getVel().y <= 0.6 && pJogador->getVel().y >= 0.2) pJogador->setVelY(-0.3f);
					//else pJogador->setVelY(pJogador->getVel().y / 2.0f);
					pJogador->setVelY(pJogador->getVel().y / 1.1f);
					flag = 1;
				}


				else if (trunc(pJogador->getPos().y + pJogador->getTam().y) + 8 >= trunc(hbx->getPos().y) && pJogador->getVel().y >= 0) {
					std::cout << "Colisao abaixo.\n";
					//int py = pJogador->getPos().y / 32;
					//py = py * 32;
					if (pJogador->getVel().y > 0) {
						pJogador->setPos(sf::Vector2f(pJogador->getPos().x, hbx->getPos().y - 73));
					}
					pJogador->setVelY(0.0f);
					//pJogador->setPos(sf::Vector2f(pJogador->getPos().x, trunc(hbx->getPos().y - pJogador->getTam().y)));
					flag = 1;
				}
				else if (pJogador->getPos().y >= hbx->getPos().y + hbx->getTam().y - 16) {
					std::cout << "Colisao acima.\n";
					pJogador->setVelY(-pJogador->getVel().y);
					pJogador->setPos(pJogador->getPos().x, hbx->getPos().y + hbx->getTam().y);
				}
				
				
			}
			//else pJogador->cair();
		}
		if (flag == 0) pJogador->cair();
		
		bool flag2 = 0;
		for (int i = 0; i <= inimigos->getLista()->getTam(); i++) {
			flag2 = 0;
			ent1 = inimigos->getLista()->getElX(i)->getInfo();
			if (ent1->getVivo() == false) continue;
			if (ent1->getPos().x > graf->getCoorView().x + 320 || ent1->getPos().x < graf->getCoorView().x - 320 || ent1->getPos().y > graf->getCoorView().y + 240 || ent1->getPos().y < graf->getCoorView().y - 240) continue;
			for (int j = 0; j < map->getColidiveis()->getTam(); j++) {
				Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
				if (hbx->getPos().x > graf->getCoorView().x + 320 || hbx->getPos().x < graf->getCoorView().x - 320 || hbx->getPos().y > graf->getCoorView().y + 240 || hbx->getPos().y < graf->getCoorView().y - 240) continue;
				sf::Vector2f ds = calculaColisaoPlat(ent1, hbx);
				if (ds.x < 0.0f && ds.y < 0.0f) {
					std::cout << "Ocorre uma colisao 2 - Inimigo.\n";
					if (ent1->getPos().y + ent1->getTam().y >= hbx->getPos().y) {
						ent1->setVelY(0.0f);
						flag2 = 1;
					}

				}
				//else if (ent1->getPos().x + ent1->getTam().x >= hbx->getPos().x)
				//else pJogador->cair();
			}
			if (flag2 == 0) ent1->cair();
		}
	}
