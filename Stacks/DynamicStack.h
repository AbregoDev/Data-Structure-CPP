#include <iostream>
#include "../Lists/ListaDoble.h"
#include "../Lists/NodoDoble.h"
using namespace std;

enum StackErrors
{
   // STACK_OVERFLOW,
   STACK_UNDERFLOW,
   EMPTY_STACK,
};

class DynamicStack
{
private:
   NodoDoble* pointer;
   ListaDoble* lista;
   int _length;
   // int _size;

public:
   // DynamicStack(int size);
   DynamicStack();
   void push(Tipo data);
   Tipo pop();
   Tipo peek();
   bool isEmpty();
   // bool isFull();
   void clean();
   // int size();
   int length();
   void print();
};

DynamicStack::DynamicStack()
{
   lista = new ListaDoble();
   pointer = NULL;
   _length = 0;
   // _size = size;
}

void DynamicStack::push(Tipo data)
{
   lista->insertarAlPrincipio(data);
   _length++;
   pointer = lista->getCabeza();
}

Tipo DynamicStack::pop()
{
   if (!isEmpty())
   {
      Tipo data = pointer->getDato();
      lista->eliminarPorIndice(0);
      pointer = lista->getCabeza();
      _length--;
      return data;
   }
   else
   {
      throw STACK_UNDERFLOW;
   }
}

Tipo DynamicStack::peek()
{
   if (!isEmpty())
   {
      return pointer->getDato();
   }
   else
   {
      throw EMPTY_STACK;
   }
}

bool DynamicStack::isEmpty()
{
   return pointer == NULL;
}

// bool DynamicStack::isFull()
// {
//    return pointer == _size - 1;
// }

void DynamicStack::clean()
{
   lista = new ListaDoble();
   pointer = NULL;
   _length = 0;
}

// int DynamicStack::size()
// {
//    return _size;
// }

int DynamicStack::length()
{
   return _length;
}

void DynamicStack::print()
{
   if(!isEmpty())
   {
      lista->imprimir();
   }
   else
   {
      cout << "**Pila vacia**" << endl;
   }
}