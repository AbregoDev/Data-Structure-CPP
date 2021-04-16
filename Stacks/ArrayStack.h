#include <iostream>
using namespace std;

typedef int DataType;

enum StackErrors
{
   STACK_OVERFLOW,
   STACK_UNDERFLOW,
   EMPTY_STACK,
};

class ArrayStack
{
private:
   int pointer;
   int *array;
   int _size;

public:
   ArrayStack(int size);
   void push(DataType data);
   DataType pop();
   DataType peek();
   bool isEmpty();
   bool isFull();
   void clean();
   int size();
   int length();
   void print();
};

ArrayStack::ArrayStack(int size)
{
   array = new DataType[size];
   pointer = -1;
   _size = size;
}

void ArrayStack::push(DataType data)
{
   if(!isFull())
   {
      array[++pointer] = data;
   }
   else
   {
      throw STACK_OVERFLOW;
   }
}

DataType ArrayStack::pop()
{
   if(!isEmpty())
   {
      return array[pointer--];
   }
   else
   {
      throw STACK_UNDERFLOW;
   }
}

DataType ArrayStack::peek()
{
   if(!isEmpty())
   {
      return array[pointer];
   }
   else
   {
      throw EMPTY_STACK;
   }
}

bool ArrayStack::isEmpty()
{
   return pointer == -1;
}

bool ArrayStack::isFull()
{
   return pointer == _size - 1;
}

void ArrayStack::clean()
{
   pointer = -1;
}

int ArrayStack::size()
{
   return _size;
}

int ArrayStack::length()
{
   return pointer + 1;
}

void ArrayStack::print()
{
   if(isEmpty())
   {
      cout << "**Empty stack**";
   }
   else
   {
      for(int i = 0; i <= pointer; i++)
      {
         cout << array[i] << ", ";
      }
   }
   cout << endl;
}