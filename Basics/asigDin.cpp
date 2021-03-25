#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
   // Crear una estructura "ficha" dinámica con los miembros:
   // numero, nombre. Rellenar los datos, mostrarlos y
   // liberar la memoria.
   // Mostrar los datos otra vez.

   struct ficha
   {
      int numero;
      char nombre[20];
   };

   ficha *f_p; // Define un puntero a un struct
   f_p = new ficha; // Devuelve un puntero a un struct

   cout << "Ingrese numero" << endl;
   cin >> f_p -> numero;

   cout << "Ingrese nombre" << endl;
   cin >> f_p -> nombre;

   cout << "numero: " << f_p -> numero << endl;
   cout << "nombre: " << f_p -> nombre << endl;
   cout << "direccion: " << f_p << endl;

   delete f_p;

   cout << "numero: " << f_p -> numero << endl;
   cout << "nombre: " << f_p -> nombre << endl;
   cout << "direccion: " << f_p << endl;

   return 0;
}