#include <iostream>
using namespace std;

int strLen(char str[]);

int main()
{
   char saludo[] = "Buen dia, terricolas!";

   cout << "La cadena \"saludo\" tiene una longitud de " << strLen(saludo) << " caracteres" << endl;

   return 0;
}

int strLen(char* str) 
{
   int index = 0;
   while(*(str++) != '\0')
   {
      index++;
   }

   return index;
}