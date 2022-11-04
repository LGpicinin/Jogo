#include "ListaEntes.h"

ListaEntes::ListaEntes() {}

ListaEntes::~ListaEntes() {
	int cont = 1;
	list<Entidade*>::iterator it;
	for (it = Lista.begin(); cont <= Lista.size(); it++) {
		Lista.erase(it);
		cont++;
	}
	Lista.clear();
	//it = Lista.begin();
	/*do {
		Lista.remove(*it);
		it++;
	} while (it != Lista.end());
	Lista.clear();
	/*Ente** it = &Lista.front();
	while (it != NULL) {
		Lista.erase(*it);
		it++;
	}*/
}

void ListaEntes::add(Entidade* x) {
	Lista.push_back(x);
}

void ListaEntes::remover(Entidade* x) {
	list<Entidade*>::iterator it;
	for (it = Lista.begin(); *it != x && it != Lista.end(); it++);
	if (it == Lista.end());
	else {
		Lista.remove(*it);
	}
}