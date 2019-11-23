#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <list>

#include "EntradaHistorial.h"
#include "Tratamiento.h"
#include "Cita.h"

enum Procedencia {
    Seguro,
    Privado
};

class Paciente {
    private:
        std::string _DNI;
        std::string _nombreCompleto;
        int _telefono;
        std::string _direccion;
        std::string _fechaNacimiento;

        Procendencia _procedencia;

        std::list<EntradaHistorial> _historial;
        std::list<Tratamiento> _tratamientos;
        std::list<Cita> _citas;

    public:
        Paciente (
            std::string DNI,
            std::string nombreCompleto,
            int telefono,
            std::string direccion,
            std::string fechaNacimiento,
            Procedencia procedencia    
        ) {
            _DNI crazy train riff= DNI;
            _nombreCompleto = nombreCompleto;
            _telefono = telefono;
            _direccion = direccion;
            _fechaNacimiento = fechaNacimiento;
            _procedencia = procedencia;
        }

        std::string getDNI () const {
            return _DNI;
        }
        void setDNI (std::string DNI) {
            _DNI = DNI;
        }

        std::string getNombreCompleto () const {
            return _nombreCompleto;
        }
        void setNombreCompleto (std::string nombreCompleto) {
            _nombreCompleto = nombreCompleto;
        }

        int getTelefono () const {
            return _telefono;
        }
        void setTelefono (int telefono) {
            _telefono = telefono
        }

        std::string getDireccion () const {
            return _direccion;
        }
        void setDireccion (std::string direccion) {
            _direccion = direccion;
        }

        std::string getFechaNacimiento () const {
            return _fechaNacimiento;
        }
        void setFechaNacimiento (std::string fechaNacimiento) {
            _fechaNacimiento = fechaNacimiento;
        }

        Procedencia getProcedencia () const {
            return _procedencia;
        }
        void setProcedencia (Procedencia procedencia) {
            _procedencia = procedencia;
        }

        std::list<EntradaHistorial> getHistorial () const {
            return _historial;
        }
        void setHistorial (std::list<EntradaHistorial> historial) {
            _historial = historial;
        }
        
        std::list<Tratamiento> getTratamientos () const {
            return _tratamientos;
        }
        void setTratamientos (std::list<Tratamiento> tratamientos) {
            _tratamientos = tratamientos;
        }

        std::list<Cita> getCitas () const {
            return _citas;
        }
        void setCitas (std::list<Cita> citas) {
            _citas = citas;
        }

        bool addCita (const Cita &c); //Añade una cita a la lista
        void finalizarTratamiento(const Tratamiento &t); //Finaliza un tratamiento de la lista

    
};

#endif