#include <iostream>

typedef int Tipo;

class Nodo
{
private:
   Tipo dato;
   Nodo *siguiente;

public:
   Nodo();
   Nodo(Tipo dato);
   Tipo getDato();
   void setDato(Tipo dato);
   Nodo *getSiguiente();
   void setSiguiente(Nodo *siguiente);
};

Nodo::Nodo()
{
   Nodo::dato = 0;
   Nodo::siguiente = NULL;
}

Nodo::Nodo(Tipo dato)
{
   Nodo::dato = dato;
   Nodo::siguiente = NULL;
}

Tipo Nodo::getDato()
{
   return dato;
}

void Nodo::setDato(Tipo dato)
{
   Nodo::dato = dato;
}

Nodo *Nodo::getSiguiente()
{
   return Nodo::siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente)
{
   Nodo::siguiente = siguiente;
}