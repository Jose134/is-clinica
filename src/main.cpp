#include <iostream>

#include "helpers.h"

#include "paciente.h"
#include "Cita.h"
#include "FileIO.h"
#include "EntradaHistorial.h"
#include "Tratamiento.h"

#include <string>
#include <list>

#define OP_EXIT 0

void menu (int opcion) {
   switch (opcion) {
      case 1:
         printPacientes(FileIO::getInstance()->getTodosPacientes());
         break;
   }
}

int main () {
   //TO DO: Implement menu
   int opcion = -1;
   do {
      std::cin >> opcion;

      menu(opcion);
   } while(opcion != OP_EXIT);
}