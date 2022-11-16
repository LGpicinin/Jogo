#include "Fase1.h"

Fase1::Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e):
Fase(c, g, e)
{
    
}

Fase1::Fase1(): Fase() {
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Teste Tilemap2.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(0.0f, 320.0f), sf::Vector2f(3968.0f, 1088.0f));
    mapa2 = mapa;
}

Fase1::~Fase1(){
    mapa2->~Mapa();
}

void Fase1::executar()
{
    float legacy = 0.0, atual = 0.0;
    int contador;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();
    

    while(j1->getVidas()!=0 && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        pColi->executar();
        pEvent->executar();
        //legacy = j1->getMapa()->getincx();
        for(contador=1; contador<lista->getLista()->getTam(); contador++)
		{
			lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
		}
        //atual = j1->getMapa()->getincx();

        /*if (atual != legacy) {
			inimigos->reposLista(-j1->getVel().x, 0);
			while (itobs != NULL) {
				itobs->getInfo()->reposX(-j1->getVel().x);
				itobs = itobs->getProximo();
			}
		}*/
        pGraf->limpaJanela();
	    mapa2->imprimir();
		lista->desenhaLista();
		pGraf->mostraElementos();
    }
}