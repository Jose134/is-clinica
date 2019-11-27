#include "FileIO.h"
#include "paciente.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>

bool FileIO::exists (std::string nombre) {
    std::ifstream file(_path, fstream::in | fstream::binary);
    if (file) {
        Paciente p("", "", 0, "", "", 0);
        file.read()
    }
    else {
        return false;
    }
}

std::list<Paciente> FileIO::getTodosPacientes () {
    std::list<Paciente> pacientes;
    
    std::ifstream();
    if (file) {
        while (!file.eof) {
            Paciente p;
            int stringReadLength;
            std::string stringRead;

            char buffer[10];
            file.read(buffer, 10);
            p.setDNI(std::string(buffer));

            file.read(reinterpret_cast<char*>(&stringReadLength), sizeof(stringReadLength));
            
            file.read(stringRead.c_str(), stringReadLength);
            p.setNombreCompleto(stringRead);
            stringRead.clear();

            int telefono;
            file.read(reinterpret_cast<char*>(&telefono), sizeof(telefono));
            p.setTelefono(telefono);

            file.read(reinterpret_cast<char*>(&stringReadLength), sizeof(stringReadLength));
            
            file.read(stringRead.c_str(), stringReadLength);
            p.setDireccion(stringRead);
            stringRead.clear();

            file.read(reinterpret_cast<char*>(&stringReadLength), sizeof(stringReadLength));
            
            file.read(stringRead.c_str(), stringReadLength);
            p.setFechaNacimiento(stringRead.c_str(), stringReadLength);
            stringRead.clear();

            int procedencia;
            file.read(reinterpret_cast<char*>(&procedencia), sizeof(procedencia));
            p.setProcedencia(procedencia);

            pacientes.push_back(p);
        }

        file.close();
    }

    return pacientes;
}

void FileIO::guardarPaciente (const Paciente &p) {
    std::fstream file(_path, fstream::in | fstream::out | fstream::app | fstream::binary);
    if (file) {
        if (exists(p.getNombre())) {
            //Reemplazar paciente

        }
        else {
            //Añadir al final
            if (file) {
                file.seekp(0, file.end);
            }


        }

        int strSize;

        file.write(p.getDNI().c_str(), 10);

        strSize = p.getNombreCompleto().size();
        file.write(reinterpret_cast<char*>(&strSize), sizeof(strSize));
        file.write(p.getNombreCompleto.c_str(), strSize);

        int telefono;
        file.read(reinterpret_cast<char*>(&telefono), sizeof(telefono));
        p.setTelefono(telefono);

        strSize = p.getDireccion().size();
        file.write(reinterpret_cast<char*>(&strSize), sizeof(strSize));
        file.write(p.getDireccion().c_str(), strSize);

        strSize = p.getFechaNacimiento().size();
        file.write(reinterpret_cast<char*>(&strSize), sizeof(strSize));
        file.write(p.getFechaNacimiento().c_str(), strSize);

        int procedencia = p.getProcedencia();
        file.write(reinterpret_cast<char*>(&procedencia), sizeof(procendencia));

        file.close();
    }
}