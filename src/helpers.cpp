#include "helpers.h"
#include <string>
#include <iostream>

#include <list>

#include "paciente.h"

//Prints colored text
void colorPrint (const std::string &str, int color, bool bold) {
    std::cout << "\033[" << (bold ? "1" : "0") << ";" << color << "m" << str << "\033[0m";
}

//Extrae la hora de una string con formato HH:MM
int strGetHora (const std::string &str) {
    std::string hora = str.substr(0, 2);
    return std::stoi(hora);
}

//Extrae los minutos de una string con formato HH:MM
int strGetMinutos (const std::string &str) {
    std::string minuto = str.substr(3, 2);
    return std::stoi(minuto);
}

bool solapanCitas (const Cita &c1, const Cita &c2) {
    if (c1.getFecha() == c2.getFecha()) {
        if (c1.getHora() == c2.getHora()) {
            return true;
        }
        else {
            int hora1 = strGetHora(c1.getHora());
            int minuto1 = strGetMinutos(c1.getHora());
            minuto1 += c1.getDuracion();
            hora1 += minuto1 / 60;
            minuto1 %= 60;

            int hora2 = strGetHora(c2.getHora());
            int minuto2 = strGetMinutos(c2.getHora());

            if (hora1 > hora2) {
                return true;
            }
            else if (hora1 == hora2) {
                if (minuto1 > minuto2) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }
}

void printPacientes (std::list<Paciente> pacientes) {
    
    int longest = 0;
    for (Paciente &p : pacientes) {
        int size = p.getNombreCompleto().size();
        if (size > longest) {
            longest = size;
        }
    }

    std::cout << "Nombre";
    for (int i = 0; i < longest - 4; i++) {
        std::cout << " ";
    }
    std::cout << "Telefono" << std::endl;
    
    for (int i = 0; i < longest+13; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (Paciente &p : pacientes) {
        std::string line;
        line += p.getNombreCompleto();

        int spaces = longest-line.size() + 2;
        for (int i = 0; i < spaces; i++) {
            line += " ";
        }
        line += std::to_string(p.getTelefono());

        colorPrint(line, Color::FG_MAGENTA, false);
        std::cout << std::endl;
    }
}