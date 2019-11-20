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

    public:
        static FileIO* getInstance() {
            if (_instance == NULL) {
                _instance = new FileIO("pacientes.bin"); //Archivo de pacientes default
            }

            return _instance;
        }

        std::string getPath () {
            return _path;
        }
        void setPath (std::string path) {
            _path = path;
        }

        bool exists(std::string name); //Comprueba si existe un paciente específico
        Paciente getPaciente(std::string name); //Devuelve un paciente especifico
        std::list<Paciente> getTodosPacientes(); //Devuelve una lista con todos los pacientes
        std::list<Cita> getTodasCitas(); //Devuelve todas las citas
        std::list<Cita> getCitasHoy(); //Devuelve las citas para el día de hoy
        void guardarPaciente(Paciente p); //Guarda los datos de un paciente
        

};

#endif