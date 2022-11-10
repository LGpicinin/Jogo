#pragma once

#include "Elemento.h"

template <class TIPO>
class Lista
{
  private:
    Elemento<TIPO> *primeiro;
    Elemento<TIPO> *ultimo;
    int cont;

  public:
    Lista();
    ~Lista();
    void incluirEl(TIPO *elemento);
    void removeEl(Elemento<TIPO>* elemento);
    Elemento<TIPO>* getPrimeiro();
    Elemento<TIPO>* getElX(int x);
    int getTam();
};





template <class TIPO>
Lista<TIPO>::Lista()
{
  primeiro = NULL;
  ultimo = NULL;
  cont = 0;
}

template <class TIPO>
Lista<TIPO>::~Lista()
{
  Elemento<TIPO> *aux;

  while(primeiro!=NULL)
    {
      aux = primeiro;
      primeiro = primeiro->getProximo();
      delete(aux);
    }
  cont = 0;
}

template <class TIPO>
void Lista<TIPO>::incluirEl(TIPO *elemento)
{
  
    Elemento<TIPO> *aux=NULL;
    
    aux = new Elemento<TIPO>();
    aux->setInfo(elemento);
    if(primeiro==NULL)
    {
      primeiro = aux;
      ultimo = aux;
      cont++;
    }
    else
    {
      ultimo->setProximo(aux);
      ultimo = ultimo->getProximo();
      cont++;
    }
  
}



template<class TIPO>
void Lista<TIPO>::removeEl(Elemento<TIPO>* elemento)
{
  Elemento<TIPO>  *anterior, *proximo;
  anterior = elemento->getAnterior();
  proximo = elemento->getProximo();
  anterior->setProximo(proximo);
  proximo->setAnterior(anterior);
  delete elemento;
  cont--;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
  return primeiro;
}

template <class TIPO>
int Lista<TIPO>::getTam() { return cont; }

template <class TIPO>
Elemento<TIPO>* Lista<TIPO>::getElX(int x) {
    int c = 1;
    Elemento<TIPO>* it = getPrimeiro();
    while (c < x) {
        it = it->getProximo();
        c++;
    }
    return it;
}