#pragma once
#include "Entidade.h"
#include <list>
using namespace std;

class ListaEntes {
private:
	list<Entidade*> Lista;

public:
	ListaEntes();
	~ListaEntes();
	void add(Entidade* x);
	void remover(Entidade* x);
	list<Entidade*>* getLista() { return &Lista; }
};