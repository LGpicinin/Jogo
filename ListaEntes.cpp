#include "ListaEntes.h"

ListaEntes::ListaEntes() {}

ListaEntes::~ListaEntes() {}


void ListaEntes::add(Entidade* x) {
	lista.incluirEl(x);
}

void ListaEntes::reposLista(float x, float y)
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade* info;
	aux = lista.getPrimeiro();

	while(aux!=NULL)
	{
		info = aux->getInfo();
		info->repos(x,y);
		aux = aux->getProximo();
	}
}

void ListaEntes::desenhaLista()
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade* info;

	aux = lista.getPrimeiro();

	while(aux!=NULL)
	{
		info = aux->getInfo();
		
		
			info->imprimir();

		aux = aux->getProximo();
	}
}

Lista<Entidade>* ListaEntes::getLista() { return &lista; }