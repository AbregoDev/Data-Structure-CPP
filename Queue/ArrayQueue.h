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
   int _front;
   int _rear;
   int _length;
   int _size;

public:
   ArrayQueue(int size);
   void enqueue(DataType data);
   DataType dequeue();
   DataType front();
   DataType rear();
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
   _front = _rear = 0;
   _length = 0;
}

void ArrayQueue::enqueue(DataType data)
{
   if(!isFull())
   {
      array[_rear] = data;
      // _rear = (_rear + 1) % _size;
      if(_rear == _size - 1)
      {
         _rear = 0;
      }
      else
      {
         _rear++;
      }

      _length++;
   }
   else
   {
      throw QUEUE_OVERFLOW;
   }
}

DataType ArrayQueue::dequeue()
{
   if(!isEmpty())
   {
      DataType e = array[_front];
      _front = (_front + 1) % _size;
      _length--;
      
      return e;
   }
   else
   {
      throw QUEUE_UNDERFLOW;
   }
}

DataType ArrayQueue::front()
{
   return array[_front];
}

DataType ArrayQueue::rear()
{
   return array[_rear == 0 ? _size - 1 : _rear - 1];
}

bool ArrayQueue::isEmpty()
{
   return _front == _rear;
}

bool ArrayQueue::isFull()
{
   return _front == (_rear + 1) % _size;
}

int ArrayQueue::size()
{
   return _size;
}

int ArrayQueue::length()
{
   return _length;
}

void ArrayQueue::print()
{
   if(isEmpty())
   {
      cout << "**Empty queue**";
   }
   else
   {
      int index = _front;
      while(index != _rear)
      {
         cout << array[index] << ", ";
         index = (index + 1) % _size;
      }
   }
   cout << endl;

   // DEBUG
   cout << "Arr: ";
   for(int k = 0; k < _size; k++)
   {
      cout << array[k] << ", ";
   }
   cout << endl;
}