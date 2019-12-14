#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <list>
#include "paciente.h"

class FileIO {
    private:
        static FileIO* _instance; //Singleton instance
        std::string _path;
        
        FileIO (std::string path) {
            _path = path;
        }

        std::list<Cita> getCitasPaciente (std::string dni);
        std::list<Tratamiento> getTratamientosPaciente (std::string dni);
        std::list<EntradaHistorial> getHistorialPaciente (std::string dni);

    public:
        static FileIO* getInstance();

        std::string getPath () const {
            return _path;
        }
        void setPath (std::string path) {
            _path = path;
        }

        int exists(std::string name); //Comprueba si existe un paciente específico, devuelve su posicion si lo encuentra, -1 si no, -2 si no consigue abrir el archivo
        Paciente getPaciente(std::string name); //Devuelve un paciente especifico
        std::list<Paciente> getTodosPacientes(); //Devuelve una lista con todos los pacientes
        std::list<Paciente> buscarPacientes(std::string name); //Busca todos los pacientes cuyo nombre coincida con el dado
        std::list<Cita> getTodasCitas(); //Devuelve todas las citas
        std::list<Cita> getCitasHoy(); //Devuelve las citas para el día de hoy
        void guardarPaciente(const Paciente &p); //Guarda los datos de un paciente

};

#endif