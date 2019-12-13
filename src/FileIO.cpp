#include "FileIO.h"
#include "paciente.h"
#include "Cita.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>

std::list<Cita> FileIO::getTodasCitas () {
    std::list<Cita> citas;

    std::ifstream file_pacientes(_path);
    if (file_pacientes) {
        while (!file_pacientes.eof()) {
            //Lee el dni del paciente
            std::string dni;
            file_pacientes >> dni;

            //Se salta el resto de campos del paciente
            for (int i = 0; i < 5; i++) {
                file_pacientes.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }

            std::list<Cita> citas_paciente = getCitasPaciente(dni); //Coge las citas del paciente leido
            citas.insert(citas.end(), citas_paciente.begin(), citas_paciente.end()); //Copia citas_paciente al final de citas

        }
        file_pacientes.close();
    }

    return citas;
}

std::list<Cita> FileIO::getCitasPaciente (std::string dni) {
    std::list<Cita> citas;

    std::ifstream file(dni + "_citas.txt");
    if (file) {
        while (!file.eof) {
            Cita c;
            std::string aux;

            file >> aux;
            c.setFecha(aux);

            file >> aux;
            c.setDuracion(std::stoi(aux));

            file >> aux;
            c.setHora(aux);

            citas.push_back(c);
        }
        file.close();
    }

    return citas;
}

std::list<Tratamiento> FileIO::getTratamientosPaciente (std::string dni) {
    std::list<Tratamiento> tratamientos;

    std::ifstream file(dni + "_tratamientos.txt");
    if (file) {
        while (!file.eof) {
            Tratamiento t;
            std::string aux;

            file >> aux;
            t.setMedicamento(aux);

            file >> aux;
            t.setDosis(std::stoi(aux));

            file >> aux;
            t.setFrecuencia(std::stoi(aux));
            
            file >> aux;
            t.setComienzo(aux);

            file >> aux;
            t.setFin(aux);

            tratamientos.push_back(t);
        }
        file.close();
    }

    return tratamientos;
}

std::list<EntradaHistorial> FileIO::getHistorialPaciente (std::string dni) {
    std::list<EntradaHistorial> historial;

    std::ifstream file(dni + "_citas.txt");
    if (file) {
        while (!file.eof) {
            EntradaHistorial e;
            std::string aux;

            file >> e.fecha;
            file >> e.sintomas;

            historial.push_back(e);
        }
        file.close();
    }

    return historial;
}

int FileIO::exists (std::string nombre) {
    std::ifstream file(_path, fstream::in | fstream::binary);
    if (file) {
        int count = 0;
        while (!file.eof) {
            std::string aux;
            file >> aux >> aux;

            file.ignore(std::numeric_limits<streamsize>::max(), '\n');

            if (aux == nombre) {
                file.close();
                return count;
            }
            count++;
        }

        file.close();
        return -1;
    }
    else {
        return -2;
    }
}

std::list<Paciente> FileIO::getTodosPacientes () {
    std::list<Paciente> pacientes;
    
    std::ifstream file(_path);
    if (file) {
        while (!file.eof) {
            Paciente p;
            std::string aux;

            file >> aux;
            p.setDNI(aux);

            file >> aux;
            p.setNombreCompleto(aux);

            file >> aux;
            p.setTelefono(std::stoi(aux));

            file >> aux;
            p.setDireccion(aux);

            file >> aux;
            p.setFechaNacimiento(aux);

            file >> aux;
            p.setProcedencia((Procedencia)std::stoi(aux));

            p.setCitas(getCitasPaciente(p.getDNI()));
            p.setTratamientos(getTratamientosPaciente(p.getDNI()));
            p.setHistorial(getHistorialPaciente(p.getDNI()));

            pacientes.push_back(p);
        }

        file.close();
    }

    return pacientes;
}

void FileIO::guardarPaciente (const Paciente &p) {
    int result = exists(p.getNombreCompleto());

    std::fstream file(_path, fstream::in | fstream::out);
    if (file) {
        if (result >= 0) {
            //Se desplaza a la posicion del paciente
            for (int i = 0; i < 6*result; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
        }
        else {
            //Añadir al final
            file.seekp(0, file.end);
        }

        file << p.getDNI()              << std::endl;
        file << p.getNombreCompleto()   << std::endl;
        file << p.getTelefono()         << std::endl;
        file << p.getDireccion()        << std::endl;
        file << p.getFechaNacimiento()  << std::endl;
        file << (int)p.getProcedencia() << std::endl;

        //TODO: Guardar las listas
        

        file.close();
    }
}