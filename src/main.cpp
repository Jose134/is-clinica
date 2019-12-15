#include <iostream>

#include "helpers.h"

#include "paciente.h"
#include "Cita.h"
#include "FileIO.h"
#include "EntradaHistorial.h"
#include "Tratamiento.h"

#include <string>
#include <list>

#define Anadir_nuevo_paciente 1
#define Mostrar_citas 2
#define Mostrar_lista_con_pacientes 3
#define Busqueda_por_nombre 4
#define Consultar_citas_de_hoy 5
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

  int num=0;
  do{
    system("clear");
    //colorPrint(line, Color::FG_MAGENTA, true);
    cout<<"MENU CLINICA:\n"<<endl;

    cout<<"Elige una de estas opciones:"<<endl;
    cout<<"1. Anadir nuevo paciente"<<endl;
    cout<<"2. Mostrar citas"<<endl;
    cout<<"3. Mostrar lista con pacientes"<<endl;
    cout<<"4. Busqueda por nombre"<<endl;
    cout<<"5. Consultar citas de hoy"<<endl;
    cout<<"6. Salir del programa\n"<<endl;
    cin>>num;
    switch(num){

    case Anadir_nuevo_paciente:{
      system("clear");
      cout << "Has elejido nadir nuevo paciente."<<endl;

    }break;

    case Mostrar_citas:{
      system("clear");
      printCitas(FileIO::getInstance()->getTodasCitas());
      cout << "Has elejido Mostrar citas."<<endl;

    }break;

    case Mostrar_lista_con_pacientes:{
      system("clear");
      cout << "Has elejido Mostrar lista con pacientes."<<endl;

    }break;

    case Busqueda_por_nombre:{
      system("clear");
      cout << "Has elejido Busqueda por nombre."<<endl;

    }break;

    case Consultar_citas_de_hoy:{
      system("clear");
      cout << "Has elejido Consultar citas de hoy."<<endl;

    }break;

    case 6:{
      system("clear");
      cout << "Has elejido Salir del programa."<<endl;

    }break;


    default:{

      system("clear");
      cout << "su numero no existe"<<endl;

    }break;

  }

}while(num!=6);

}

void menupaciente(){

  int num=0;
  do{
    //colorPrint(line, Color::FG_MAGENTA, true);
    cout<<"MENU Paciente:\n"<<endl;

    cout<<"Ya seleccionado un paciente eleige que quieres hacer con el:"<<endl;
    cout<<"06. Anadirle nueva cita"<<endl;
    cout<<"07. Anadirle nuevo tratamiento"<<endl;
    cout<<"08. Anadirle nueva entrada a historial"<<endl;
    cout<<"09. Mostrar toda la informacion del paciente seleccionado"<<endl;
    cout<<"10. Modicar paciente"<<endl;
    cout<<"11. Modificarle el tratamiento"<<endl;
    cout<<"12. Borrar paciente seleccionado"<<endl;
    cout<<"13. Mover una cita del paciente"<<endl;
    cout<<"14. Cancelarle una cita"<<endl;
    cout<<"15. Consultar citas del paciente"<<endl;
    cout<<"16. Consultar historial medico del paciente"<<endl;
    cout<<"17. Consultar tratamientos del paciente"<<endl;
    cout<<"18. Salir al menu principal\n"<<endl;
    cin>>num;
    switch(num){

    case Anadirle_nueva_cita:{
      system("clear");
      cout << "Has elejido Anadirle nueva cita."<<endl;

    }break;

    case Anadirle_nuevo_tratamiento:{
      system("clear");
      cout << "Has elejido Anadirle nuevo tratamiento."<<endl;

    }break;

    case Anadirle_nueva_entrada_a_historial:{
      system("clear");
      cout << "Has elejido Anadirle nueva entrada a historial."<<endl;

    }break;

    case Mostrar_toda_la_informacion_del_paciente_seleccionado:{

      system("clear");
      printPacientes(FileIO::getInstance()->getTodosPacientes());
      cout << "Has elejido Mostrar toda la informacion del paciente seleccionado."<<endl;

    }break;

    case Modicar_paciente:{
      system("clear");
      cout << "Has elejido Modificar paciente."<<endl;

    }break;

    case Modificarle_el_tratamiento:{
      system("clear");
      cout << "Has elejido Modificarle el tratamiento."<<endl;

    }break;

    case Borrar_paciente_seleccionado:{
      system("clear");
      cout << "Has elejido Borrar paciente seleccionado."<<endl;

    }break;

    case Mover_una_cita_del_paciente:{
      system("clear");
      cout << "Has elejido Mover una cita del paciente."<<endl;

    }break;

    case Cancelarle_una_cita:{
      system("clear");
      cout << "Has elejido Cancelarle una cita."<<endl;

    }break;

    case Consultar_citas_del_paciente:{
      system("clear");
      cout << "Has elejido Consultar citas del paciente."<<endl;

    }break;

    case Consultar_historial_medico_del_paciente:{
      system("clear");
      cout << "Has elejido Consultar historial medico del paciente."<<endl;

    }break;

    case Consultar_tratamientos_del_paciente:{
      system("clear");
      cout << "Has elejido Consultar tratamientos del paciente."<<endl;

    }break;


    case 18:{
      system("clear");
      cout << "Has elejido Salir al menu principal."<<endl;

    }break;


    default:{

      system("clear");
      cout << "Su numero no existe"<<endl;

    }break;

  }

  }while(num!=18);

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
   
   menu();
    //hay otro menu pero eso va cuando busques paciente

}
