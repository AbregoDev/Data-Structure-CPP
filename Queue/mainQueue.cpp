#include "ArrayQueue.h"

int main()
{
   int size;
   cout << "Enter size of the queue: ";
   cin >> size;
   ArrayQueue *queue = new ArrayQueue(size);

   try
   {
      // User option
      char opc;
      // Type to save user input for elements
      DataType element;

      do
      {
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "1: Enqueue" << endl;
         cout << "2: Dequeue" << endl;
         cout << "3: Front" << endl;
         cout << "4: Rear" << endl;
         cout << "5: Is empty?" << endl;
         cout << "6: Is full?" << endl;
         cout << "7: length" << endl;
         cout << "8: print" << endl;
         cout << "0: exit" << endl;
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "Option: ";

         cin >> opc;
         fflush(stdin);

         switch (opc)
         {
         case '1':
            cout << "Element to enque: ";
            cin >> element;
            queue->enqueue(element);
            queue->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '2':
            element = queue->dequeue();
            cout << "Dequeue: " << element << endl;
            queue->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '3':
            element = queue->front();
            cout << "Front: " << element << endl;
            queue->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;
            break;

         case '4':
            element = queue->rear();
            cout << "Rear: " << element << endl;
            queue->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '5':
            cout << "Is empty?: " << (queue->isEmpty() ? "true" : "false") << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '6':
            cout << "Is full?: " << (queue->isFull() ? "true" : "false") << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '7':
            cout << "Length: " << queue->length() << " / " << queue->size() << endl;
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;

         case '8':
            queue->print();
            // Wait 'till key press
            fflush(stdin);
            cin.get();
            break;
         
         default:
            opc = '0';
            cout << "Bye" << endl;
            break;
         }
      } while(opc != '0');
   }
   catch(QueueErrors err)
   {
      switch (err)
      {
      case QUEUE_OVERFLOW:
         cout << "Queue overflow!" << endl;
         break;

      case QUEUE_UNDERFLOW:
         cout << "Queue underflow!" << endl;
         break;
         break;

      case EMPTY_QUEUE:
         cout << "Empty queue!" << endl;
         break;
      
      default:
         cout << "~ Error ~" << endl;
         break;
      }
   }
}