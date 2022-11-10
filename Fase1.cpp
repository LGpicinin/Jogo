#include "Fase1.h"

Fase1::Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e):
Fase(c, g, e)
{

}
Fase1::~Fase1(){}

void Fase1::executar()
{
    float legacy = 0.0, atual = 0.0;
    int contador;
    Elemento<Hitbox>* itobs = obs->getPrimeiro();

    while(j1->getVidas()!=0 && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        pColi->executar();
        pEvent->executar();
        legacy = j1->getMapa()->getincx();
        for(contador=1; contador<lista->getLista()->getTam(); contador++)
		{
			lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
		}
        atual = j1->getMapa()->getincx();

        if (atual != legacy) {
			inimigos->reposLista(-j1->getVel().x, 0);
			while (itobs != NULL) {
				itobs->getInfo()->reposX(-j1->getVel().x);
				itobs = itobs->getProximo();
			}
		}
        pGraf->limpaJanela();
		mapa->imprimir();
		lista->desenhaLista();
		pGraf->mostraElementos();
    }
}