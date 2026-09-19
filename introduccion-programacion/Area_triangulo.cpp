#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

int main() {

   //DEFINICIÓN DE VARIABLES
   float base, altura, lado, base_cuadrada, lado_cuadrado;
   int valor;
   bool no_base, no_valor, error, continuar_bool, validar_continuar;
   string continuar;


   //BIENVENIDA
   cout <<"///////////////////////////////////////////////" << endl;
   cout <<"BIENVENIDO AL CALCULADOR DE AREA DE TRIANGULOS" << endl;
   cout <<"///////////////////////////////////////////////" << endl;
   cout <<"" << endl;

   //INGRESO DE DATOS
do {
   do {
      cout <<"Inserta la base de tu triangulo" << endl;
      cin >> base;
      if (cin.fail() || base <= 0 ){
         cin.clear();
         cin.ignore (numeric_limits<streamsize>::max(), '\n');
         no_base = true;
         cout << "ERROR: Valor no valido. Favor de volver a intentar" << endl;
      } else {
         no_base = false;
         cin.ignore (numeric_limits<streamsize>::max(), '\n');
      }
      } while (no_base == true);
   do {
      cout <<"Inserta el valor que deseas añadir: " << endl;
      cout <<"1.- Valor de la altura" << endl;
      cout <<"2.- Valor de un lado del triangulo" << endl;
      cout <<"Ingrese 1 o 2" << endl;
      cin >> valor;
      if (valor == 1 || valor == 2){
         no_valor = false;
         cin.ignore (numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << "ERROR: Valor invalido. Favor de volver a intentar" << endl;
        no_valor = true;
         cin.clear();
         cin.ignore (numeric_limits<streamsize>::max(), '\n');
      }
      } while (no_valor == true);

      if (valor == 1) {
         do {
         cout << "Ingrese la altura del triangulo" << endl;
         cin >> altura;
         if (cin.fail() || altura <= 0){
            cout << "ERROR: Valor ingresado no valido. Favor de volver a intentar" << endl;
            cin.clear();
            cin.ignore (numeric_limits<streamsize>::max(), '\n');
            error = true;
         } else {
            error = false;
         }
         } while (error == true);
         } // TERMINA EL IF 1

      if (valor == 2) {
         do {
         cout << "Ingrese el valor del lado del triangulo" << endl;
         cin >> lado;
         if (cin.fail() || lado <= 0){
            cout << "ERROR: Valor ingresado no valido. Favor de volver a intentar" << endl;
            cin.clear();
            cin.ignore (numeric_limits<streamsize>::max(), '\n');
            error = true;
         } else {
            error = false;
         }
      } while (error == true);
      } //TERMINA EL IF 2

   //CALCULOS
   if (valor == 1){
      cout << "El area del triangulo es de " << (base*altura)/2 << " unidades cuadradas" << endl;
   } else {
     base = base/2;
     base_cuadrada = base * base;
     lado_cuadrado = lado * lado;
     altura = sqrt(lado_cuadrado-base_cuadrada);

     cout << "El area del triangulo es de " << altura << " unidades cuadradas" << endl;
   }

   cin.ignore (numeric_limits<streamsize>::max(), '\n'); //LIMPIEZA

   //CONTINUACION
   do {
   cout << "¿Desea continuar la operacion? Inserte si o no" << endl;
   getline (cin, continuar);
   for (char &c : continuar) {
     c = tolower (c);
     }
   if (continuar != "si" && continuar != "no") {
      cout << "ERROR: Valor no valido. Favor de volver a intentar" << endl;
      validar_continuar = false;
   }
   if (continuar == "si"){
       continuar_bool = true;
       validar_continuar = true;
   }
   if (continuar == "no") {
       continuar_bool = false;
       validar_continuar = true;
   }
   } while (validar_continuar == false);

} while (continuar_bool == true);

return 0;
}

