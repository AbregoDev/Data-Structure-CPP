#include <iostream>
#include "NodoDoble.h"
using namespace std;

enum ErroresListas
{
   INDEX_OUT_OF_RANGE,
   EMPTY_LIST,
};

class ListaDoble
{
private:
   NodoDoble *cabeza;
   NodoDoble *ultimo;

public:
   ListaDoble();
   void insertarAlPrincipio(Tipo dato);
   void insertarAlFinal(Tipo dato);
   void insertarEnPosicion(Tipo dato, int indice);
   // int buscarElemento(Tipo elementoBuscado);
   // Tipo buscarPorIndice(int indice);
   // void eliminarElemento(Tipo elemento);
   // void eliminarPorIndice(int posicion);
   bool estaVacia();
   void imprimir();
};

ListaDoble::ListaDoble()
{
   // Inicializar en nulos
   cabeza = NULL;
   ultimo = NULL;
}

void ListaDoble::insertarAlPrincipio(Tipo dato)
{
   // Crear nuevo nodo con el dato
   NodoDoble *nuevoNodo = new NodoDoble(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo al principio con enlace doble
      nuevoNodo->setSiguiente(cabeza);
      cabeza->setAnterior(nuevoNodo);
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

void ListaDoble::insertarAlFinal(Tipo dato)
{
   NodoDoble *nuevoNodo = new NodoDoble(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Insertar el nodo en el siguiente del último
      // Realizar enlace doble
      ultimo->setSiguiente(nuevoNodo);
      nuevoNodo->setAnterior(ultimo);
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

void ListaDoble::insertarEnPosicion(Tipo dato, int indice)
{
   NodoDoble *nuevoNodo = new NodoDoble(dato);

   if (!estaVacia())
   {
      // La lista no está vacía
      // Auxiliar para recorrer la lista
      NodoDoble *aux = cabeza;
      // Indice para controlar la posicion
      int controlIndice = 0;

      // Recorrer la lista y detenerse en la posición deseada
      while (controlIndice < indice)
      {
         // Si el auxiliar es nulo, la posicion solicitada
         // es mayor a los elementos en la lista
         if (aux == NULL)
         {
            throw INDEX_OUT_OF_RANGE;
         }

         // Avanzar al siguiente nodo
         aux = aux->getSiguiente();
         // El controlador del indice avanza
         controlIndice++;
      }

      // Si el índice solicitado es el cero, o de manera equivalente
      // el auxiliar sigue apuntando a la cabeza
      // significa que hay que insertar al principio
      if (indice == 0) // aux == cabeza
      {
         insertarAlPrincipio(dato);
      }
      // Si el auxiliar está apuntando hacia NULL
      // significa que hay que insertar al final
      else if (aux == NULL)
      {
         insertarAlFinal(dato);
      }
      // En el último caso, se debe insertar "en medio"
      else
      {
         // Guardar la referencia del anterior en otro puntero
         NodoDoble *anterior = aux->getAnterior();
         // Enlace doble entre el nuevo nodo y el anterior
         nuevoNodo->setAnterior(anterior);
         anterior->setSiguiente(nuevoNodo);
         // Enlace doble entre el nuevo nodo y el siguiente
         aux->setAnterior(nuevoNodo);
         nuevoNodo->setSiguiente(aux);
      }
   }
   // La lista está vacía y se quiere insertar al principio
   // (el indice solicitado es 0)
   else if (indice == 0)
   {
      cabeza = nuevoNodo;
      ultimo = nuevoNodo;
      // Equivalente
      // insertarAlPrincipio(dato);
   }
   // La lista está vacía y se quiere insertar en un índice
   // que todavía no existe
   else
   {
      // Lanzar error
      throw EMPTY_LIST;
   }
}

// int ListaDoble::buscarElemento(Tipo elementoBuscado)
// {
//    // Auxiliar para recorrer la lista
//    NodoDoble *aux = cabeza;
//    // variable para controlar el índice
//    int controlIndice = 0;
//    // Recorrer la lista mientras el elemento no sea nulo
//    while (aux != NULL)
//    {
//       // Si el dato del auxiliar consiste con el elemento
//       // que se está buscando, terminar el ciclo
//       if (aux->getDato() == elementoBuscado)
//       {
//          break;
//       }
//       // Si no coincide, avanzar al siguiente nodo
//       else
//       {
//          aux = aux->getSiguiente();
//          controlIndice++;
//       }
//    }
//    // Si al finalizar el ciclo el auxiliar es nulo,
//    // entonces no se encontró el elemento
//    if (aux == NULL)
//    {
//       // Devolver un -1 indicando que no se encontró
//       controlIndice = -1;
//    }

//    // Finalmente, devolver el índice
//    return controlIndice;
// }

// Tipo ListaDoble::buscarPorIndice(int indice)
// {
//    // Si la lista no está vacía, ejecutar el algoritmo
//    if (!estaVacia())
//    {
//       // Auxiliar para recorrer la lista
//       NodoDoble *aux = cabeza;
//       // Variable de control del índice
//       int controlIndice = 0;

//       // Mientras el control del índice sea menor al
//       // índice solicitado, ejecutar
//       while (controlIndice < indice)
//       {
//          // Avanzar al siguiente nodo
//          aux = aux->getSiguiente();
//          controlIndice++;

//          // Si el auxiliar es nulo, significa que pidió
//          // un índice que no existe aún. Lanzar error
//          if (aux == NULL)
//          {
//             throw INDEX_OUT_OF_RANGE;
//          }
//       }

//       // Si el ciclo se terminó correctamente, devolver el dato
//       // de la posición alcanzada
//       return aux->getDato();
//    }
//    // La lista está vacía, devolver un error
//    else
//    {
//       throw EMPTY_LIST;
//    }
// }

bool ListaDoble::estaVacia()
{
   // Si la cabeza es nula, significa que no hay datos
   return cabeza == NULL;
}

// void ListaDoble::eliminarElemento(Tipo elemento)
// {
//    if (!estaVacia())
//    {
//       NodoDoble *aux = cabeza;
//       NodoDoble *anterior = NULL;

//       while (aux != NULL)
//       {
//          if (aux->getDato() == elemento)
//          {
//             break;
//          }
//          else
//          {
//             anterior = aux;
//             aux = aux->getSiguiente();
//          }
//       }

//       if (aux != NULL)
//       {
//          if (aux == cabeza)
//          {
//             // El elemento está al principio
//             cabeza = aux->getSiguiente();
//          }
//          else if (aux == ultimo)
//          {
//             // El elemento está al final
//             anterior->setSiguiente(NULL);
//             ultimo = anterior;
//          }
//          else
//          {
//             anterior->setSiguiente(aux->getSiguiente());
//          }

//          delete aux;
//       }
//    }
//    else
//    {
//       throw EMPTY_LIST;
//    }
// }

// void ListaDoble::eliminarPorIndice(int posicion)
// {
//    if (!estaVacia())
//    {
//       NodoDoble *aux = cabeza;
//       NodoDoble *anterior = NULL;
//       int indiceControl = 0;

//       while (indiceControl < posicion)
//       {
//          anterior = aux;
//          aux = aux->getSiguiente();
//          indiceControl++;

//          if (aux == NULL)
//          {
//             // Se salió de la lista
//             throw INDEX_OUT_OF_RANGE;
//          }
//       }

//       if (aux == cabeza)
//       {
//          // El auxiliar nunca se movió
//          // Eliminar el primer elemento
//          cabeza = aux->getSiguiente();
//       }
//       else if (aux == ultimo)
//       {
//          // El auxiliar avanzó hasta el último elemento
//          // Eliminar el último nodo
//          anterior->setSiguiente(NULL);
//          ultimo = anterior;
//       }
//       else
//       {
//          // El elemento a eliminar no es ni la cabeza ni el último
//          anterior->setSiguiente(aux->getSiguiente());
//       }

//       delete aux;
//    }
//    else
//    {
//       throw EMPTY_LIST;
//    }
// }

void ListaDoble::imprimir()
{
   NodoDoble *aux = cabeza;
   // Recorrer la lista e imprimir el dato
   while (aux != NULL)
   {
      cout << aux->getDato() << ", ";
      aux = aux->getSiguiente();
   }
   cout << endl;
}