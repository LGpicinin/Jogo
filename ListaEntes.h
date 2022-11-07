#pragma once

#include "Entidade.h"
#include "Lista.h"
#include "Elemento.h"
#include <iostream>

using namespace std;

class ListaEntes {
private:
	Lista<Entidade> lista;

public:
	ListaEntes();
	~ListaEntes();
	void add(Entidade* x);
	void remover(Entidade* x);
	Elemento<Entidade>* procuraEl(int i);
	void reposLista(float x, float y);
	void desenhaLista();
	Lista<Entidade>* getLista();
};