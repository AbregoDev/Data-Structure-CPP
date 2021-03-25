#include<iostream>
using namespace std;

int main()
{
   struct ficha {
      int num;
      char nombre[30];
   };

   ficha *ficha_p = new ficha;

   cout << "Introduzca el numero de ficha" << endl;
   cin >> ficha_p -> num;

   cout << "Introduzca el nombre" << endl;
   cin >> ficha_p -> nombre;

   cout << "Numero: " << ficha_p -> num << endl;
   cout << "Nombre: " << ficha_p -> nombre << endl;
   cout << "Address: " << &ficha_p << endl;

   delete ficha_p;

   cout << "Numero: " << ficha_p -> num << endl;
   cout << "Nombre: " << ficha_p -> nombre << endl;
   cout << "Address: " << &ficha_p << endl;

   return 0;
}