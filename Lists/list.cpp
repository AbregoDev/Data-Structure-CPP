#include <iostream>
#include "Nodo.h"
using namespace std;

class Lista
{
   Nodo *cabeza;

   public: Lista()
   {
      cabeza = NULL;
   }

   public: void insertarAlPrincipio(Tipo dato)
   {
      Nodo *nuevoNodo = new Nodo(dato);
      nuevoNodo->setSiguiente(cabeza);
      cabeza = nuevoNodo;
   }

   public: void insertarAlFinal(Tipo dato)
   {
      Nodo *nuevoNodo = new Nodo(dato);
      Nodo *aux = cabeza;

      while(aux != NULL)
      {
         if(aux->getSiguiente() == NULL)
         {
            // Llegué al último nodo
            aux->setSiguiente(nuevoNodo);
            break;
         }
         else
         {
            aux = aux->getSiguiente();
         }
      }
   }

   public: int buscarElemento(Tipo elementoBuscado)
   {
      Nodo *aux = cabeza;
      int indice = 0;
      while(aux != NULL)
      {
         if(aux->getDato() == elementoBuscado)
         {
            break;
         }
         else
         {
            aux = aux->getSiguiente();
            indice++;
         }
      }

      if(aux == NULL)
      {
         // Nunca encontró el elemento
         indice = -1;
      }

      return indice;
   }
   
   public: Tipo busquedaPorIndice(int indice)
   {
      Nodo *aux = cabeza;
      int controlIndice = 0;

      while(controlIndice < indice)
      {
         aux = aux->getSiguiente();
         controlIndice++;

         if(aux = NULL)
         {
            // Lanzar error
         }
      }

      return aux->getDato();
   }

   public: void imprimir()
   {
      Nodo *aux = cabeza;

      while(aux != NULL)
      {
         cout << aux->getDato() << " ";
         aux = aux->getSiguiente();
      }
      cout << endl;
   }
};

int main()
{
   Lista *lista = new Lista();

   lista->insertarAlPrincipio(8);
   lista->insertarAlPrincipio(10);
   lista->insertarAlPrincipio(3);
   lista->insertarAlFinal(2);
   lista->insertarAlPrincipio(3);
   lista->insertarAlPrincipio(1);
   lista->insertarAlFinal(9);
   lista->insertarAlFinal(5);
   lista->insertarAlPrincipio(0);
   lista->insertarAlFinal(7);
   lista->insertarAlPrincipio(1);
   lista->insertarAlFinal(15);

   lista->imprimir();

   cout << "Lista[4]: " << lista->busquedaPorIndice(4) << endl;
   cout << "Lista[7]: " << lista->busquedaPorIndice(7) << endl;
   cout << "Lista[2]: " << lista->busquedaPorIndice(2) << endl;
   //cout << "Lista[3000]: " << lista->busquedaPorIndice(3000) << endl;
}