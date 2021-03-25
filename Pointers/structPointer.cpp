#include <iostream>
using std::cout;
using std::endl;

int main()
{
   // Crear una estructura "ficha" con los miembros:
   // numero, nombre. Rellenar los datos, mostrarlos
   // con punteros

   struct ficha
   {
      int numero;
      char nombre[20];
   };

   ficha f = {456, "Bryan"};

   ficha *ficha_p = &f;

   cout << ficha_p -> numero << endl;
   cout << ficha_p -> nombre << endl;


   return 0;
}