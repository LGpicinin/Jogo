#include "Jogo.h"

Jogo::Jogo() {
	graf = GerenciadorGrafico::getGerenciadorGrafico();
	pEvent = GerenciadorEvento::getGerenciadorEvento();
	menuopc = new Menu();
	Fase1* f = menuopc->getFase1();
	f = new Fase1();
	pColi = new GerenciadorColisao(f->getInimigos(), f->getMapa2(), f->getJogador1());
	pEvent->setJogador(f->getJogador1());
	pEvent->setPGraf(graf);
	resumir = new Resumir(menuopc);
	bfase1 = new BFase1(menuopc);
	sair = new Sair(menuopc);
	menuopc->setBFase1(bfase1);
	menuopc->setResumir(resumir);
	menuopc->setSair(sair);
	menuopc->setFase1(f);
	menuopc->executar();
}

Jogo::~Jogo() {
	delete menuopc;
	delete pColi;
	//delete graf;
	//delete pEvent;
	delete resumir;
	delete bfase1;
	delete sair;
}

void Jogo::executar() {
	if (menuopc->getFase1()) menuopc->getFase1()->executar();
}