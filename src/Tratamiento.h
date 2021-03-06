#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include <string>
using namespace std;

class Tratamiento{

	private:
		string _medicamento;
		int _dosis;
		int _frecuencia;
		string _comienzo;
		string _fin;

	public:
		Tratamiento () {}
		Tratamiento(string medicamento, int dosis, int frecuencia, string comienzo, string fin){
			_medicamento=medicamento;
			_dosis=dosis;
			_frecuencia=frecuencia;
			_comienzo=comienzo;
			_fin=fin;
		}

		string getMedicamento() const {
			return _medicamento;
		}

		int getDosis() const {
			return _dosis;
		}

		int getFrecuencia() const {
			return _frecuencia;
		}

		string getComienzo() const {
			return _comienzo;
		}

		string getFin() const {
			return _fin;
		}

		void setMedicamento(string medicamento){
			_medicamento=medicamento;
		}

		void setDosis(int dosis){
			_dosis=dosis;
		}

		void setFrecuencia(int frecuencia){
			_frecuencia=frecuencia;
		}

		void setComienzo(string comienzo){
			_comienzo=comienzo;
		}

		void setFin(string fin){
			_fin=fin;
		}
};

#endif
