#include <iostream>

class NodoArbol
{
   private:
      NodoArbol *subarbolIzq;
      NodoArbol *subarbolDer;
      int dato;

   public:
      NodoArbol(int n);
      NodoArbol(int n, NodoArbol *subIzq, NodoArbol *subDer);
      int getDato();
      void setDato(int n);
      NodoArbol *&getIzquierdo();
      void setIzquierdo(NodoArbol *izquierdo);
      NodoArbol *&getDerecho();
      void setDerecho(NodoArbol *derecho);
};

NodoArbol::NodoArbol(int n) {
   dato = n;
   subarbolIzq = NULL;
   subarbolDer = NULL;
}

NodoArbol::NodoArbol(int n, NodoArbol *subIzq, NodoArbol *subDer) {
   dato = n;
   subarbolIzq = subIzq;
   subarbolDer = subDer;
}

int NodoArbol::getDato()
{
   return dato;
}

void NodoArbol::setDato(int n)
{
   dato = n;
}

NodoArbol *&NodoArbol::getIzquierdo()
{
   return subarbolIzq;
}

void NodoArbol::setIzquierdo(NodoArbol *izquierdo)
{
   subarbolIzq = izquierdo;
}

NodoArbol *&NodoArbol::getDerecho()
{
   return subarbolDer;
}

void NodoArbol::setDerecho(NodoArbol *derecho)
{
   subarbolDer = derecho;
}