#include <iostream>
using std::cout;
using std::endl;

int strLen(char cadena[])
{
   int len = 0;
   while(cadena[len] != '\0')
   {
      len++;
   }
   return len;
}

int main()
{
   char alfa[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   char *p = &alfa[0];
   while(*p) { cout << *p++; }
   
   return 0;
}