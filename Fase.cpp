#include "Fase.h"

using namespace Fases;

Fase::Fase() {
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
    //obs = NULL;
}

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e)
{
    pColi = c;
    pGraf = g;
    lista = NULL;
    pEvent = e;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
    //obs = NULL;
}

Fase::~Fase()
{
    mapa2->~Mapa();
    delete pColi;
    delete lista;
    delete j1;
    delete inimigos;
    delete j2;
    pEvent = NULL;
    pGraf = NULL;
}

void Fase::setJogador1(Jogador *j)
{
    j1 = j;
}
void Fase::setJogador2(Jogador *j)
{
    j2 = j;
}

void Fase::setEntes(ListaEntes *l)
{
    lista = l;
}

void Fase::setInimigos(ListaEntes *i)
{
    inimigos =i;
}

void Fase::setMapa2(Mapa* m) { mapa2 = m; }

Mapa* Fase::getMapa2() { return mapa2; }

void Fase::setColi(GerenciadorColisao* c) { pColi = c; }

void Fase::setEvent(GerenciadorEvento* e) { pEvent = e; }

void Fase::setGraf(GerenciadorGrafico* g) { pGraf = g; }

ListaEntes* Fase::getLista() { return lista; }

ListaEntes* Fase::getInimigos() { return inimigos; }

Jogador* Fase::getJogador1() { return j1; }

Jogador* Fase::getJogador2() { return j2; }

void Fase::geraOnca(float x, float y)
{

    Onca* inimigo;
    inimigo = new Onca(j1, j2, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraArara(float x, float y)
{

    Arara *inimigo;
    inimigo = new Arara(j1, j2, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraPedra(float x, float y)
{
    Pedra* p2 = new Pedra(x, y);
    lista->add(static_cast<Entidade*>(p2));
    inimigos->add(static_cast<Entidade*>(p2));
}
void Fase::geraEspinho(float x, float y, int tam)
{
    Espinho* e1 = new Espinho(x, y, tam);
    lista->add(static_cast<Entidade*>(e1));
    inimigos->add(static_cast<Entidade*>(e1));
}


GerenciadorEvento* Fase::getEvent() { return pEvent; }

void Fase::moveLista()
{
    int contador;

    pColi->executar();
    pEvent->executar();

    for(contador=1; contador<lista->getLista()->getTam() + 1; contador++)
	{
        if (lista->getLista()->getElX(contador)->getInfo()->getVivo() == false) continue;
		lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
	}
}