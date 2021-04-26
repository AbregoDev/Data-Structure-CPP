#include <iostream>
using namespace std;

typedef int DataType;

enum QueueErrors
{
   QUEUE_OVERFLOW,
   QUEUE_UNDERFLOW,
   EMPTY_QUEUE,
};

class ArrayQueue
{
private:
   DataType *array;
   int front;
   int rear;
   int _length;
   int _size;

public:
   ArrayQueue(int size);
   void enqueue(DataType data);
   DataType dequeue();
   DataType peek();
   bool isEmpty();
   bool isFull();
   int size();
   int length();
   void print();
};

ArrayQueue::ArrayQueue(int size)
{
   array = new DataType[size];
   _size = size;
}

void ArrayQueue::enqueue(DataType data)
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

DataType ArrayQueue::deque()
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

DataType ArrayQueue::peek()
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

bool ArrayQueue::isEmpty()
{
   return pointer == -1;
}

bool ArrayQueue::isFull()
{
   return pointer == _size - 1;
}

void ArrayQueue::clean()
{
   pointer = -1;
}

int ArrayQueue::size()
{
   return _size;
}

int ArrayQueue::length()
{
   return pointer + 1;
}

void ArrayQueue::print()
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