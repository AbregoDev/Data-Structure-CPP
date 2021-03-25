#include <iostream>
using std::cout;
using std::endl;

int main()
{
   // Ejercicio 1
   int n = 10;
   int &r = n;

   cout << n << endl;
   cout << r << endl;

   n = 20;

   cout << n << endl;
   cout << r << endl;

   // // Ejercicio 2
   // int k = 8;
   // int *p_k = &k;
   // int &r = *p_k;

   // cout << p_k << endl;

   // // Ejercicio 3
   // short sharr[5];
   // sharr[0] = 4;
   // sharr[1] = 40;
   // sharr[2] = 400;

   // cout << *sharr << endl;
   // cout << *(sharr + 1) << endl;

   // // Ejercicio 4
   // int arr[3] = {10, 50, 75};
   // int (*p_arr)[3] = &arr;

   // cout << *p_arr << endl;
   // cout << **p_arr << endl;
   // cout << **p_arr + 1 << endl;
}