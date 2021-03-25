#include <iostream>
using namespace std;

class Nodo
{
   int dato;
   Nodo *siguiente;

   public: Nodo() { }

   public: Nodo(int dato)
   {
      Nodo::dato = dato;
   }

   public: int getDato()
   {
      return dato;
   }

   public: void setDato(int dato)
   {
      Nodo::dato = dato;
   }

   public: Nodo *getSiguiente()
   {
      return siguiente;
   }

   public: void setSiguiente(Nodo *siguiente)
   {
      Nodo::siguiente = siguiente;
   }
};

class Lista
{
   Nodo *cabeza;

   public: Lista()
   {
      cabeza = NULL;
   }

   public: void insertarAlPrincipio(int dato)
   {
      Nodo *nuevoNodo = new Nodo(dato);
      nuevoNodo->setSiguiente(cabeza);
      cabeza = nuevoNodo;
   }

   public: Nodo *getCabeza()
   {
      return cabeza;
   }
};

int main()
{
   Lista *lista = new Lista();

   lista->insertarAlPrincipio(8);
   lista->insertarAlPrincipio(10);
   lista->insertarAlPrincipio(3);
   
   // [5, 10, 8]
}