#include "Fase1.h"

Fase1::Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e):
Fase(c, g, e)
{
    
}

Fase1::Fase1(): Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();

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
    geraOnca();

    pEvent->setJogador(j1);
    pColi = new GerenciadorColisao(inimigos, mapa2, j1);

    f1->play();
}

Fase1::~Fase1(){
    mapa2->~Mapa();
    delete f1;
    delete pColi;
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
        pGraf->limpaJanela();
	    mapa2->imprimir();
		lista->desenhaLista();
		pGraf->mostraElementos();
    }
}

void Fase1::geraOnca()
{
    srand(time(NULL));
    float x;
    float y;
    int verif;
    int lim = 0;
    int contador = 0;
    x = 200;
    y = 100;
    while (lim < 10 || contador<3)
    {
        verif = rand()%2;
        if (verif == 1)
        {
            Onca* inimigo;
            inimigo = new Onca(j1, x, y);
            //inimigo->setGerente(graf);
            inimigos->add(static_cast<Entidade*>(inimigo));
            lista->add(static_cast<Entidade*>(inimigo));
            contador++;
        }
        lim++;
        x = x+200;
    }
}