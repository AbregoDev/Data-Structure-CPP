#include <iostream>
using std::cout;
using std::endl;

int main()
{
   int arr[5] = {5, 89, 36, 74, 12};

   // cout << arr << endl; // Dirección del índice 0
   // cout << *arr << endl; // 5

   // cout << "*arr + 1: " << *arr + 1 << endl; // 5 + 1
   // cout << "arr + 1: " << arr + 1 << endl; // 0x65165ABD6
   // cout << "*(arr + 1): " << *(arr + 1) << endl; // 89
   // cout << "arr[1]: " << arr[1] << endl; // 89

   for(int i = 0; i <= 4; i++)
   {
      cout << *arr + i << endl;
   }

   // cout << *arr + 0 << endl; // 5
   // cout << *arr + 1 << endl; // 6
   // cout << *arr + 2 << endl; // 7
   // cout << *arr + 3 << endl; // 8
   // cout << *arr + 4 << endl; // 9


   for(int i = 0; i <= 4; i++)
   {
      cout << *(arr + i) << endl;
   }

   // 5
   // 89
   // 36
   // 74
   // 14
}