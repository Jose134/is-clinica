//     |-----------------------------------------------------|
//     |   AÑADIR STD:: a las strings, cout, cin y endl!!!   |
//     |-----------------------------------------------------|
//
// Mete estas funciones en helpers.cpp y helpers.h cuando las acabes pls <3

//Eso hecho falta meter revisar si existe cita lo hago o ya esta hecho?


Citas crearCita(){

  system("clear");
  std::string aux1;//Fecha
  int aux2;//Duracion
  std::string aux3;//Hora
  std::cout<<"Bienvenido a la creación de citas:"<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Por favor introduzce la fecha de la cita: (ejemplo:DD/MM/YYYY)"<std::endl;
  std::cin>>aux1;
  std::cout<<"Ahora por favor, introduce cuando va a durar la cita en minutos:"<<std::endl;
  std::cin>>aux2;
  std::cout<<"Por ultimo introduce a que hora va a ser la cita: (Ejemplo HH:MM)"<<std::endl;
  std::cin>>aux3;
  //revisar si  a esa hora y ese dia esta libre
  if(//esta libre){
      Citas c;
      c.setFecha(aux1);
      c.setDuracion(aux2);
      c.setHora(aux3);
      std::cout<<"Se ha introducido correctamente la cita."<<std::endl;
    return c;
  }
  else(//No libre){
      std::cout<<"Error, esa hora a ese dia ya hay una cita, disculpa las molestias pero no se ha podido reservar la cita."<<std::endl;
  }
}

void crearEntradaHistotial(){//Aqui faltaria pasarle el struct Entrada historia no?

  system("clear");
  std::cout<<"Bienvenido a la creación de un historial medico:"<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Por favor introduzce la fecha cuando vino el paciente: (ejemplo:DD/MM/YYYY)"<std::endl;
  std::cin>>EntradaHistorial.fecha;
  std::cout<<"Por ultimo introduce que sintomas tenia el pacientes:"<<std::endl;
  std::cin>>EntradaHistorial.sintomas;

}

Tratamiento crearTratamiento(){

  system("clear");
  Tratamiento t;
  std::string auxstring;
  int auxint;
  std::cout<<"Bienvenido a la creación de un tratamiento:"<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Por favor introduzce el medicamento que necesita el paciente:"<std::endl;
  std::cin>>auxstring;
  t.setMedicamento(auxstring);
  std::cout<<"Ahora por favor, introduzce por pantalla la dosis que debe tomar el paciente: "<<std::endl;
  std::cin>>auxint;
  t.setDosis(auxint);
  std::cout<<"Ahora por favor, introduzce por pantalla la frecuencia que debe tomar el medicamento el paciente: "<<std::endl;
  std::cin>>auxint;
  t.setFrecuencia(auxint);
  std::cout<<"Acontinuacion, introduce el comienzo de cuando debe tomar el medicamento:"<<std::endl;
  std::cin>>auxstring;
  t.setFin(auxstring);
  std::cout<<"Por ultimo el fin de cuando debe tomar el medicamento:"<<std::endl;
  return t;
}
