#include <iostream>
#include "Nodo.h"
using namespace std;

enum ErroresListas
{
   INDEX_OUT_OF_RANGE,
   EMPTY_LIST,
};

class ListaCircular
{
private:
   Nodo *cabeza;
   Nodo *ultimo;

public:
   ListaCircular();
   void insertarAlPrincipio(Tipo dato);
   void insertarAlFinal(Tipo dato);
   void insertarEnPosicion(Tipo dato, int indice);
   int buscarElemento(Tipo elementoBuscado);
   Tipo buscarPorIndice(int indice);
   void eliminarElemento(Tipo elemento);
   void eliminarPorIndice(int posicion);
   bool estaVacia();
   void imprimir();
};

ListaCircular::ListaCircular()
{
   // Inicializar en nulos
   cabeza = NULL;
   ultimo = NULL;
}

void ListaCircular::insertarAlPrincipio(Tipo dato)
{
   Nodo *nuevoNodo = new Nodo(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo al principio
      nuevoNodo->setSiguiente(cabeza);
      // El siguiente del último elemento ahora es el nuevo nodo
      ultimo->setSiguiente(nuevoNodo);
      // La cabeza ahora apunta al nuevo nodo
      cabeza = nuevoNodo;
   }
   else
   {
      // La lista está vacía
      // El nuevo nodo es la cabeza y el último
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
      // El siguiente de la cabeza es ella misma
      cabeza->setSiguiente(cabeza);
   }
}

void ListaCircular::insertarAlFinal(Tipo dato)
{
   Nodo *nuevoNodo = new Nodo(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo en el siguiente del último
      ultimo->setSiguiente(nuevoNodo);
      // El siguiente del nuevo nodo es el primero
      nuevoNodo->setSiguiente(cabeza);
      // El último ahora apunta al nuevo nodo
      ultimo = nuevoNodo;
   }
   else
   {
      // La lista está vacía
      // El nuevo nodo es la cabeza y el último
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
      // El siguiente de la cabeza es ella misma
      cabeza->setSiguiente(cabeza);
   }
}

void ListaCircular::insertarEnPosicion(Tipo dato, int indice)
{
   Nodo *nuevoNodo = new Nodo(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Auxiliar para recorrer la lista
      Nodo *aux = cabeza;
      // Indice para controlar la posicion
      int controlIndice = 0;

      // Recorrer la lista y detenerse en el índice anterior
      // a la posición en la que se va a insertar
      while (controlIndice < indice - 1)
      {
         // Avanzar al siguiente nodo
         aux = aux->getSiguiente();
         // El controlador del indice avanza
         controlIndice++;

         // El auxiliar nunca es nulo, por lo que puede recorrerse
         // el ciclo las veces solicitadas
      }

      // Si el índice solicitado es el cero, o de manera equivalente
      // el auxiliar sigue apuntando a la cabeza
      // significa que hay que insertar al principio
      if (aux->getSiguiente() == cabeza)
      {
         insertarAlPrincipio(dato);
      }
      // Si el auxiliar está apuntando al último
      // hay que insertar al final el nuevo nodo
      else if (aux->getSiguiente() == ultimo)
      {
         insertarAlFinal(dato);
      }
      // En el último caso, se debe insertar "en medio"
      else
      {
         // Guardar la referencia del siguiente en otro puntero
         Nodo *siguiente = aux->getSiguiente();
         // El siguiente del auxiliar será el nuevo nodo
         // pues el auxiliar es el elemento inmediatamente anterior
         aux->setSiguiente(nuevoNodo);
         // Hay que conectar el siguiente del nuevo nodo
         // con la referencia guardada anteriormente
         nuevoNodo->setSiguiente(siguiente);

         // Alternativa
         // nuevoNodo->setSiguiente(aux->getSiguiente());
         // aux->setSiguiente(nuevoNodo);
      }
   }
   // La lista está vacía, el elemento se insertará como el único
   else
   {
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
      // Enlazar el elemento consigo mismo
      cabeza->setSiguiente(cabeza);
   }
}

int ListaCircular::buscarElemento(Tipo elementoBuscado)
{
   if (!estaVacia())
   {
      // Auxiliar para recorrer la lista
      Nodo *aux = cabeza;
      // variable para controlar el índice
      int controlIndice = 0;

      // Recorrer la lista mientras el elemento no sea nulo
      do
      {
         // Si el dato del auxiliar consiste con el elemento
         // que se está buscando, terminar el ciclo
         if (aux->getDato() == elementoBuscado)
         {
            break;
         }
         // Si no coincide, avanzar al siguiente nodo
         else
         {
            aux = aux->getSiguiente();
            controlIndice++;
         }
      } while (aux != cabeza);
      // Si al finalizar el ciclo el el dato del auxiliar no coincide
      // entonces no se encontró el elemento
      if (aux->getDato() != elementoBuscado)
      {
         // Devolver un -1 indicando que no se encontró
         controlIndice = -1;
      }

      // Finalmente, devolver el índice
      return controlIndice;
   }
   // La lista está vacía
   else
   {
      return -1;
   }
}

Tipo ListaCircular::buscarPorIndice(int indice)
{
   // Si la lista no está vacía, ejecutar el algoritmo
   if (!estaVacia())
   {
      // Auxiliar para recorrer la lista
      Nodo *aux = cabeza;
      // Variable de control del índice
      int controlIndice = 0;

      // Mientras el control del índice sea menor al
      // índice solicitado, ejecutar
      while (controlIndice < indice)
      {
         // Avanzar al siguiente nodo
         aux = aux->getSiguiente();
         controlIndice++;

         // El auxiliar nunca es nulo, por lo que se puede
         // interar indefinidamente
      }

      // Si el ciclo se terminó correctamente, devolver el dato
      // de la posición alcanzada
      return aux->getDato();
   }
   // La lista está vacía, devolver un error
   else
   {
      throw EMPTY_LIST;
   }
}

void ListaCircular::eliminarElemento(Tipo elemento)
{
   // La lista tiene elementos
   if (!estaVacia())
   {
      // Nodo auxiliar para recorrer la lista
      Nodo *aux = cabeza;
      // El nodo que precede al anterior
      Nodo *anterior = NULL;

      // Ciclo para recorrer la lista
      do
      {
         // Si el dato del nodo es igual al elemento que
         // se quiere eliminar, se rompe el ciclo
         if (aux->getDato() == elemento)
         {
            break;
         }
         // En caso contrario, avanzar al siguiente nodo
         else
         {
            anterior = aux;
            aux = aux->getSiguiente();
         }
      } while (aux != cabeza);

      // Al finalizar el nodo, se verifica si se halló
      // el elemento, y se procede a eliminar en función
      // de la posición
      if (aux->getDato() == elemento)
      {
         // El elemento está al principio
         if (aux == cabeza)
         {
            // La cabeza ahora apunta al siguiente
            cabeza = aux->getSiguiente();
            // el siguiente del último debe apuntar
            // a la nueva cabeza
            ultimo->setSiguiente(cabeza);
         }
         // El elemento está al final
         else if (aux == ultimo)
         {
            // El elemento anterior ya no apunta al
            // nodo que se va a eliminar, sino a la cabeza
            anterior->setSiguiente(cabeza);
            // El último ahora apunta al anterior
            ultimo = anterior;
         }
         else
         {
            // Guardar la referencia al siguiente elemento
            Nodo *siguiente = aux->getSiguiente();
            // El siguiente del anterior, será el siguiente del
            // nodo que se eliminará
            anterior->setSiguiente(siguiente);
         }
         // Liberar el espacio que utilizaba el nodo eliminado
         delete aux;
      }
      else
      {
         cout << "No se encontro el elemento" << endl;
      }
   }
   // La lista está vacía, lanzar un error
   else
   {
      throw EMPTY_LIST;
   }
}

void ListaCircular::eliminarPorIndice(int posicion)
{
   if (!estaVacia())
   {
      Nodo *aux = cabeza;
      Nodo *anterior = NULL;
      int indiceControl = 0;

      while (indiceControl < posicion)
      {
         anterior = aux;
         aux = aux->getSiguiente();
         indiceControl++;
      }

      // El elemento está al principio
      if (aux == cabeza)
      {
         // La cabeza ahora apunta al siguiente
         cabeza = aux->getSiguiente();
         // el siguiente del último debe apuntar
         // a la nueva cabeza
         ultimo->setSiguiente(cabeza);
      }
      // El elemento está al final
      else if (aux == ultimo)
      {
         // El elemento anterior ya no apunta al
         // nodo que se va a eliminar, sino a la cabeza
         anterior->setSiguiente(cabeza);
         // El último ahora apunta al anterior
         ultimo = anterior;
      }
      else
      {
         // Guardar la referencia al siguiente elemento
         Nodo *siguiente = aux->getSiguiente();
         // El siguiente del anterior, será el siguiente del
         // nodo que se eliminará
         anterior->setSiguiente(siguiente);
      }
      // Liberar el espacio que utilizaba el nodo eliminado
      delete aux;
   }
   else
   {
      throw EMPTY_LIST;
   }
}

bool ListaCircular::estaVacia()
{
   // Si la cabeza es nula, significa que no hay datos
   return cabeza == NULL;
}

void ListaCircular::imprimir()
{
   // Imprimir solo si la lista no está vacía
   if (!estaVacia())
   {
      // Declarar un nodo auxiliar para recorrer la lista
      // empezando por la cabeza;
      Nodo *aux = cabeza;
      // Dado que la lista no está vacía, hay al menos un elemento
      // Por ello se ejecuta un do-while
      do
      {
         // Imprimir el dato y el separador
         cout << aux->getDato() << ", ";
         // Avanzar al siguiente nodo
         aux = aux->getSiguiente();
         // El ciclo finalizará cuando el auxiliar
         // apunte nuevamente a la cabeza
      } while (aux != cabeza);
      // Imprimir el final de línea
      cout << endl;
   }
}