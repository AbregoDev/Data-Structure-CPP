#include "ListaCircular.h"

int main()
{
   ListaCircular *lista = new ListaCircular();

   try
   {
      char opc;
      Tipo n, e;
      int p;

      do
      {
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "1: Insertar al principio" << endl;
         cout << "2: Insertar al final" << endl;
         cout << "3: Insertar en posicion" << endl;
         cout << "4: Buscar por incidencia" << endl;
         cout << "5: Buscar por indice" << endl;
         cout << "6: Eliminar por incidencia" << endl;
         cout << "7: Eliminar por posicion" << endl;
         // cout << "8: Invertir" << endl;
         cout << "0: Salir" << endl;
         cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
         cout << "Opcion: ";

         cin >> opc;
         fflush(stdin);

         switch (opc)
         {
         case '1':
            cout << "Numero a insertar: ";
            cin >> n;
            lista->insertarAlPrincipio(n);
            lista->imprimir();
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '2':
            cout << "Numero a insertar: ";
            cin >> n;
            lista->insertarAlFinal(n);
            lista->imprimir();
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '3':
            cout << "Numero a insertar: ";
            cin >> n;
            cout << "Posicion en la que insertar: ";
            cin >> p;
            lista->insertarEnPosicion(n, p);
            lista->imprimir();
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '4':
            cout << "Numero a buscar: ";
            cin >> n;
            e = lista->buscarElemento(n);
            cout << "Posicion: " << e << endl;
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '5':
            cout << "Posicion a obtener: ";
            cin >> p;
            e = lista->buscarPorIndice(p);
            cout << "Elemento: " << e << endl;
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '6':
            cout << "Numero a eliminar: ";
            cin >> n;
            lista->eliminarElemento(n);
            lista->imprimir();
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         case '7':
            cout << "Posicion eliminar: ";
            cin >> p;
            lista->eliminarPorIndice(p);
            lista->imprimir();
            // Esperar antes de volver a mostrar el menú
            fflush(stdin);
            cin.get();
            break;

         // case '8':
         //    lista = lista->invertir();
         //    lista->imprimir();
         //    // Esperar antes de volver a mostrar el menú
         //    fflush(stdin);
         //    cin.get();
         //    break;
         
         default:
            opc = '0';
            cout << "Ha sido un placer atenderle" << endl;
            break;
         }
      } while(opc != '0');
   }
   catch(ErroresListas exc)
   {
      switch (exc)
      {
      case INDEX_OUT_OF_RANGE:
         cout << "Indice no valido" << endl;
         break;

      case EMPTY_LIST:
         cout << "La lista esta vacia" << endl;
         break;
      
      default:
         cout << "Otro error" << endl;
         break;
      }
   }
}