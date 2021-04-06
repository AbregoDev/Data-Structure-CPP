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
private:
   Nodo *cabeza;
   Nodo *ultimo;

public:
   Lista();
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

Lista::Lista()
{
   // Inicializar en nulos
   cabeza = NULL;
   ultimo = NULL;
}

void Lista::insertarAlPrincipio(Tipo dato)
{
   Nodo *nuevoNodo = new Nodo(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo al principio
      nuevoNodo->setSiguiente(cabeza);
      // La cabeza ahora apunta al nuevo nodo
      cabeza = nuevoNodo;
   }
   else
   {
      // La lista está vacía
      // El nuevo nodo es la cabeza y el último
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
   }
}

void Lista::insertarAlFinal(Tipo dato)
{
   Nodo *nuevoNodo = new Nodo(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo en el siguiente del último
      ultimo->setSiguiente(nuevoNodo);
      // El último ahora apunta al nuevo nodo
      ultimo = nuevoNodo;
   }
   else
   {
      // La lista está vacía
      // El nuevo nodo es la cabeza y el último
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
   }
}

void Lista::insertarEnPosicion(Tipo dato, int indice)
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

         // Si el auxiliar es nulo, la posicion solicitada
         // es mayor a los elementos en la lista
         if (aux == NULL)
         {
            throw INDEX_OUT_OF_RANGE;
         }
      }

      // Si el índice solicitado es el cero, o de manera equivalente
      // el auxiliar sigue apuntando a la cabeza
      // significa que hay que insertar al principio
      if (indice == 0) // aux == cabeza
      {
         insertarAlPrincipio(dato);
      }
      // Si el auxiliar está apuntando al último
      // hay que insertar al final el nuevo nodo
      else if (aux == ultimo)
      {
         insertarAlFinal(dato);
      }
      // En el último caso, se debe insertar "en medio"
      else
      {
         // Guardar la referencia del siguiente en otro puntero
         Nodo *siguiente = aux->getSiguiente();
         // El siguiente del auxiliar será el nuevo nodo
         aux->setSiguiente(nuevoNodo);
         // Hay que conectar el siguiente del nuevo nodo
         // con la referencia guardada anteriormente
         nuevoNodo->setSiguiente(siguiente);

         // Alternativa
         // nuevoNodo->setSiguiente(aux->getSiguiente());
         // aux->setSiguiente(nuevoNodo);
      }
   }
   // La lista está vacía y se quiere insertar al principio
   // (el indice solicitado es 0)
   else if (indice == 0)
   {
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
   }
   // La lista está vacía y se quiere insertar en un índice
   // que todavía no existe
   else
   {
      // Lanzar error
      throw EMPTY_LIST;
   }
}

int Lista::buscarElemento(Tipo elementoBuscado)
{
   // Auxiliar para recorrer la lista
   Nodo *aux = cabeza;
   // variable para controlar el índice
   int controlIndice = 0;
   // Recorrer la lista mientras el elemento no sea nulo
   while (aux != NULL)
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
   }
   // Si al finalizar el ciclo el auxiliar es nulo,
   // entonces no se encontró el elemento
   if (aux == NULL)
   {
      // Devolver un -1 indicando que no se encontró
      controlIndice = -1;
   }

   // Finalmente, devolver el índice
   return controlIndice;
}

Tipo Lista::buscarPorIndice(int indice)
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

         // Si el auxiliar es nulo, significa que pidió
         // un índice que no existe aún. Lanzar error
         if (aux == NULL)
         {
            throw INDEX_OUT_OF_RANGE;
         }
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

bool Lista::estaVacia()
{
   // Si la cabeza es nula, significa que no hay datos
   return cabeza == NULL;
}

void Lista::eliminarElemento(Tipo elemento)
{
   if (!estaVacia())
   {
      Nodo *aux = cabeza;
      Nodo *anterior = NULL;

      while (aux != NULL)
      {
         if (aux->getDato() == elemento)
         {
            break;
         }
         else
         {
            anterior = aux;
            aux = aux->getSiguiente();
         }
      }

      if (aux != NULL)
      {
         if (aux == cabeza)
         {
            // El elemento está al principio
            cabeza = aux->getSiguiente();
         }
         else if (aux == ultimo)
         {
            // El elemento está al final
            anterior->setSiguiente(NULL);
            ultimo = anterior;
         }
         else
         {
            anterior->setSiguiente(aux->getSiguiente());
         }

         delete aux;
      }
   }
   else
   {
      throw EMPTY_LIST;
   }
}

void Lista::eliminarPorIndice(int posicion)
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

         if (aux == NULL)
         {
            // Se salió de la lista
            throw INDEX_OUT_OF_RANGE;
         }
      }

      if (aux == cabeza)
      {
         // El auxiliar nunca se movió
         // Eliminar el primer elemento
         cabeza = aux->getSiguiente();
      }
      else if (aux == ultimo)
      {
         // El auxiliar avanzó hasta el último elemento
         // Eliminar el último nodo
         anterior->setSiguiente(NULL);
         ultimo = anterior;
      }
      else
      {
         // El elemento a eliminar no es ni la cabeza ni el último
         anterior->setSiguiente(aux->getSiguiente());
      }

      delete aux;
   }
   else
   {
      throw EMPTY_LIST;
   }
}

void Lista::imprimir()
{
   Nodo *aux = cabeza;
   // Recorrer la lista e imprimir el dato
   while (aux != NULL)
   {
      cout << aux->getDato() << ", ";
      aux = aux->getSiguiente();
   }
   cout << endl;
}