#ifndef CITA_H
#define CITA_H

#include <string>

using namespace std;

class Cita {

	private:
		string _fecha; //DD/MM/YYYY
		int _duracion; //En minutos
		string _hora;  //Hora:Minuto HH:MM

	public:
		Cita () {
			_fecha = "";
			_duracion = -1;
			_hora = "";
		}

		Cita(string fecha, int duracion, string hora) {
			_fecha=fecha;
			_duracion=duracion;
			_hora=hora;
		}

		string getFecha() const {
			return _fecha;
		}

		int getDuracion() const {
			return _duracion;
		}

		string getHora() const {
			return _hora;
		}

		void setFecha(string fecha) {
			_fecha=fecha;
		}

		void setDuracion(int duracion) {
			_duracion=duracion;
		}

		void setHora(string hora) {
			_hora=hora;
		}

        bool operator== (const Cita &c) {
            if (c.getDuracion() == _duracion && c.getHora() == _hora && c.getFecha() == _fecha) {
                return true;
            }
            return false;
        }
};

#endif
