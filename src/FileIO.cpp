#include "FileIO.h"
#include "paciente.h"
#include "Cita.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>

struct RegCita {
    char fecha[10];
    int duracion;
    char hora[5];
};

struct RegPaciente {
    char dni[9];
    char nombreCompleto[100];
    int telefono;
    char direccion[200] ;
    char fechaNacimiento[10];
    int procedencia;
};

std::list<Cita> FileIO::getCitasPaciente (std::string dni) {
    std::list<Cita> citas;

    std::ifstream file(dni + ".bin", ios::binary);
    if (file) {
        RegCita reg;
        while (!file.eof) {
            file.read(reg.fecha, 10);
            file.read(reinterpret_cast<char*>(&reg.duracion), sizeof(reg.duracion));
            file.read(reg.hora, 5);

            Cita c(std::string(reg.fecha), reg.duracion, std::string(reg.hora));
            citas.push_back(c);
        }
        file.close();
    }

    return citas;
}

std::list<Tratamiento> FileIO::getTratamientosPaciente (std::string dni) {

}

std::list<EntradaHistorial> FileIO::getHistorialPaciente (std::string dni) {

}

int FileIO::exists (std::string nombre) {
    std::ifstream file(_path, fstream::in | fstream::binary);
    if (file) {
        int count = 0;
        RegPaciente reg;
        while (!file.eof) {
            file.read(reg.dni, 9);
            file.read(reg.nombreCompleto, 100);
            file.read(reinterpret_cast<char*>(&reg.telefono), sizeof(int));
            file.read(reg.direccion, 200);
            file.read(reg.fechaNacimiento, 10);
            file.read(reinterpret_cast<char*>(&reg.procedencia), sizeof(int));
        
            if (std::string(reg.nombreCompleto) == nombre) {
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
        RegPaciente reg;
        while (!file.eof) {
            file.read(reg.dni, 9);
            file.read(reg.nombreCompleto, 100);
            file.read(reinterpret_cast<char*>(&reg.telefono), sizeof(int));
            file.read(reg.direccion, 200);
            file.read(reg.fechaNacimiento, 10);
            file.read(reinterpret_cast<char*>(&reg.procedencia), sizeof(int));
        
            Paciente p(
                std::string(reg.dni),
                std::string(reg.nombreCompleto),
                reg.telefono,
                std::string(reg.direccion),
                std::string(reg.fechaNacimiento),
                (Procedencia)reg.procedencia
            );
            pacientes.push_back(p);
        }

        file.close();15 Dec 2019
    }

    return pacientes;
}

void FileIO::guardarPaciente (const Paciente &p) {
    std::fstream file(_path, fstream::in | fstream::out | fstream::app | fstream::binary);
    if (file) {
        int result = exists(p.getNombreCompleto());
        if (result > 0) {
            //Reemplazar paciente
            file.seekp(result * (sizeof(char)*319 + sizeof(int)*2), file.beg);
        }
        else {
            //Añadir al final{
            file.seekp(0, file.end);
        }

        RegPaciente reg;
        std::copy(p.getDNI().begin(), p.getDNI().end(), reg.dni);
        std::copy(p.getNombreCompleto().begin(), p.getNombreCompleto().end(), reg.nombreCompleto);
        std::copy(p.getDireccion().begin(), p.getDireccion().end(), reg.direccion);
        std::copy(p.getFechaNacimiento().begin(), p.getFechaNacimiento().end(), reg.fechaNacimiento);
        reg.telefono = p.getTelefono();
        reg.procedencia = p.getProcedencia();


        file.write(reg.dni, 9);
        file.write(reg.nombreCompleto, 100);
        file.write(reinterpret_cast<char*>(&reg.telefono), sizeof(reg.telefono));
        file.write(reg.direccion, 200);
        file.write(reg.fechaNacimiento, 10);

        file.close();
    }
}