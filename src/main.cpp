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
      case 2:
         printCitas(FileIO::getInstance()->getTodasCitas());
         break;
   }
}

int main (int argc, char** argv) {
   if (argc > 1) {
      if (argv[1] == "-nc" || argv[1] == "--no-colors") {
         setColors(false);
      }
   }

   Paciente p("testdni", "owo", 456, "si", "04/08/2000", Procedencia::Seguro);
   p.addCita(Cita("20/12/2000", 30, "12:30"));
   p.addCita(Cita("21/04/2020", 10, "09:10"));
   FileIO::getInstance()->guardarPaciente(p);

   //TO DO: Implement menu
   int opcion = -1;
   do {
      std::cin >> opcion;

      menu(opcion);
   } while(opcion != OP_EXIT);
}