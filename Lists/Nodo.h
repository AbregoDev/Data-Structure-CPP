#include <iostream>

typedef int Tipo;

class Nodo
{
   private:
      Tipo dato;
      Nodo *siguiente;

   public:
      Nodo();
      Nodo(int dato);
      int getDato();
      void setDato(int dato);
      Nodo *getSiguiente();
      void setSiguiente(Nodo *siguiente);
};

Nodo::Nodo()
{
   Nodo::dato = 0;
   Nodo::siguiente = NULL;
}

Nodo::Nodo(int dato)
{
   Nodo::dato = dato;
   Nodo::siguiente = NULL;
}

int Nodo::getDato()
{
   return dato;
}

void Nodo::setDato(int dato)
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