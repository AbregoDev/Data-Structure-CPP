#include "Stack.h"

int main()
{
   Stack *pila = new Stack();

   try
   {
      // User option
      char opc;
      // Type to save user input for elements
      Tipo element;

      do
      {
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "1: Push" << endl;
         cout << "2: Pop" << endl;
         cout << "3: Peek" << endl;
         cout << "4: is empty?" << endl;
         // cout << "5: is full?" << endl;
         cout << "5: clean" << endl;
         // cout << "7: size" << endl;
         cout << "6: length" << endl;
         cout << "7: print" << endl;
         cout << "0: exit" << endl;
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "Option: ";

         cin >> opc;
         fflush(stdin);

         switch (opc)
         {
         case '1':
            cout << "Element to push: ";
            cin >> element;
            pila->push(element);
            pila->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '2':
            element = pila->pop();
            cout << "Pop: " << element << endl;
            pila->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '3':
            element = pila->peek();
            cout << "Peek: " << element << endl;
            pila->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '4':
            cout << "Is empty?: " << (pila->isEmpty() ? "Yes" : "No") << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         // case '5':
         //    cout << "Is full?: " << pila->isFull() << endl;
         //    // Wait 'till key press
         //    fflush(stdin);
         //    cin.get();
         //    break;

         case '5':
            pila->clean();
            cout << "Stack cleaned!" << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         // case '7':
         //    cout << "Size: " << pila->size() << endl;
         //    // Wait 'till key press
         //    fflush(stdin);
         //    cin.get();
         //    break;

         case '6':
            cout << "Length: " << pila->length() << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;
            break;

         case '7':
            pila->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         default:
            opc = '0';
            cout << "Bye" << endl;
            break;
         }
      } while (opc != '0');
   }
   catch (StackErrors err)
   {
      switch (err)
      {
      case STACK_UNDERFLOW:
         cout << "Stack underflow!!!" << endl;
         break;
         break;

      case EMPTY_STACK:
         cout << "Empty stack!!!!!" << endl;
         break;

      default:
         cout << "Error :(" << endl;
         break;
      }
   }
}