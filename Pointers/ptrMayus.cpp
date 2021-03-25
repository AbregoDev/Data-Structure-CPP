#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
   char *p;
   char cadena[30];

   cout << "Introduzca la cadena a convertir: ";
   cin.get(cadena, sizeof(cadena));

   p = &cadena[0];
   while(*p)
   {
      if(*p >= 'a' && *p <= 'z')
         *p -= 32;
      p++;
   }
   cout << "La cadena resultante es: " << cadena << endl;
}