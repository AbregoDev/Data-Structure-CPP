#include <iostream>
#include "../Lists/NodoDoble.h"
#include <string>
using namespace std;

typedef int DataType;

enum QueueErrors
{
   // QUEUE_OVERFLOW,
   QUEUE_UNDERFLOW,
   EMPTY_QUEUE,
};

class Queue
{
private:
   // DataType *array;
   NodoDoble* _front;
   NodoDoble* _rear;
   int _length;
   // int _size;

public:
   Queue();
   void enqueue(DataType data);
   DataType dequeue();
   DataType front();
   DataType rear();
   bool isEmpty();
   // bool isFull();
   // int size();
   int length();
   void print();
   string toString();
};

Queue::Queue()
{
   // array = new DataType[size];
   // _size = size;
   _front = _rear = NULL;
   _length = 0;
}

void Queue::enqueue(DataType data)
{
   // Nuevo nodo
   NodoDoble *element = new NodoDoble(data);

   if(!isEmpty())
   {
      // Enlace doble
      _rear->setSiguiente(element);
      element->setAnterior(_rear);
      // Apuntar al último
      _rear = element;
   }
   else {
      _rear = _front = element;
   }
   
   // Incremenetar el tamaño de la cola
   _length++;
}

DataType Queue::dequeue()
{
   if(!isEmpty())
   {
      // Obtener el dato que tiene el frente para devolverlo después
      DataType data = _front->getDato();

      // Considerar el caso en el que la cola no quedará vacía después
      // de la operación
      if(_length != 1)
      {
         // Apuntar al siguiente nodo de la cola
         NodoDoble *newFront = _front->getSiguiente();
         // Romper el enlace al nodo que será removido
         newFront->setAnterior(NULL);
         // Liberar el espacio en memoria del nodo eliminado
         delete _front;
         // Apuntar al nuevo frente
         _front = newFront;
      }
      // La cola quedará vacía después de la operación
      else
      {
         // Liberar espacio en memoria
         delete _front;
         // La cabeza y el último apuntan a nulo
         _front = _rear = NULL;
      }

      // Decrementar el tamaño de la cola
      _length--;
      
      return data;
   }
   else
   {
      throw QUEUE_UNDERFLOW;
   }
}

DataType Queue::front()
{
   return _front->getDato();
}

DataType Queue::rear()
{
   return _rear->getDato();
}

bool Queue::isEmpty()
{
   // return _front == NULL;
   // return _rear == NULL;
   return !_length;
}

int Queue::length()
{
   return _length;
}

void Queue::print()
{
   if(isEmpty())
   {
      cout << "**Empty queue**";
   }
   else
   {
      NodoDoble *aux = _front;
      while(aux != NULL)
      {
         cout << aux->getDato() << ", ";
         aux = aux->getSiguiente();
      }
   }
   cout << endl;
}

string Queue::toString()
{
   string s = "";
   if(isEmpty())
   {
      s = "**Empty queue**";
   }
   else
   {
      NodoDoble *aux = _front;
      while(aux != NULL)
      {
         s += std::to_string(aux->getDato()) + ", ";
         aux = aux->getSiguiente();
      }
   }

   return s;
}