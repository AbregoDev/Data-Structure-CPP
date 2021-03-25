#include <iostream>
#include <clocale>
using namespace std;

int main()
{
   int len;
   cout << "Tamaño del array: ";
   cin >> len;

   int *arr = new int[len];

   for (int i = 0; i < len; i++)
   {
      cout << "Valor para arr[" << i << "]: ";
      cin >> arr[i];
   }

   for (int i = 0; i < len; i++)
   {
      cout << arr[i] << endl;
   }

   return 0;
}