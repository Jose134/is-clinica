#ifndef CITAS_H
#define CITAS_H
#include <string>
using namespace std;

class Cita{

	private: 
		string _fecha;
		int _duracion;
		string _hora;
	
	public:
		Cita();
	
		string getFecha(){
			return _fecha;
		}
	
		int getDuracion(){
			return _duracion;
		}

		string getHora(){
			return _hora;
		}

		void setFecha(string fecha){
			_fecha=fecha;
		}

		void setDuracion(int duracion){
			_duracion=duracion;
		}

		void setHora(string hora){
			_hora=hora;
		}
};

#endif 
