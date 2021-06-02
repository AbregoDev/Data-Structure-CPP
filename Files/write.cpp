#include <iostream>
#include <fstream>
#include <string>
#include "../Queue/Queue.h"

int main()
{
   ofstream file ("new.txt");
   Queue *queue = new Queue();
   queue->enqueue(5);
   file << "Agregue un 5" << endl;
   queue->enqueue(8);
   file << "Agregue un 8" << endl;
   queue->enqueue(10);
   file << "Agregue un 10" << endl;
   queue->dequeue();
   file << "Quité un elemento" << endl;
   queue->enqueue(3);
   file << "Agregue un 3" << endl;

   file << "Estado final:" << endl;
   file << queue->toString();
   file << endl;

   cout << "File writed!";

   return 0;
}