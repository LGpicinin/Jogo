#include "ListaEntes.h"

ListaEntes::ListaEntes() {}

ListaEntes::~ListaEntes() {
}


void ListaEntes::add(Entidade* x) {
	lista.incluirEl(x);
}


void ListaEntes::remover(Entidade* x) 
{
	Elemento<Entidade>* aux;
	aux = procuraEl(x->getId());

	if(aux==NULL)
		cout << "Elemento nao encontrado" << endl;

	else
		lista.removeEl(aux);
}


Elemento<Entidade>* ListaEntes::procuraEl(int i)
{
	if(lista.getPrimeiro()!=NULL)
	{
		Elemento<Entidade>* aux;
		Entidade* tipo;
		aux = lista.getPrimeiro();
		tipo = aux->getInfo();

		while(tipo->getId()!=i && aux->getProximo()!=NULL)
		{
			aux = aux->getProximo();
			tipo = aux->getInfo();
		}
		if(tipo->getId()!=i)
		{
			aux = NULL;
		}
		return aux;
	}
	return NULL;
}

void ListaEntes::reposLista(float x, float y)
{
	Elemento<Entidade> *aux;
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
	Elemento<Entidade> *aux;
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