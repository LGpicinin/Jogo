#include "Fase1.h"
#include "Fase2.h"
#include "Pedra.h"
#include <iostream>

using namespace Fases;

Fase1::Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e):
Fase(c, g, e)
{
    
}

Fase1::Fase1(): Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

    f1 = new sf::Music();
    f1->openFromFile("Midia/Musicas/S8M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase1.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(0.0f, 160.0f), sf::Vector2f(4480.0f, 2240.0f));
    mapa2 = mapa;

    j1 = new Jogador();
    j1->setMapa2(mapa2);

    pGraf = GerenciadorGrafico::getGerenciadorGrafico();
    pEvent = GerenciadorEvento::getGerenciadorEvento();

    lista->add(static_cast<Entidade*>(j1));
    geraInimigos();
    geraObstaculos();
    /*Pedra* p1 = new Pedra(150, 150);
    lista->add(p1);
    inimigos->add(p1);
    Pedra* p2 = new Pedra(500, 100);
    lista->add(p2);
    inimigos->add(p2);*/

    pEvent->setJogador(j1);
    pColi = new GerenciadorColisao(inimigos, mapa2, j1);

    f1->play();
}

Fase1::~Fase1(){
    delete f1;
}

void Fase1::executar()
{
    float legacy = 0.0, atual = 0.0;
    int contador;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();
    

    while(j1->getVidas() > 0 && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        pColi->executar();
        pEvent->executar();
        //legacy = j1->getMapa()->getincx();
        for(contador=1; contador<lista->getLista()->getTam() + 1; contador++)
		{
            if (lista->getLista()->getElX(contador)->getInfo()->getVivo() == false) continue;
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
        if (j1->getPos().x > 4300 && j1->getPos().y > 800) {
            f1->stop();
            Fase2* f2 = new Fase2();
            f2->executar();
            break;
        }
        pGraf->limpaJanela();
	    mapa2->imprimir();
		lista->desenhaLista();
		pGraf->mostraElementos();
    }
    std::cout << "O loop de execucao da fase terminou.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    f1->pause();
}

void Fase1::geraInimigos()
{

    srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
    geraOnca(660, 376);
    geraOnca(608, 120);
    geraOnca(3224, 1462);
    geraArara(2384, 250);
    geraArara(1312, 150);
    geraArara(2936, 568);


    /*while (lim < 5 || contador < 3)
    {
        verif = rand() % 4;

        if (verif == 1)
        {
            geraOnca(x, y);
            contador++;
        }
        else if (verif == 3)
        {
            geraArara(x, y);
            contador++;
        }
        lim++;
        x = x + 225;
    }*/
    verif = rand() % 4;
    if (verif == 1) geraOnca(1072, 248);
    verif = rand() % 4;
    if (verif == 1) geraArara(352, 50);
    verif = rand() % 4;
    if (verif == 1) geraArara(1080, 96);
    verif = rand() % 4;
    if (verif == 1) geraOnca(2304, 374);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3456, 662);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3014, 1335);
    verif = rand() % 4;
    if (verif == 1) geraOnca(4334, 823);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3110, 1848);


}

void Fase1::geraArara(float x, float y)
{

    Arara *inimigo;
    inimigo = new Arara(j1, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase1::geraObstaculos() {
    srand(time(NULL));
    /*for (int i = 1; i <= 10; i++) {
        int p = (rand() % 50) + 30;
        Pedra* k = new Pedra((p+i)*32, 150);
        //obs->incluirEl((k));
        lista->add(static_cast<Entidade*>(k));
        inimigos->add(static_cast<Entidade*>(k));
    }*/
    int verif;
    verif = rand() % 4;
    if (verif == 1) {
        Pedra* k = new Pedra(1736, 280);
        lista->add(k);
        inimigos->add(k);
    }
    verif = rand() % 4;
    if (verif == 1) {
        Pedra* k = new Pedra(2368, 200);
        lista->add(k);
        inimigos->add(k);
    }
    verif = rand() % 4;
    if (verif == 1) {
        Pedra* k = new Pedra(3302, 300);
        lista->add(k);
        inimigos->add(k);
    }
    Trepadeira* p1 = new Trepadeira(1072, 100);
    lista->add(p1);
    inimigos->add(p1);
    Pedra* p2 = new Pedra(2056, 300);
    lista->add(p2);
    inimigos->add(p2);
    Pedra* p3 = new Pedra(2632, 300);
    lista->add(p3);
    inimigos->add(p3);
}

sf::Music* Fase1::getMusica() { return f1; }
