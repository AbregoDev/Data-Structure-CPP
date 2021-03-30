#include <iostream>
#include "Nodo.h"
using namespace std;

enum ErroresListas
{
   INDEX_OUT_OF_RANGE,
   EMPTY_LIST,
};

class Lista
{
   Nodo *cabeza;
   Nodo *ultimo;

   public: Lista()
   {
      cabeza = NULL;
      ultimo = NULL;
   }

   public: void insertarAlPrincipio(Tipo dato)
   {
      Nodo *nuevoNodo = new Nodo(dato);

      if(!estaVacia())
      {   
         nuevoNodo->setSiguiente(cabeza);
         cabeza = nuevoNodo;
      }
      else
      {
         cabeza = nuevoNodo;
         ultimo = nuevoNodo;
      }
   }

   public: void insertarAlFinal(Tipo dato)
   {
      Nodo *nuevoNodo = new Nodo(dato);
      
      if(!estaVacia())
      {
         ultimo->setSiguiente(nuevoNodo);
         ultimo = nuevoNodo;
      }
      else
      {
         cabeza = nuevoNodo;
         ultimo = nuevoNodo;
      }
   }

   public: void insertarEnPosicion(Tipo dato, int posicion)
   {
      Nodo *nuevoNodo = new Nodo(dato);
      if(!estaVacia())
      {
         Nodo *aux = cabeza;
         int indice = 0;

         while(indice < posicion - 1)
         {
            aux = aux->getSiguiente();
            indice++;

            if(aux == NULL)
            {
               throw INDEX_OUT_OF_RANGE;
            }
         }

         if(posicion == 0)
         {
            insertarAlPrincipio(dato);
         }
         else
         {
            Nodo *siguiente = aux->getSiguiente();  
            aux->setSiguiente(nuevoNodo);
            nuevoNodo->setSiguiente(siguiente);

            // Alternativa
            // nuevoNodo->setSiguiente(aux->getSiguiente());
            // aux->setSiguiente(nuevoNodo);
         }
      }
      else
      {
         cabeza = nuevoNodo;
         ultimo = nuevoNodo;
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
   
   public: Tipo buscarPorIndice(int indice)
   {
      if(!estaVacia())
      {
         Nodo *aux = cabeza;
         int controlIndice = 0;

         while(controlIndice < indice)
         {
            aux = aux->getSiguiente();
            controlIndice++;

            if(aux == NULL)
            {
               throw INDEX_OUT_OF_RANGE;
            }
         }

         return aux->getDato();
      }
      else
      {
         throw EMPTY_LIST;
      }
   }

   public: bool estaVacia()
   {
      return cabeza == NULL;
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

   try
   {
      char opc;
      int n, p, i, e;

      do
      {
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "1: Insertar al principio" << endl;
         cout << "2: Insertar al final" << endl;
         cout << "3: Insertar en posicion" << endl;
         cout << "4: Buscar por incidencia" << endl;
         cout << "5: Buscar por indice" << endl;
         // cout << "6: Eliminar por incidencia" << endl;
         cout << "0: Salir" << endl;
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "Opcion: ";

         cin >> opc;
         fflush(stdin);

         switch (opc)
         {
         case '1':
            cout << "Numero a insertar: ";
            cin >> n;
            lista->insertarAlPrincipio(n);
            lista->imprimir();
            break;

         case '2':
            cout << "Numero a insertar: ";
            cin >> n;
            lista->insertarAlFinal(n);
            lista->imprimir();
            break;

         case '3':
            cout << "Numero a insertar: ";
            cin >> n;
            cout << "Posicion en la que insertar: ";
            cin >> p;
            lista->insertarEnPosicion(n, p);
            lista->imprimir();
            break;

         case '4':
            cout << "Numero a buscar: ";
            cin >> n;
            e = lista->buscarElemento(n);
            cout << "Posicion: " << e << endl;
            break;

         case '5':
            cout << "Posicion a obtener: ";
            cin >> i;
            e = lista->buscarPorIndice(i);
            cout << "Elemento: " << e << endl;
            break;

         // case '6':
         //    cout << "Numero a eliminar: ";
         //    cin >> n;
         //    lista->eliminarElemento(n);
         //    lista->imprimir();
         //    break;
         
         default:
            opc = '0';
            cout << "Ha sido un placer atenderle" << endl;
            break;
         }
      } while(opc != '0');
   }
   catch(ErroresListas exc)
   {
      switch (exc)
      {
      case INDEX_OUT_OF_RANGE:
         cout << "Indice no valido" << endl;
         break;

      case EMPTY_LIST:
         cout << "La lista esta vacia" << endl;
         break;
      
      default:
         cout << "Otro error" << endl;
         break;
      }
   }
}