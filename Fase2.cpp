#include "Fase2.h"
#include "Pedra.h"

using namespace Fases;

Fase2::Fase2(GerenciadorColisao* c, GerenciadorGrafico* g, GerenciadorEvento* e) :
    Fase(c, g, e)
{

}

Fase2::Fase2() : Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

    f1 = new sf::Music();
    f1->openFromFile("Midia/Musicas/S8M4.ogg");
    f2 = new sf::Music();
    f2->openFromFile("Midia/Musicas/S9M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase2.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(4192.0f, 32.0f), sf::Vector2f(12768.0f, 1792.0f));
    mapa2 = mapa;
    cout << "O mapa foi criado.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    j1 = new Jogador();
    j1->setMapa2(mapa2);
    j1->setPos(4320, 800);
    

    pGraf = GerenciadorGrafico::getGerenciadorGrafico();
    pEvent = GerenciadorEvento::getGerenciadorEvento();
    pGraf->setView(sf::Vector2f(4320, 800));

    lista->add(static_cast<Entidade*>(j1));
    geraInimigos();
    geraObstaculos();
    /*Pedra* p1 = new Pedra(150, 150);
    lista->add(p1);
    inimigos->add(p1);
    Pedra* p2 = new Pedra(500, 100);
    lista->add(p2);
    inimigos->add(p2);*/

    pEvent->setJogador(j1);
    pColi = new GerenciadorColisao(inimigos, mapa2, j1);

    f1->play();
}

Fase2::~Fase2() {
    delete f1;
    delete f2;
}

void Fase2::executar()
{
    float legacy = 0.0, atual = 0.0;
    int contador;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();


    while (j1->getVidas() > 0 && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        pColi->executar();
        pEvent->executar();
        //legacy = j1->getMapa()->getincx();
        for (contador = 1; contador < lista->getLista()->getTam() + 1; contador++)
        {
            if (lista->getLista()->getElX(contador)->getInfo()->getVivo() == false) continue;
            lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
        }
        if (j1->getPos().x >= 12086 && f1->getStatus() == sf::Music::Playing) {
            f1->stop();
            f2->play();
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
    std::cout << "O loop de execucao da fase terminou.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if (f1->getStatus() == sf::Music::Playing) f1->pause();
    else if (f2->getStatus() == sf::Music::Playing) f2->pause();
}

void Fase2::geraInimigos()
{

    srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
    Curupira* c;
    geraOnca(4830, 888);
    geraOnca(7912, 472);
    geraOnca(9110, 855);
    geraOnca(9286, 855);
    geraOnca(9526, 728);
    geraOnca(12142, 823);
    geraOnca(12342, 823);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5382, 950);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5816, 792);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6382, 500);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6630, 300);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6912, 438);
    verif = rand() % 4;
    if (verif == 1) geraOnca(8110, 920);
    verif = rand() % 4;
    if (verif == 1) geraOnca(9406, 1496);
    verif = rand() % 4;
    if (verif == 1) geraOnca(10126, 728);
    /*while (lim < 9 || contador < 3)
    {
        verif = rand() % 4;
        if (verif == 1)
        {
            geraOnca(x, y);
            contador++;
        }
        else if (verif == 3)
        {
            contador++;
        }
        lim++;
        x = x + 225;
    }*/
    c = geraCurupira(12598, 800);

    inimigos->add(static_cast<Entidade*>(c->getFogo()));
    lista->add(static_cast<Entidade*>(c->getFogo()));

    c->setLista(inimigos);

}

void Fase2::geraObstaculos() {
    srand(time(NULL));
    /*for (int i = 1; i <= 10; i++) {
        int p = rand() % 50 + 30;
        Pedra* k = new Pedra(p * 32, 90);
        //obs->incluirEl((k));
        lista->add(static_cast<Entidade*>(k));
        inimigos->add(static_cast<Entidade*>(k));
    }*/
    
}

Curupira* Fase2::geraCurupira(float x, float y)
{
    Curupira *inimigo;
    inimigo = new Curupira(j1, x, y);

    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

    return inimigo;
}

sf::Music* Fase2::getMusica() { return f1; }