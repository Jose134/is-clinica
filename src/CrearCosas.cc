void Cita::crearCita(){

    system("clear");
    string aux1, aux3;
    int aux2;
    cout<<"Bienvenido a la creación de citas:"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Por favor introduzce la fecha de la cita: (ejemplo:DD/MM/YYYY)"<endl;
    cin>>aux1;
    cout<<"Ahora por favor, introduce cuando va a durar la cita en minutos:"<<endl;
    cin>>aux2;
    cout<<"Por ultimo introduce a que hora va a ser la cita: (Ejemplo HH:MM)"<<endl;
    cin>>aux3;
    //revisar si  a esa hora y ese dia esta libre
    if(//esta libre){
      _fecha=aux1;
      _duracion=aux2;
      _hora=aux3;
      cout<<"Se ha introducido correctamente la cita."<<endl;
    }
    else(//No libre){
      cout<<"Error, esa hora a ese dia ya hay una cita, disculpa las molestias pero no se ha podido reservar la cita."<<endl;
    }
  }

  void CrearEntradaHistotial(){

    system("clear");
    cout<<"Bienvenido a la creación de un historial medico:"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Por favor introduzce la fecha cuando vino el paciente: (ejemplo:DD/MM/YYYY)"<endl;
    cin>>EntradaHistorial.fecha;
    cout<<"Por ultimo introduce que sintomas tenia el pacientes:"<<endl;
    cin>>EntradaHistorial.sintomas;

  }

  void Tratamiento::CrearTratamiento(){

    system("clear");
    cout<<"Bienvenido a la creación de un tratamiento:"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Por favor introduzce el medicamento que necesita el paciente:"<endl;
    cin>>_medicamento;
    cout<<"Ahora por favor, introduzce por pantalla la dosis que debe tomar el paciente: "<<endl;
    cin>>_dosis;
    cout<<"Ahora por favor, introduzce por pantalla la frecuencia que debe tomar el medicamento el paciente: "<<endl;
    cin>>_frecuencia;
    cout<<"Acontinuacion, introduce el comienzo de cuando debe tomar el medicamento:"<<endl;
    cin>>_comienzo;
    cout<<"Por ultimo el fin de cuando debe tomar el medicamento:"<<endl;
  }
