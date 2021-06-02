#include <iostream>
#include <fstream>
// #include <string>
#include "../Queue/Queue.h"

using namespace std;

int main()
{
   ifstream file("numbers.txt");
   if (!file.is_open())
   {
      cout << "Error";
      return 1;
   }

   Queue *queue = new Queue();

   string line;

   while(getline(file, line))
   {
      int n = std::stoi(line);
      queue->enqueue(n);
   }

   queue->dequeue();
   queue->dequeue();
   queue->dequeue();
   queue->dequeue();
   
   cout << queue->toString() << endl;

   return 0;
}