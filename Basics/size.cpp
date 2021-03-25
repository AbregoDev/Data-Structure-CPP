#include <iostream>
using std::cout;
using std::endl;

int main()
{
   union alumno
   {
      char sexo;
      int matricula;
   };

   alumno au1;
   cout << sizeof(au1);
}