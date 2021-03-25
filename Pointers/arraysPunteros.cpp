#include <iostream>
using namespace std;

int main()
{
   // Tipos enteros
   int a = 4;
   int b = 40;
   int c = 400;
   int d = 4000;

   // Arreglo de punteros (a enteros)
   int *pointers_array[4];
   pointers_array[0] = &a;
   pointers_array[1] = &b;
   pointers_array[2] = &c;
   pointers_array[3] = &d;

   // cout << pointers_array[1] << endl;
   // cout << *pointers_array[1] << endl;

   // Array de enteros
   int arr[] = {a, b, c, d};

   // Puntero al array de enteros anterior
   int (*array_pointer)[4] = &arr;

   // cout << array_pointer << endl;
   // cout << &arr << endl;
   // cout << *(*array_pointer) << endl;

   int *(*pointers_array_pointer)[4] = &pointers_array;

   cout << &pointers_array_pointer << endl;
   cout << *pointers_array_pointer << endl;
   cout << **pointers_array_pointer << endl;
   cout << ***pointers_array_pointer << endl;

   return 0;
}