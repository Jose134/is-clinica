#include <iostream>

#include "helpers.h"

#include "paciente.h"
#include "Cita.h"
#include "FileIO.h"
#include "EntradaHistorial.h"
#include "Tratamiento.h"

#include <string>
#include <list>

#define EXIT 0
#define ANADIR_PACIENTE 1
#define MOSTRAR_CITAS 2
#define MOSTRAR_CITAS_HOY 3
#define MOSTRAR_PACIENTES 4
#define Busqueda_por_nombre 5
#define Anadirle_nueva_cita 6
#define Anadirle_nuevo_tratamiento 7
#define Anadirle_nueva_entrada_a_historial 8
#define Mostrar_toda_la_informacion_del_paciente_seleccionado 9
#define Modicar_paciente 10
#define Modificarle_el_tratamiento 11
#define Borrar_paciente_seleccionado 12
#define Mover_una_cita_del_paciente 13
#define Cancelarle_una_cita 14
#define Consultar_citas_del_paciente 15
#define Consultar_historial_medico_del_paciente 16
#define Consultar_tratamientos_del_paciente 17

void menu(){

    int op=0;
    do{
        std::cout << "MENU CLINICA:"                     << std::endl;
 
        std::cout << "Elija una opcion:"                 << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "0. Salir del programa"             << std::endl;
        std::cout << "1. Anadir nuevo paciente"          << std::endl;
        std::cout << "2. Mostrar citas"                  << std::endl;
        std::cout << "3. Consultar citas de hoy"         << std::endl;
        std::cout << "4. Mostrar lista con pacientes"    << std::endl;
        std::cout << "5. Busqueda por nombre"            << std::endl;
        
        std::cin >> op;

        switch(op){

            case ANADIR_PACIENTE:{
                system("clear");
                std::cout << "Has elejido nadir nuevo paciente." << std::endl;

            }break;

            case MOSTRAR_CITAS:{
                system("clear");
                printCitas(FileIO::getInstance()->getTodasCitas());
            }break;

            case MOSTRAR_CITAS_HOY:{
                system("clear");
                printCitas(FileIO::getInstance()->getCitasHoy());

            }break;

            case MOSTRAR_PACIENTES:{
                system("clear");
                std::list<Paciente> pacientes = FileIO::getInstance()->getTodosPacientes();
                int index = seleccionarPaciente(pacientes);
                auto p = pacientes.begin();
                for (int i = 0; i < index; i++) { p++; }

                menuPaciente(*p);
            }break;

            case EXIT:{
                system("clear");
                std::cout << "Has elejido Salir del programa." << std::endl;

            }break;


            default:{
                system("clear");
                colorPrint("ERROR: Opcion no valida\n", Color::FG_RED, true);
            }break;

        }

    }while(op!=EXIT);

}

void menuPaciente(Paciente p){
    int op=0;
    do{
      std::cout << "MENU Paciente:\n"<<std::endl;
 
      std::cout << "00. Salir al menu principal\n"<<std::endl;
      std::cout << "06. Anadirle nueva cita"<<std::endl;
      std::cout << "07. Anadirle nuevo tratamiento"<<std::endl;
      std::cout << "08. Anadirle nueva entrada a historial"<<std::endl;
      std::cout << "09. Mostrar toda la informacion del paciente seleccionado"<<std::endl;
      std::cout << "10. Modicar paciente"<<std::endl;
      std::cout << "11. Modificarle el tratamiento"<<std::endl;
      std::cout << "12. Borrar paciente seleccionado"<<std::endl;
      std::cout << "13. Mover una cita del paciente"<<std::endl;
      std::cout << "14. Cancelarle una cita"<<std::endl;
      std::cout << "15. Consultar citas del paciente"<<std::endl;
      std::cout << "16. Consultar historial medico del paciente"<<std::endl;
      std::cout << "17. Consultar tratamientos del paciente"<<std::endl;
      std::cin>>op;
      
      switch(op){

      case Anadirle_nueva_cita:{
        system("clear");
        std::cout << "Has elejido Anadirle nueva cita."<<std::endl;

      }break;

      case Anadirle_nuevo_tratamiento:{
        system("clear");
        cout << "Has elejido Anadirle nuevo tratamiento."<<std::endl;

      }break;

      case Anadirle_nueva_entrada_a_historial:{
        system("clear");
        std::cout << "Has elejido Anadirle nueva entrada a historial."<<std::endl;

      }break;

      case Mostrar_toda_la_informacion_del_paciente_seleccionado:{

        system("clear");
        printPacientes(FileIO::getInstance()->getTodosPacientes());
        std::cout << "Has elejido Mostrar toda la informacion del paciente seleccionado."<<std::endl;

      }break;

      case Modicar_paciente:{
        system("clear");
        std::cout << "Has elejido Modificar paciente."<<std::endl;

      }break;

      case Modificarle_el_tratamiento:{
        system("clear");
        std::cout << "Has elejido Modificarle el tratamiento."<<std::endl;

      }break;

      case Borrar_paciente_seleccionado:{
        system("clear");
        std::cout << "Has elejido Borrar paciente seleccionado."<<std::endl;

      }break;

      case Mover_una_cita_del_paciente:{
        system("clear");
        std::cout << "Has elejido Mover una cita del paciente."<<std::endl;

      }break;

      case Cancelarle_una_cita:{
        system("clear");
        std::cout << "Has elejido Cancelarle una cita."<<std::endl;

      }break;

      case Consultar_citas_del_paciente:{
        system("clear");
        std::cout << "Has elejido Consultar citas del paciente."<<std::endl;

      }break;

      case Consultar_historial_medico_del_paciente:{
        system("clear");
        std::cout << "Has elejido Consultar historial medico del paciente."<<std::endl;

      }break;

      case Consultar_tratamientos_del_paciente:{
        system("clear");
        std::cout << "Has elejido Consultar tratamientos del paciente."<<std::endl;

      }break;


      case EXIT:{
        system("clear");
        std::cout << "Has elejido Salir al menu principal."<<std::endl;

      }break;


      default:{

        system("clear");
        std::cout << "Su opero no existe"<<std::endl;

      }break;

    }

    }while(op!=EXIT);

}


int main (int argc, char** argv) {
    if (argc > 1) {
        if (argv[1] == "-nc" || argv[1] == "--no-colors") {
            setColors(false);
        }
    }
   
    menu();
}
