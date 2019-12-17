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
#define LISTA_PACIENTES 4

#define ANADIR_CITA 1
#define ANADIR_TRATAMIENTO 2
#define ANADIR_HISTORIAL 3
#define CITAS 4
#define HISTORIAL 5
#define TRATAMIENTOS 6
#define MODIFICAR_PACIENTE 7
#define BORRAR_PACIENTE 8

void menuPaciente(Paciente p){
    int op=0;
    do{
        std::cout << "MENU Paciente:" << std::endl;
        printPaciente(p);

        std::cout << "0. Salir al menu principal"                 << std::endl;
        std::cout << "1. Anadir nueva cita"                       << std::endl;
        std::cout << "2. Anadir nuevo tratamiento"                << std::endl;
        std::cout << "3. Anadir nueva entrada al historial"       << std::endl;
        std::cout << "4. Consultar citas del paciente"            << std::endl;
        std::cout << "5. Consultar historial medico del paciente" << std::endl;
        std::cout << "6. Consultar tratamientos del paciente"     << std::endl;
        std::cout << "7. Modificar datos del paciente"            << std::endl;
        std::cout << "8. Borrar paciente seleccionado"            << std::endl;
        
        //std::cout << "05. Modificar tratamiento"<<std::endl;
        //std::cout << "06. Mover una cita del paciente"<<std::endl;
        //std::cout << "07. Cancelarle una cita"<<std::endl;
        
        std::cin >> op;
        
        switch(op){

            case ANADIR_CITA:{
                system("clear");
                std::cout << "Has elejido Anadirle nueva cita."<<std::endl;

            }break;

            case ANADIR_TRATAMIENTO:{
                system("clear");
                cout << "Has elejido Anadirle nuevo tratamiento."<<std::endl;

            }break;

            case ANADIR_HISTORIAL:{
                system("clear");
                std::cout << "Has elejido Anadirle nueva entrada a historial."<<std::endl;

            }break;

            case CITAS:{
                system("clear");
                std::cout << "Has elejido Consultar citas del paciente."<<std::endl;

            }break;

            case HISTORIAL:{
                system("clear");
                std::cout << "Has elejido Consultar historial medico del paciente."<<std::endl;

            }break;

            case TRATAMIENTOS:{
                system("clear");
                std::cout << "Has elejido Consultar tratamientos del paciente."<<std::endl;

            }break;
            
            case MODIFICAR_PACIENTE:{
                system("clear");
            }break;

            case BORRAR_PACIENTE:{
                system("clear");
                std::cout << "Has elejido Borrar paciente seleccionado."<<std::endl;

            }break;

            case EXIT:{
                system("clear");
            }break;


            default:{
                system("clear");
                colorPrint("ERROR: Opcion no valida", Color::FG_RED, true);
            }break;

        }

    }while(op!=EXIT);

}

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
        std::cout << "4. Lista de pacientes"             << std::endl;
        
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

            case LISTA_PACIENTES:{
                system("clear");
                /*
                std::list<Paciente> pacientes = FileIO::getInstance()->getTodosPacientes();
                int index = seleccionarPaciente(pacientes);
                auto p = pacientes.begin();
                for (int i = 0; i < index; i++) { p++; }

                menuPaciente(*p);
                */

                Paciente p = seleccionarPaciente();
                if (p.getDNI() != "NULL") {
                    menuPaciente(p);
                }
            }break;

            case 5: {
                std::cout << "Introduzca el nombre: " << std::endl;
                std::string nombre;
                std::cin >> nombre;
                std::list<Paciente> busqueda = FileIO::getInstance()->buscarPacientes(nombre);
                int index = seleccionarPaciente(busqueda);
                auto p = busqueda.begin();
                for (int i = 0; i < index; i++) { p++; }

                menuPaciente(*p);
            }

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

int main (int argc, char** argv) {
    if (argc > 1) {
        if (argv[1] == "-nc" || argv[1] == "--no-colors") {
            setColors(false);
        }
    }
   
    menu();
}
