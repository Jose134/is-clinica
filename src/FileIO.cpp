#include "FileIO.h"
#include "paciente.h"
#include "Cita.h"
#include "helpers.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <limits>
#include <ctime>

FileIO* FileIO::_instance = NULL;

FileIO* FileIO::getInstance () {
    if (_instance == NULL) {
        _instance = new FileIO("pacientes.txt"); //Archivo de pacientes default
    }

    return _instance;
}

std::list<Cita> FileIO::getTodasCitas () {
    std::list<Cita> citas;

    std::ifstream file_pacientes(_path);
    if (file_pacientes) {
        while (!file_pacientes.eof()) {
            //Checks if file is empty
            if (file_pacientes.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            //Lee el dni del paciente
            std::string dni;
            getline(file_pacientes, dni);

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

std::list<Cita> FileIO::getCitasHoy () {
    std::list<Cita> citas;

    std::string hoy = getFechaHoy();

    std::list<Cita> todas = FileIO::getInstance()->getTodasCitas();
    for (Cita &c : todas) {
        if (c.getFecha() == hoy) {
            citas.push_back(c);
        }
    }

    return citas;
}

std::list<Cita> FileIO::getCitasPaciente (std::string dni) {
    std::list<Cita> citas;

    std::ifstream file(dni + "_citas.txt");
    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            Cita c;
            std::string aux;

            getline(file, aux);
            c.setFecha(aux);

            getline(file, aux);
            c.setDuracion(std::stoi(aux));

            getline(file, aux);
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
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            Tratamiento t;
            std::string aux;

            getline(file, aux);
            t.setMedicamento(aux);

            getline(file, aux);
            t.setDosis(std::stoi(aux));

            getline(file, aux);
            t.setFrecuencia(std::stoi(aux));
            
            getline(file, aux);
            t.setComienzo(aux);

            getline(file, aux);
            t.setFin(aux);

            tratamientos.push_back(t);
        }
        file.close();
    }

    return tratamientos;
}

std::list<EntradaHistorial> FileIO::getHistorialPaciente (std::string dni) {
    std::list<EntradaHistorial> historial;

    std::ifstream file(dni + "_historial.txt");
    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            EntradaHistorial e;
            std::string aux;

            getline(file, e.fecha);
            getline(file, e.sintomas);

            historial.push_back(e);
        }
        file.close();
    }

    return historial;
}

int FileIO::exists (std::string dni) {
    std::ifstream file(_path);
    if (file) {
        int count = 0;
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            
            std::string aux;
            file >> aux;

            if (aux == dni) {
                file.close();
                return count;
            }

            for (int i = 0; i < 5; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            
            count++;

            file.get();
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
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            Paciente p;
            std::string aux;

            getline(file, aux);
            p.setDNI(aux);

            getline(file, aux);
            p.setNombreCompleto(aux);

            getline(file, aux);
            p.setTelefono(std::stoi(aux));

            getline(file, aux);
            p.setDireccion(aux);

            getline(file, aux);
            p.setFechaNacimiento(aux);

            getline(file, aux);
            p.setProcedencia((Procedencia)std::stoi(aux));

            p.setCitas(getCitasPaciente(p.getDNI()));
            p.setTratamientos(getTratamientosPaciente(p.getDNI()));
            p.setHistorial(getHistorialPaciente(p.getDNI()));

            pacientes.push_back(p);
        }

        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }

    return pacientes;
}

std::list<Paciente> FileIO::buscarPacientes (std::string nombre) {
    std::ifstream file(_path);
    std::list<Paciente> pacientes;

    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            Paciente p;
            std::string aux;

            getline(file, aux);
            p.setDNI(aux);

            getline(file, aux);
            p.setNombreCompleto(aux);
            
            //Checks if aux contains name
            if (aux.find(nombre) != std::string::npos) {

                getline(file, aux);
                p.setTelefono(std::stoi(aux));

                getline(file, aux);
                p.setDireccion(aux);

                getline(file, aux);
                p.setFechaNacimiento(aux);

                getline(file, aux);
                p.setProcedencia((Procedencia)std::stoi(aux));

                p.setCitas(getCitasPaciente(p.getDNI()));
                p.setTratamientos(getTratamientosPaciente(p.getDNI()));
                p.setHistorial(getHistorialPaciente(p.getDNI()));

                pacientes.push_back(p);
            }
            else {
                for (int i = 0; i < 4; i++) {
                    file.ignore(std::numeric_limits<streamsize>::max(), '\n');
                }
            }
            
        }

        file.close();
    }

    return pacientes;
}

void FileIO::borrarPaciente (const Paciente &p) {
    remove((p.getDNI() + "_citas.txt").c_str());
    remove((p.getDNI() + "_tratamientos.txt").c_str());
    remove((p.getDNI() + "_historial.txt").c_str());

    std::list<Paciente> pacientes = getInstance()->getTodosPacientes();
    std::ofstream file(_path);
    if (file) {
        for (Paciente &paciente : pacientes) {
            if (paciente.getDNI() != p.getDNI()) {
                file << paciente.getDNI()              << std::endl;
                file << paciente.getNombreCompleto()   << std::endl;
                file << paciente.getTelefono()         << std::endl;
                file << paciente.getDireccion()        << std::endl;
                file << paciente.getFechaNacimiento()  << std::endl;
                file << (int)paciente.getProcedencia() << std::endl;
            }
        }

        file.close();
    }
}

void FileIO::guardarPaciente (const Paciente &p) {
    int result = exists(p.getDNI());
    if (result >= 0) {
        std::list<Paciente> pacientes = getInstance()->getTodosPacientes();
        std::ofstream file(_path);
        if (file) {
            for (Paciente &paciente : pacientes) {
                if (paciente.getDNI() == p.getDNI()) {
                    paciente = p;
                }

                file << paciente.getDNI()              << std::endl;
                file << paciente.getNombreCompleto()   << std::endl;
                file << paciente.getTelefono()         << std::endl;
                file << paciente.getDireccion()        << std::endl;
                file << paciente.getFechaNacimiento()  << std::endl;
                file << (int)paciente.getProcedencia() << std::endl;

                //Guarda las listas del paciente
                std::ofstream listFile;

                listFile.open(paciente.getDNI() + "_citas.txt");
                for (Cita &c : paciente.getCitas()) {
                    listFile << c.getFecha()    << std::endl;
                    listFile << c.getDuracion() << std::endl;
                    listFile << c.getHora()     << std::endl;
                }
                listFile.close();

                listFile.open(paciente.getDNI() + "_tratamientos.txt");
                for (Tratamiento &t : paciente.getTratamientos()) {
                    listFile << t.getMedicamento() << std::endl;
                    listFile << t.getDosis()       << std::endl;
                    listFile << t.getFrecuencia()  << std::endl;
                    listFile << t.getComienzo()    << std::endl;
                    listFile << t.getFin()         << std::endl;
                }
                listFile.close();

                listFile.open(paciente.getDNI() + "_historial.txt");
                for (EntradaHistorial &e : paciente.getHistorial()) {
                    listFile << e.fecha    << std::endl;
                    listFile << e.sintomas << std::endl;
                }
                listFile.close();
            }
            file.close();
        }
    }
    else {
        std::fstream file(_path, fstream::out | fstream::app);
        if (file) {
            file << p.getDNI()              << std::endl;
            file << p.getNombreCompleto()   << std::endl;
            file << p.getTelefono()         << std::endl;
            file << p.getDireccion()        << std::endl;
            file << p.getFechaNacimiento()  << std::endl;
            file << (int)p.getProcedencia() << std::endl;

            //Guarda las listas del paciente
            std::ofstream listFile;

            listFile.open(p.getDNI() + "_citas.txt");
            for (Cita &c : p.getCitas()) {
                listFile << c.getFecha()    << std::endl;
                listFile << c.getDuracion() << std::endl;
                listFile << c.getHora()     << std::endl;
            }
            listFile.close();

            listFile.open(p.getDNI() + "_tratamientos.txt");
            for (Tratamiento &t : p.getTratamientos()) {
                listFile << t.getMedicamento() << std::endl;
                listFile << t.getDosis()       << std::endl;
                listFile << t.getFrecuencia()  << std::endl;
                listFile << t.getComienzo()    << std::endl;
                listFile << t.getFin()         << std::endl;
            }
            listFile.close();

            listFile.open(p.getDNI() + "_historial.txt");
            for (EntradaHistorial &e : p.getHistorial()) {
                listFile << e.fecha    << std::endl;
                listFile << e.sintomas << std::endl;
            }
            listFile.close();
            

            file.close();
        }
    }
}