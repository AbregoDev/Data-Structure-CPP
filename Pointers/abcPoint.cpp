#include <iostream>
using std::cout;
using std::endl;

int main()
{
   // Crear un programa que muestre el abecedario
   // utilizando un puntero

   char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   char *abc_p = abc;

   // for(int i = 0; i < 27; i++)
   // {
   //    cout << *(abc_p + i);
   // }

   int i = 0;
   while(*abc_p)
   {
      cout << *abc_p;
      abc_p = abc_p + 1;
   }   
}