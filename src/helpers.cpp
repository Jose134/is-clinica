#include "helpers.h"
#include <string>
#include <iostream>

#include <list>

#include "paciente.h"

//Sets the USE_COLORS variable
void setColors (bool use) {
    USE_COLORS = use;
}

//Prints colored text
void colorPrint (const std::string &str, int color, bool bold) {
    if (USE_COLORS) {
        std::cout << "\033[" << (bold ? "1" : "0") << ";" << color << "m" << str << "\033[0m";
    }
    else {
        std::cout << str;
    }
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

int seleccionarPaciente (std::list<Paciente> pacientes) {
    int sel = 0;
    std::cout << "Seleccionar Paciente" << std::endl;

    char input = 0;
    bool exit = false;
    while (!exit) {
        system("clear");     
        printPacientes(pacientes, sel);

        std::cin >> input;
        if (input == 'w' || input == 'W') {
            sel = sel == 0 ? sel : sel-1;
        }
        else if (input == 's' || input == 'S') {
            sel = sel == pacientes.size()-1 ? sel : sel+1;
        }
        else if (input == 'e' || input == 'E') {
            exit = true;
        }
    }

    return sel;
}

void printPacientes (std::list<Paciente> pacientes, int sel) {
    
    int longest = 0;
    for (Paciente &p : pacientes) {
        int size = p.getNombreCompleto().size();
        if (size > longest) {
            longest = size;
        }
    }

    colorPrint("Nombre", Color::FG_CYAN, true);
    for (int i = 0; i < longest - 4; i++) {
        std::cout << " ";
    }
    colorPrint("Telefono\n", Color::FG_CYAN, true);
    
    for (int i = 0; i < longest+13; i++) {
        colorPrint("-", Color::FG_CYAN, true);
    }
    std::cout << std::endl;

    int count = 0;
    for (Paciente &p : pacientes) {
        std::string line;
        line += p.getNombreCompleto();

        int spaces = longest-line.size() + 2;
        for (int i = 0; i < spaces; i++) {
            line += " ";
        }
        line += std::to_string(p.getTelefono()) + "\n";

        if (count == sel) {
            colorPrint(line, Color::BG_CYAN, true);
        }
        else {
            colorPrint(line, Color::FG_WHITE, false);
        }
        count++;
    }
}

bool compCitas (const Cita &c1, const Cita &c2) {
    //Compara la fecha de ambas citas
    const std::string f1 = c1.getFecha();
    const std::string f2 = c2.getFecha();

    int y1 = std::stoi(f1.substr(6, 4));
    int y2 = std::stoi(f2.substr(6, 4));
    
    if (y1 == y2) {
        int m1 = std::stoi(f1.substr(3, 2));
        int m2 = std::stoi(f2.substr(3, 2));

        if (m1 == m2) {
            int d1 = std::stoi(f1.substr(0, 2));
            int d2 = std::stoi(f2.substr(0, 2));
        
            if (d1 == d2) {
                //Misma fecha, comprobar hora
                const std::string hora1 = c1.getHora();
                const std::string hora2 = c2.getHora();

                int h1 = std::stoi(hora1.substr(0, 2));
                int h2 = std::stoi(hora2.substr(0, 2));

                if (h1 == h2) {
                    int min1 = std::stoi(hora1.substr(3, 2));
                    int min2 = std::stoi(hora2.substr(3, 2));

                    return min1 < min2;
                }
                else {
                    return h1 < h2;
                }
            }
            else {
                return d1 < d2;
            }
        }
        else {
            return m1 < m2;
        }
    }
    else {
        return y1 < y2;
    }
}

void printCitas (std::list<Cita> citas) {
    std::list<Cita> sortedList = citas;
    sortedList.sort(compCitas);

    std::string currentDate = "";
    for (Cita &c : sortedList) {
        if (c.getFecha() != currentDate) {
            std::cout << std::endl;
            colorPrint("        " + c.getFecha() + "\n", Color::FG_CYAN, true);
            colorPrint("--------------------------\n", Color::FG_CYAN, true);

            currentDate = c.getFecha();
        }

        std::cout << " " << c.getHora() << " | " << c.getDuracion() << " minutos" << std::endl; 
    }
}