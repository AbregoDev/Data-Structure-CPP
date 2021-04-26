#include <iostream>
#include "NodoDoble.h"
using namespace std;

enum StackErrors
{
   // STACK_OVERFLOW,
   STACK_UNDERFLOW,
   EMPTY_STACK,
};

class Stack
{
private:
   NodoDoble *cabeza;
   NodoDoble *cima;
   int _length;

public:
   Stack();
   void push(Tipo data);
   Tipo pop();
   Tipo peek();
   bool isEmpty();
   void clean();
   int length();
   void print();
};

Stack::Stack()
{
   cabeza = cima = NULL;
   _length = 0;
}

void Stack::push(Tipo data)
{
   NodoDoble *nuevo = new NodoDoble(data);
   _length++;

   if(!isEmpty())
   {
      cima->setSiguiente(nuevo);
      nuevo->setAnterior(cima);
      cima = nuevo;
   }
   else
   {
      cabeza = cima = nuevo;
   }
}

Tipo Stack::pop()
{
   if (!isEmpty())
   {
      Tipo data = cima->getDato();

      if(_length == 1)
      {
         delete cima;
         cabeza = cima = NULL;
      }
      else
      {
         NodoDoble *aux = cima;
         cima = aux->getAnterior();
         cima->setSiguiente(NULL);
         delete aux;
      }
      
      _length--;
      return data;
   }
   else
   {
      throw STACK_UNDERFLOW;
   }
}

Tipo Stack::peek()
{
   if (!isEmpty())
   {
      return cima->getDato();
   }
   else
   {
      throw EMPTY_STACK;
   }
}

bool Stack::isEmpty()
{
   return cima == NULL;
}

// bool Stack::isFull()
// {
//    return pointer == _size - 1;
// }

void Stack::clean()
{
   cabeza = cima = NULL;
   _length = 0;
}

// int Stack::size()
// {
//    return _size;
// }

int Stack::length()
{
   return _length;
}

void Stack::print()
{
   if(!isEmpty())
   {
      NodoDoble *aux = cabeza;
      while(aux != NULL)
      {
         cout << aux->getDato() << ", ";
         aux = aux->getSiguiente();
      }
      cout << endl;
   }
   else
   {
      cout << "**Pila vacia**" << endl;
   }
}