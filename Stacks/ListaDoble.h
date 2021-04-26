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
   int buscarElemento(Tipo elementoBuscado);
   Tipo buscarPorIndice(int indice);
   void eliminarElemento(Tipo elemento);
   void eliminarPorIndice(int posicion);
   bool estaVacia();
   void imprimir();
   ListaDoble *invertir();
   NodoDoble *getCabeza();
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

int ListaDoble::buscarElemento(Tipo elementoBuscado)
{
   // Auxiliar para recorrer la lista
   NodoDoble *aux = cabeza;
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

Tipo ListaDoble::buscarPorIndice(int indice)
{
   // Si la lista no está vacía, ejecutar el algoritmo
   if (!estaVacia())
   {
      // Auxiliar para recorrer la lista
      NodoDoble *aux = cabeza;
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

bool ListaDoble::estaVacia()
{
   // Si la cabeza es nula, significa que no hay datos
   return cabeza == NULL;
}

void ListaDoble::eliminarElemento(Tipo elemento)
{
   // Verificar que la lista no esté vacía
   if (!estaVacia())
   {
      // Crear un nodo para recorrer toda la lista
      NodoDoble *aux = cabeza;

      // Mientras aux sea un Nodo válido
      while (aux != NULL)
      {
         // Si el miembro dato del auxiliar es igual al elemento buscado
         // detener el ciclo
         if (aux->getDato() == elemento)
         {
            break;
         }
         // En caso contrario, avanzar al siguiente nodo
         else
         {
            aux = aux->getSiguiente();
         }
      }

      // Al finalizar el ciclo, verificar si el nodo es válido (no nulo)
      if (aux != NULL)
      {
         // Si el auxiliar apunta a la cabeza, eliminar el primer elemento
         if (aux == cabeza)
         {
            // La cabeza ahora apuntará al siguiente del primero (el segundo)
            cabeza = aux->getSiguiente();
            // El puntero anterior del auxiliar ya no debe apuntar a ningún nodo
            cabeza->setAnterior(NULL);
         }
         // Si el auxiliar apunta al último, eliminar el elemento final
         else if (aux == ultimo)
         {
            // Guardar una referencia al nodo anterior (el penúltimo)
            NodoDoble *anterior = aux->getAnterior();
            // El siguiente del nodo "anterior" (el penúltimo) ya no debe apuntar
            // a ningún nodo
            anterior->setSiguiente(NULL);
            // Ahora el último elemento es ese anterior
            ultimo = anterior;
         }
         // El auxiliar no está al principio ni al final (está "en medio")
         else
         {
            // Guardar una referencia al nodo anterior
            NodoDoble *anterior = aux->getAnterior();
            // Guardar una referencia al nodo siguiente
            NodoDoble *siguiente = aux->getSiguiente();
            // El "anterior" ahora debe apuntar como siguiente a "siguiente"
            anterior->setSiguiente(siguiente);
            // El "siguiente" ahora debe apuntar como anterior a "anterior"
            siguiente->setAnterior(anterior);
         }
         // En cualquier caso, liberar ese espacio de memoria de ese nodo
         delete aux;
      }
   }
   else
   {
      // Si la lista está vacía, lanzar un error, pues no se puede eliminar
      // un elemento en una lista vacía
      throw EMPTY_LIST;
   }
}

void ListaDoble::eliminarPorIndice(int posicion)
{
   // Verificar que la lista no esté vacía
   if (!estaVacia())
   {
      // Crear un nodo para recorrer toda la lista
      NodoDoble *aux = cabeza;
      // Crear un control de índice
      int indiceControl = 0;

      // Mientras no se llegue a la posición deseada
      while (indiceControl < posicion)
      {
         // Avanzar al siguiente nodo
         aux = aux->getSiguiente();
         // Aumentar el control del índice
         indiceControl++;

         // Si el auxiliar es nulo, lanzar un error, significa que el numero
         // de elementos es menor al índice solicitado
         if (aux == NULL)
         {
            throw INDEX_OUT_OF_RANGE;
         }
      }

      // Si el auxiliar apunta a la cabeza, eliminar el primer elemento
      if (aux == cabeza)
      {
         // La cabeza ahora apuntará al siguiente del primero (el segundo)
         cabeza = aux->getSiguiente();
         // El puntero anterior del auxiliar ya no debe apuntar a ningún nodo
         // cuidar que la cabeza no sea NULL
         if(!estaVacia())
         {
            cabeza->setAnterior(NULL);
         }
      }
      // Si el auxiliar apunta al último, eliminar el elemento final
      else if (aux == ultimo)
      {
         // Guardar una referencia al nodo anterior (el penúltimo)
         NodoDoble *anterior = aux->getAnterior();
         // El siguiente del nodo "anterior" (el penúltimo) ya no debe apuntar
         // a ningún nodo
         anterior->setSiguiente(NULL);
         // Ahora el último elemento es ese anterior
         ultimo = anterior;
      }
      // El auxiliar no está al principio ni al final (está "en medio")
      else
      {
         // Guardar una referencia al nodo anterior
         NodoDoble *anterior = aux->getAnterior();
         // Guardar una referencia al nodo siguiente
         NodoDoble *siguiente = aux->getSiguiente();
         // El "anterior" ahora debe apuntar como siguiente a "siguiente"
         anterior->setSiguiente(siguiente);
         // El "siguiente" ahora debe apuntar como anterior a "anterior"
         siguiente->setAnterior(anterior);
      }
      // En cualquier caso, liberar ese espacio de memoria de ese nodo
      delete aux;
   }
   else
   {
      throw EMPTY_LIST;
   }
}

void ListaDoble::imprimir()
{
   // Crear un nodo para recorrer toda la lista
   NodoDoble *aux = cabeza;
   while (aux != NULL)
   {
      // Imprimir y agregar un separador
      cout << aux->getDato() << ", ";
      // Avanzar al siguiente nodo
      aux = aux->getSiguiente();
   }
   cout << endl;
}

ListaDoble *ListaDoble::invertir()
{
   // Crear una nueva lista
   ListaDoble *lista = new ListaDoble();

   // Si la lista no está vacía, poblar la copia
   if (!estaVacia())
   {
      // Crear un nodo para recorrer la lista empezando
      // en el último elemento
      NodoDoble *aux = ultimo;
      // Verificar que sea un nodo válido
      while (aux != NULL)
      {
         // Insertar el elemento al final,
         // puesto que se empezará en el último.
         // Otro enfoque sería inicializar aux en la cabeza
         // e insertar al principio en cada iteración.
         lista->insertarAlFinal(aux->getDato());

         // Navegar al nodo anterior
         // Guardar la referencia del elemento anterior
         NodoDoble *anterior = aux->getAnterior();
         // Liberar la dirección de memoria del nodo actual
         // puesto que ya no será utilizado
         delete aux;
         // Asignar al auxiliar la dirección guardada en el anterior
         aux = anterior;
      }
   }
   // Devolver la nueva lista invertida
   return lista;
}

NodoDoble *ListaDoble::getCabeza()
{
   return cabeza;
}