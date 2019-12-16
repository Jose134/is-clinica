#include<iostream>
#include <stdlib.h>

using namespace std;

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

    case 1:{
      system("clear");
      cout << "Has elejido nadir nuevo paciente."<<endl;

    }break;

    case 2:{
      system("clear");
      printCitas(FileIO::getInstance()->getTodasCitas());
      cout << "Has elejido Mostrar citas."<<endl;

    }break;

    case 3:{
      system("clear");
      cout << "Has elejido Mostrar lista con pacientes."<<endl;

    }break;

    case 4:{
      system("clear");
      cout << "Has elejido Busqueda por nombre."<<endl;

    }break;

    case 5:{
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

    cout<<"Ya elegido un paciente eleige que quieres hacer con el:"<<endl;
    cout<<"01. Anadirle nueva cita"<<endl;
    cout<<"02. Anadirle nuevo tratamiento"<<endl;
    cout<<"03. Anadirle nueva entrada a historial"<<endl;
    cout<<"04. Mostrar toda la informacion del paciente seleccionado"<<endl;
    cout<<"05. Modicar paciente"<<endl;
    cout<<"06. Modificarle el tratamiento"<<endl;
    cout<<"07. Borrar paciente seleccionado"<<endl;
    cout<<"08. Mover una cita del paciente"<<endl;
    cout<<"09. Cancelarle una cita"<<endl;
    cout<<"10. Consultar citas del paciente"<<endl;
    cout<<"11. Consultar historial medico del paciente"<<endl;
    cout<<"12. Consultar tratamientos del paciente"<<endl;
    cout<<"13. Salir al menu principal\n"<<endl;
    cin>>num;
    switch(num){

    case 1:{
      system("clear");
      cout << "Has elejido Anadirle nueva cita."<<endl;

    }break;

    case 2:{
      system("clear");
      cout << "Has elejido Anadirle nuevo tratamiento."<<endl;

    }break;

    case 3:{
      system("clear");
      cout << "Has elejido Anadirle nueva entrada a historial."<<endl;

    }break;

    case 4:{

      system("clear");
      printPacientes(FileIO::getInstance()->getTodosPacientes());
      cout << "Has elejido Mostrar toda la informacion del paciente seleccionado."<<endl;

    }break;

    case 5:{
      system("clear");
      cout << "Has elejido Modificar paciente."<<endl;

    }break;

    case 6:{
      system("clear");
      cout << "Has elejido Modificarle el tratamiento."<<endl;

    }break;

    case 7:{
      system("clear");
      cout << "Has elejido Borrar paciente seleccionado."<<endl;

    }break;

    case 8:{
      system("clear");
      cout << "Has elejido Mover una cita del paciente."<<endl;

    }break;

    case 9:{
      system("clear");
      cout << "Has elejido Cancelarle una cita."<<endl;

    }break;

    case 10:{
      system("clear");
      cout << "Has elejido Consultar citas del paciente."<<endl;

    }break;

    case 11:{
      system("clear");
      cout << "Has elejido Consultar historial medico del paciente."<<endl;

    }break;

    case 12:{
      system("clear");
      cout << "Has elejido Consultar tratamientos del paciente."<<endl;

    }break;


    case 13:{
      system("clear");
      cout << "Has elejido Salir al menu principal."<<endl;

    }break;


    default:{

      system("clear");
      cout << "Su numero no existe"<<endl;

    }break;

  }

  }while(num!=13);

  }

