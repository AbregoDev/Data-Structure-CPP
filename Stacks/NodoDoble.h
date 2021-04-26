#include <iostream>

typedef int Tipo;

class NodoDoble
{
private:
   Tipo dato;
   NodoDoble *siguiente;
   NodoDoble *anterior;

public:
   NodoDoble();
   NodoDoble(Tipo dato);
   Tipo getDato();
   void setDato(Tipo dato);
   NodoDoble *getSiguiente();
   void setSiguiente(NodoDoble *siguiente);
   NodoDoble *getAnterior();
   void setAnterior(NodoDoble *anterior);
};

NodoDoble::NodoDoble()
{
   NodoDoble::dato = 0;
   NodoDoble::siguiente = NULL;
   NodoDoble::anterior = NULL;
}

NodoDoble::NodoDoble(Tipo dato)
{
   NodoDoble::dato = dato;
   NodoDoble::siguiente = NULL;
   NodoDoble::anterior = NULL;
}

Tipo NodoDoble::getDato()
{
   return dato;
}

void NodoDoble::setDato(Tipo dato)
{
   NodoDoble::dato = dato;
}

NodoDoble *NodoDoble::getSiguiente()
{
   return NodoDoble::siguiente;
}

void NodoDoble::setSiguiente(NodoDoble *siguiente)
{
   NodoDoble::siguiente = siguiente;
}

NodoDoble *NodoDoble::getAnterior()
{
   return NodoDoble::anterior;
}

void NodoDoble::setAnterior(NodoDoble *anterior)
{
   NodoDoble::anterior = anterior;
}