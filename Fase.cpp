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
    j2 = NULL;
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

void Fase::geraOnca(float x, float y)
{

    Onca* inimigo;
    inimigo = new Onca(j1, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraArara(float x, float y)
{

    Arara *inimigo;
    inimigo = new Arara(j1, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraPedra(float x, float y)
{
    Pedra* p2 = new Pedra(x, y);
    lista->add(p2);
    inimigos->add(p2);
}

void Fase::geraEspinhos(float x, float y, int tam)
{
    Espinho* e1 = new Espinho(x, y, tam);
    lista->add(e1);
    inimigos->add(e1);
}


GerenciadorEvento* Fase::getEvent() { return pEvent; }