#include "Jogo.h"

Jogo::Jogo() {
	graf = GerenciadorGrafico::getGerenciadorGrafico();
	pEvent = GerenciadorEvento::getGerenciadorEvento();
	pColi = new GerenciadorColisao();
	resumir = new Resumir(&menuopc);
	bfase1 = new BFase1(&menuopc);
	sair = new Sair(&menuopc);

	pEvent->setPGraf(graf);

	criaFase1();

}

Jogo::~Jogo() {
	delete pColi;
	//delete graf;
	//delete pEvent;
}

void Jogo::executar() {
	int i;
	while(graf->verifJanelaAberta())
	{

		i = menuopc.executar();

		switch(i)
		{
			case 1:
			{
				graf->fecharJanela();
			}
			break;

			case 2:
			{
				menuopc.getFase1()->executar();
			}
			break;

			case 3:
			{
		
			}
			break;

			default:
			{
				
			}
			break;
		}
	}
}

void Jogo::criaFase1()
{

	Fase1* f;
	f = new Fase1();
	
	pColi->setInimigos(f->getInimigos());
	pColi->setJogador(f->getJogador1());
	pColi->setMapa(f->getMapa2());
	pEvent->setJogador(f->getJogador1());
	menuopc.setFase1(f);

}