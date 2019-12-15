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
    cout<<"01. Anadir nuevo paciente"<<endl;
    cout<<"02. Anadir nueva cita"<<endl;
    cout<<"03. Anadir nuevo tratamiento a paciente"<<endl;
    cout<<"04. Anadir nueva entrada a historial de paciente"<<endl;
    cout<<"05. Mostrar citas"<<endl;
    cout<<"06. Mostrar lista con pacientes"<<endl;
    cout<<"07. Mostrar toda la informacion del paciente seleccionado"<<endl;
    cout<<"08. Modificar paciente"<<endl;
    cout<<"09. Modificar tratamiento"<<endl;
    cout<<"10. Busqueda por nombre"<<endl;
    cout<<"11. Borrar paciente"<<endl;
    cout<<"12. Mover cita"<<endl;
    cout<<"13. Cancelar cita"<<endl;
    cout<<"14. Consultar citas de hoy"<<endl;
    cout<<"15. Consultar citas de un paciente"<<endl;
    cout<<"16. Consultar historial medico de un paciente"<<endl;
    cout<<"17. Consultar tratamientos de un paciente"<<endl;
    cout<<"18. Salir del programa\n"<<endl;
    cin>>num;
    switch(num){

    case '1':{

      cout << "Has elejido nadir nuevo paciente."<<endl;

    }break;

    case '2':{

      cout << "Has elejido Anadir nueva cita."<<endl;

    }break;

    case '3':{

      cout << "Has elejido Anadir nuevo tratamiento a paciente."<<endl;

    }break;

    case '4':{

      cout << "Has elejido Anadir nueva entrada a historial de paciente."<<endl;

    }break;

    case '5':{

      cout << "Has elejido Mostrar citas."<<endl;

    }break;

    case '6':{

      cout << "Has elejido Mostrar lista con pacientes."<<endl;

    }break;

    case '7':{

      cout << "Has elejido Mostrar toda la informacion del paciente seleccionado."<<endl;

    }break;

    case '8':{

      cout << "Has elejido Modificar paciente."<<endl;

    }break;

    case '9':{

      cout << "Has elejido Modificar tratamiento."<<endl;

    }break;

    case '10':{

      cout << "Has elejido Busqueda por nombre."<<endl;

    }break;

    case '11':{

      cout << "Has elejido Borrar paciente."<<endl;

    }break;

    case '12':{

      cout << "Has elejido Mover cita."<<endl;

    }break;

    case '13':{

      cout << "Has elejido Cancelar cita."<<endl;

    }break;

    case '14':{

      cout << "Has elejido Consultar citas de hoy."<<endl;

    }break;

    case '15':{

      cout << "Has elejido Consultar citas de un paciente."<<endl;

    }break;

    case '16':{

      cout << "Has elejido Consultar historial medico de un paciente."<<endl;

    }break;

    case '17':{

      cout << "Has elejido Consultar tratamientos de un paciente."<<endl;

    }break;

    case '18':{

      cout << "Has elejido Salir del programa."<<endl;

    }break;


    default:{


      cout << "Su numero no existe"<<endl;

    }break;

  }

}while(num!=18);

}
