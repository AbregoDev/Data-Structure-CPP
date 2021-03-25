#include <iostream>
using std::cout;
using std::endl;

enum dias
{
   LUNES,
   MARTES,
   MIERCOLES,
   JUEVES,
   VIERNES,
   SABADO,
   DOMINGO
};

enum climas
{
   CALIDO,
   LLUVIOSO,
   VENTISCA,
   FRIO
};

void decision(dias d, climas c);

int main()
{
   // Crear un programa que reciba un dia de la semana
   // y el clima de ese dia (calido, lluvioso, ventisca, frio),
   // y decidir si salir de compras segun el siguiente criterio:
   // es lunes o miercoles y está calido,
   // es domingo y esta lluvioso
   // o es jueves y hace frio o hay ventisca

   decision(LUNES, CALIDO); // Sí
   decision(MARTES, LLUVIOSO); // No
   decision(VIERNES, FRIO); // No
}

void decision(dias dia, climas clima)
{
   if((dia == LUNES || dia == MIERCOLES) && clima == CALIDO)
   {
      cout << "Vamos de compras" << endl;
   } else if(dia == DOMINGO && clima == LLUVIOSO)
   {
      cout << "Vamos de compras" << endl;
   } else if(dia == JUEVES && (clima == FRIO || clima == VENTISCA))
   {
      cout << "Vamos de compras" << endl;
   } else
   {
      cout << "Otro dia";
   }
}