#include <iostream>
using std::cout;
using std::endl;

int main()
{
   char *p;
   unsigned int i = 1;

   // El programa se detendrá cuando ya no haya memoria disponible
   do {
      p = new char[1000000];
      cout << "Assign: " << i++ << " MiB" << endl;
   } while(p);

   return 0;
}