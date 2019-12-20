/* helpers.cpp
 *
 * Contiene la implementacion de funciones auxiliares que no pertenecen a ninguna clase 
 * 
 */

#include "helpers.h"
#include <string>
#include <iostream>
#include <cctype>

#include <list>

#include "paciente.h"
#include "Cita.h"
#include "Tratamiento.h"
#include "EntradaHistorial.h"
#include "FileIO.h"

bool crearCita(Cita &c) {
    Cita cAux;
    std::string aux;

    //Fecha
    std::cout << "Introduzca la fecha de la cita (DD/MM/YYYY):" << std::endl;
    std::cin >> aux;

    if (!fechaValida(aux)) {
        colorPrint("ERROR: Fecha no valida\n", Color::FG_RED, true);
        return false;
    }
    cAux.setFecha(aux);

    //Duracion
    std::cout << "Introduzca la duracion de la cita (en minutos):" << std::endl;
    int d;
    std::cin >> d;

    if (d <= 0) {
        colorPrint("ERROR: Duracion no valida\n", Color::FG_RED, true);
        return false;
    }
    cAux.setDuracion(d);

    //Hora
    std::cout << "Introduzca la hora de la cita (HH:MM):" << std::endl;
    std::cin >> aux;

    if (!horaValida(aux)) {
        colorPrint("ERROR: Hora no valida\n", Color::FG_RED, true);
    }
    cAux.setHora(aux);

    //Comprueba si la cita solapa con otra
    std::list<Cita> citas = FileIO::getInstance()->getTodasCitas();
    for (Cita &cita : citas) {
        if (solapanCitas(cAux, cita)) {
            colorPrint("ERROR: La cita solapa con otra\n", Color::FG_RED, true);
            return false;
        }
    }
    
    c = cAux;
    return true;
}

bool crearTratamiento(Tratamiento &t) {
    Tratamiento tAux;
    std::string aux;

    //Medicamento
    std::cout << "Introduzca el medicamento:" << std::endl;
    std::cin >> aux;
    tAux.setMedicamento(aux);

    //Dosis
    std::cout << "Introduzca la dosis (en mg): "<<std::endl;
    int dosis;
    std::cin >> dosis;

    if (dosis <= 0) {
        colorPrint("ERROR: Dosis no valida\n", Color::FG_RED, true);
        return false;
    }

    tAux.setDosis(dosis);

    //Frecuencia
    std::cout << "Introduzca la frecuencia con la que el paciente debe tomar el medicamento: " << std::endl;
    int frecuencia;
    std::cin >> frecuencia;

    if (frecuencia <= 0) {
        colorPrint("ERROR: Frecuencia no valida\n", Color::FG_RED, true);
        return false;        
    }
    tAux.setFrecuencia(frecuencia);

    //Fecha comienzo
    std::cout<<"Introduzca el comienzo del tratamiento:"<<std::endl;
    std::cin >> aux;

    if (!fechaValida(aux)) {
        colorPrint("ERROR: Fecha no valida\n", Color::FG_RED, true);
        return false;
    }
    tAux.setComienzo(aux);

    //Fecha fin
    std::cout<<"Introduzca el fin del tratamiento:"<<std::endl;
    std::cin >> aux;

    if (!fechaValida(aux)) {
        colorPrint("ERROR: Fecha no valida\n", Color::FG_RED, true);
        return false;
    }
    tAux.setFin(aux);

    t = tAux;
    return true;
}

bool crearEntradaHistorial(EntradaHistorial &e) {
    EntradaHistorial aux;

    std::cout << "Introduzca la fecha (DD/MM/YYYY):" << std::endl;
    std::cin >> aux.fecha;

    if (!fechaValida(aux.fecha)) {
        colorPrint("ERROR: Fecha no valida\n", Color::FG_RED, true);
        return false;
    }

    std::cout << "Introduzca los sintomas:" << std::endl;
    std::cin >> aux.sintomas;

    e = aux;
    return true;
}

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

//Comprueba que la fecha este en el formato DD/MM/YYYY y sea valida
bool fechaValida (const std::string &str) {
    if (str.size() == 10) {
        //Comprueba el formato
        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) {
                if (str[i] != '/') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba el mes
        int m = std::stoi(str.substr(3, 2));
        if (m < 1 || m > 12) {
            return false;
        }

        //Comprueba el dia en funcion del mes
        int d = std::stoi(str.substr(0, 2));
        if (d < 1) { return false; }

        switch (m) {
            case  1: return d <= 31;
            case  2: return d <= 28;
            case  3: return d <= 31;
            case  4: return d <= 30;
            case  5: return d <= 31;
            case  6: return d <= 30;
            case  7: return d <= 31;
            case  8: return d <= 31;
            case  9: return d <= 30;
            case 10: return d <= 31;
            case 11: return d <= 30;
            case 12: return d <= 31;
        }
    }
    else {
        return false;
    }

    return true;
}

//Comprueba que la hora este en el formato HH:MM y sea valida
bool horaValida (const std::string &str) {
    if (str.size() == 5) {
        //Comprueba el formato
        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                if (str[i] != ':') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba que la hora sea valida
        int h = strGetHora(str);
        if (h < 0 || h > 23) {
            return false;
        }

        //Comprueba que los minutos sean validos
        int m = strGetMinutos(str);
        if (m < 0 || m > 59) {
            return false;
        }
    }
    else {
        return false;        
    }

    return true;
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

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool isNumber (const std::string &str)
{
    auto it = str.begin();
    if (*it == '-') { it++; } //Detects if number is negative
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

std::string lowerString (const std::string &str) {
    std::string result(str);
    for (auto it = result.begin(); it != result.end(); it++) {
        *it = std::tolower(*it);
    }
    return result;
}

Paciente seleccionarPaciente () {
    std::list<Paciente> pacientes = FileIO::getInstance()->getTodosPacientes();
    int sel = 0;
    std::cout << "Seleccionar Paciente" << std::endl;

    std::string input;
    bool exit = false;
    while (!exit) {
        system("clear");     
        printPacientes(pacientes, sel);

        std::cin >> input;
        if (isNumber(input)) {
            sel += std::stoi(input);
            if (sel < 0) { sel = 0; }
            if (sel > pacientes.size()-1) { sel = pacientes.size()-1; }            
        }
        else if (lowerString(input) == "quit") {
            sel = -1;
            exit = true;
        }
        else if (lowerString(input) == "select") {
            exit = true;
        }
        else {
            sel = 0;
            pacientes = FileIO::getInstance()->buscarPacientes(input);
        }

        
    }

    if (sel == -1) {
        Paciente p;
        p.setDNI("NULL");
        return p;
    }

    auto it = pacientes.begin();
    for (int i = 0; i < sel; i++) { it++; };
    return *it;
}

void printPacientes (std::list<Paciente> pacientes, int sel) {
    if (pacientes.size() == 0) {
        std::cout << "----------------------------------" << std::endl;
        colorPrint("No hay ningun paciente\n", Color::FG_WHITE, true);
    }
    
    int longest = 0;
    for (Paciente &p : pacientes) {
        int size = p.getNombreCompleto().size();
        if (size > longest) {
            longest = size;
        }
    }

    colorPrint("Nombre  ", Color::FG_CYAN, true);
    for (int i = 0; i < longest - 6; i++) {
        std::cout << " ";
    }
    colorPrint("Telefono\n", Color::FG_CYAN, true);
    
    int dashes = 0;
    if (longest == 0) { dashes = longest + 16; }
    else              { dashes = longest + 11; }

    for (int i = 0; i < dashes; i++) {
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

void printCitas (std::list<Cita> citas, int sel) {
    if (citas.size() == 0) {
        std::cout << "----------------------------------" << std::endl;
        colorPrint("No hay ninguna cita\n", Color::FG_WHITE, true);
    }

    std::list<Cita> sortedList = citas;
    sortedList.sort(compCitas);

    std::string currentDate = "";
    int count = 0;
    for (Cita &c : sortedList) {
        if (c.getFecha() != currentDate) {
            std::cout << std::endl;
            colorPrint("        " + c.getFecha() + "\n", Color::FG_CYAN, true);
            colorPrint("--------------------------\n", Color::FG_CYAN, true);

            currentDate = c.getFecha();
        }

        if (count == sel) {
            std::string text = c.getHora() + " | " + std::to_string(c.getDuracion()) + " minutos\n";
            colorPrint(text, Color::BG_CYAN, true);
        }
        else {
            std::cout << " " << c.getHora() << " | " << c.getDuracion() << " minutos" << std::endl; 
        }
        count++;
    }
}

void printHistorial (std::list<EntradaHistorial> historial) {
    std::cout << "----------------------------------" << std::endl;
    if (historial.size() == 0) {
        colorPrint("No hay ninguna entrada\n", Color::FG_WHITE, true);
    }

    for (EntradaHistorial &e : historial) {
        colorPrint("Fecha:    ", Color::FG_WHITE, true);
        colorPrint(e.fecha, Color::FG_WHITE, false);

        std::cout << std::endl;

        colorPrint("Sintomas: ", Color::FG_WHITE, true);
        colorPrint(e.sintomas, Color::FG_WHITE, false);

        std::cout << std::endl << "----------------------------------" << std::endl;
    }
}

void printTratamientos (std::list<Tratamiento> tratamientos) {
    std::cout << "----------------------------------" << std::endl;
    if (tratamientos.size() == 0) {
        colorPrint("No hay ningun tratamiento\n", Color::FG_WHITE, true);
    }

    for (Tratamiento &t : tratamientos) {
        colorPrint("Medicamento: ", Color::FG_WHITE, true);
        colorPrint(t.getMedicamento(), Color::FG_WHITE, false);

        std::cout << std::endl;

        colorPrint("Dosis:       ", Color::FG_WHITE, true);
        colorPrint(std::to_string(t.getDosis()), Color::FG_WHITE, false);

        std::cout << std::endl;

        colorPrint("Frecuencia:  ", Color::FG_WHITE, true);
        colorPrint(std::to_string(t.getFrecuencia()), Color::FG_WHITE, false);

        std::cout << std::endl;

        colorPrint("Comienzo:    ", Color::FG_WHITE, true);
        colorPrint(t.getComienzo(), Color::FG_WHITE, false);

        std::cout << std::endl;

        colorPrint("Fin:         ", Color::FG_WHITE, true);
        colorPrint(t.getFin(), Color::FG_WHITE, false);

        std::cout << std::endl << "----------------------------------" << std::endl;
    }
}

void printPaciente (const Paciente &p) {
    colorPrint("DNI:              ", Color::FG_WHITE, true);
    std::cout << p.getDNI() << std::endl;

    colorPrint("Nombre:           ", Color::FG_WHITE, true);
    std::cout << p.getNombreCompleto() << std::endl;

    colorPrint("Telefono:         ", Color::FG_WHITE, true);
    std::cout << p.getTelefono() << std::endl;

    colorPrint("Direccion:        ", Color::FG_WHITE, true);
    std::cout << p.getDireccion() << std::endl;

    colorPrint("Fecha Nacimiento: ", Color::FG_WHITE, true);
    std::cout << p.getFechaNacimiento() << std::endl;

    colorPrint("Procedencia:      ", Color::FG_WHITE, true);
    if (p.getProcedencia() == Procedencia::Privado) {
        std::cout << "Privado" << std::endl;
    }
    else if (p.getProcedencia() == Procedencia::Seguro) {
        std::cout << "Seguro" << std::endl;
    }
}