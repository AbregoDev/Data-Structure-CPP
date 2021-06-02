#include <iostream>
#include <fstream>
#include <string>
#include "../Queue/Queue.h"

using namespace std;

int main()
{
   // Leer archivo
   ifstream file("nums.dll");
   if (!file.is_open())
   {
      // En caso de no encontrarlo, salir del programa
      cout << "Error. Archivo no encontrado";
      return 1;
   }

   // Crear una pila para almacenar los datos
   Queue *queue = new Queue();

   // Cadena en donde se almacenarán las líneas
   // leídas por getline
   string line;

   // Mientras haya alguna línea por leer
   while(getline(file, line))
   {
      int n = std::stoi(line);
      queue->enqueue(n);
   }

   cout << "La cola al ser leida es:" << endl;
   queue->print();

   // Modificar la cola
   queue->dequeue();
   queue->dequeue();

   queue->enqueue(9);
   queue->dequeue();

   queue->enqueue(7);

   queue->dequeue();
   queue->dequeue();
   queue->dequeue();

   cout << "La cola al final es:" << endl;
   queue->print();

   // Guardar los datos de la cola en un fichero
   ofstream fileSave("nuevos.dll");
   fileSave << queue->toString() << endl;

   cout << "El archivo ha sido escrito";

   return 0;
}