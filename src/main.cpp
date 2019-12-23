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

void menuPaciente(Paciente &p){
    int op=0;
    do{
        system("clear");
        printPaciente(p);

        colorPrint("\nElija una opcion:\n", Color::FG_CYAN, true);
        colorPrint("-------------------------------------------\n", Color::FG_CYAN, true);
        std::cout << "0. Salir al menu principal"                  << std::endl;
        std::cout << "1. Anadir nueva cita"                        << std::endl;
        std::cout << "2. Anadir nuevo tratamiento"                 << std::endl;
        std::cout << "3. Anadir nueva entrada al historial"        << std::endl;
        std::cout << "4. Citas del paciente"                       << std::endl;
        std::cout << "5. Historial medico del paciente"            << std::endl;
        std::cout << "6. Tratamientos del paciente"                << std::endl;
        std::cout << "7. Modificar datos del paciente"             << std::endl;
        std::cout << "8. Borrar paciente seleccionado"             << std::endl;
        
        std::cin >> op;
        
        switch(op){

            case ANADIR_CITA:{
                system("clear");
                Cita c;
                if(crearCita(c)) {
                    p.addCita(c);
                    FileIO::getInstance()->guardarPaciente(p);
                    std::cout << "La cita se añadio correctamente" << std::endl;
                }

                //Waits for user input
                std::cin.ignore();
                std::cin.get();

            }break;

            case ANADIR_TRATAMIENTO:{
                system("clear");
                Tratamiento t;
                if(crearTratamiento(t)) {
                    p.addTratamiento(t);
                    FileIO::getInstance()->guardarPaciente(p);
                    std::cout << "El tratamiento se añadio correctamente" << std::endl;
                }

                //Waits for user input
                std::cin.ignore();
                std::cin.get();

            }break;

            case ANADIR_HISTORIAL:{
                system("clear");
                EntradaHistorial e;
                if(crearEntradaHistorial(e)) {
                    p.addHistorial(e);
                    FileIO::getInstance()->guardarPaciente(p);
                    std::cout << "La entrada se añadio correctamente al historial" << std::endl;
                }

                //Waits for user input
                std::cin.ignore();
                std::cin.get();

            }break;

            case CITAS:{
                system("clear");
                std::list<Cita> citas = p.getCitas();
                Selection s = seleccionarCita(citas);
                if (s.index != -1) {
                    auto it = citas.begin();
                    for (int i = 0; i < s.index; i++) { it++; }

                    if (s.op == "edit") {
                        system("clear");
                        if(crearCita(*it)) {
                            p.setCitas(citas);
                            FileIO::getInstance()->guardarPaciente(p);
                            std::cout << "Cita modificada correctamente" << std::endl;
                        }
                        //Waits for user input
                        std::cin.ignore();
                        std::cin.get();
                    }
                    else if (s.op == "delete") {
                        system("clear");
                        citas.erase(it);
                        p.setCitas(citas);
                        FileIO::getInstance()->guardarPaciente(p);
                        std::cout << "Cita eliminada correctamente" << std::endl;

                        //Waits for user input
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
                
            }break;

            case HISTORIAL:{
                system("clear");
                printHistorial(p.getHistorial());
                
                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

            case TRATAMIENTOS:{
                system("clear");
                std::list<Tratamiento> tratamientos = p.getTratamientos();
                Selection s = seleccionarTratamiento(tratamientos);
                if (s.index != -1) {
                    auto it = tratamientos.begin();
                    for (int i = 0; i < s.index; i++) { it++; }

                    if (s.op == "edit") {
                        system("clear");
                        if(crearTratamiento(*it)) {
                            p.setTratamientos(tratamientos);
                            FileIO::getInstance()->guardarPaciente(p);
                            std::cout << "Tratamiento modificado correctamente" << std::endl;

                            //Waits for user input
                            std::cin.ignore();
                            std::cin.get();
                        }
                    }
                    else if (s.op == "delete") {
                        system("clear");

                        if (compFechas(getFechaHoy(), it->getFin())) {
                            tratamientos.erase(it);
                            p.setTratamientos(tratamientos);
                            FileIO::getInstance()->guardarPaciente(p);
                            std::cout << "Tratamiento eliminado correctamente" << std::endl;
                        }
                        else {
                            colorPrint("ERROR: No se puede eliminar un tratamiento ya finalizado\n", Color::FG_RED, true);
                        }
                        
                        //Waits for user input
                        std::cin.ignore();
                        std::cin.get();
                    }
                }

            }break;
            
            case MODIFICAR_PACIENTE:{
                system("clear");
                if(crearPaciente(p, true)) {
                    FileIO::getInstance()->guardarPaciente(p);
                    std::cout << "Paciente modificado correctamente" << std::endl;
                }

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

            case BORRAR_PACIENTE:{
                system("clear");
                FileIO::getInstance()->borrarPaciente(p);
                op = EXIT;
                std::cout << "Paciente borrado correctamente" << std::endl;

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

            case EXIT: break;

            default:{
                system("clear");
                colorPrint("ERROR: Opcion no valida\n", Color::FG_RED, true);

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

        }

    }while(op!=EXIT);

}

void menu(){

    int op=0;
    do{
        system("clear");
        std::cout << "MENU CLINICA" << std::endl;
 
        colorPrint("\nElija una opcion:\n", Color::FG_CYAN, true);
        colorPrint("---------------------------------\n", Color::FG_CYAN, true);
        std::cout << "0. Salir del programa"             << std::endl;
        std::cout << "1. Anadir nuevo paciente"          << std::endl;
        std::cout << "2. Mostrar citas"                  << std::endl;
        std::cout << "3. Consultar citas de hoy"         << std::endl;
        std::cout << "4. Lista de pacientes"             << std::endl;
        
        std::cin >> op;

        switch(op){

            case ANADIR_PACIENTE:{
                system("clear");
                Paciente p;
                if (crearPaciente(p)) {
                    //WARNING: Si el paciente que se ha creado tiene el mismo DNI que uno ya existente se reemplazara el antiguo,
                    //         por tanto se borraran el historial, citas y tratamientos
                    FileIO::getInstance()->guardarPaciente(p);
                    std::cout << "Paciente anadido correctamente" << std::endl;
                }

                //Waits for user input
                std::cin.get();
            }break;

            case MOSTRAR_CITAS:{
                system("clear");
                printCitas(FileIO::getInstance()->getTodasCitas());

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

            case MOSTRAR_CITAS_HOY:{
                system("clear");
                printCitas(FileIO::getInstance()->getCitasHoy());

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
            }break;

            case LISTA_PACIENTES:{
                system("clear");
                Paciente p = seleccionarPaciente();
                if (p.getDNI() != "NULL") {
                    menuPaciente(p);
                }
            }break;

            case EXIT:{
                system("clear");
            }break;


            default:{
                system("clear");
                colorPrint("ERROR: Opcion no valida\n", Color::FG_RED, true);

                //Waits for user input
                std::cin.ignore();
                std::cin.get();
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