#ifndef HELPERS_H
#define HELPERS_H

#include "Cita.h"
#include "Tratamiento.h"
#include "EntradaHistorial.h"
#include "paciente.h"

#include <list>
#include <string>

enum Color {
    FG_BLACK   = 30,
    FG_RED     = 31,
    FG_GREEN   = 32,
    FG_YELLOW  = 33,
    FG_BLUE    = 34,
    FG_MAGENTA = 35,
    FG_CYAN    = 36,
    FG_WHITE   = 37,
    BG_BLACK   = 40,
    BG_RED     = 41,
    BG_GREEN   = 42,
    BG_YELLOW  = 43,
    BG_BLUE    = 44,
    BG_MAGENTA = 45,
    BG_CYAN    = 46,
    BG_WHITE   = 47
};

struct Selection {
    int index;
    std::string op;
};

static bool USE_COLORS = true;

bool crearPaciente(Paciente &p, bool modificar=false);
bool crearCita(Cita &c);
bool crearTratamiento(Tratamiento &t);
bool crearEntradaHistorial(EntradaHistorial &e);

void setColors(bool use);
void colorPrint(const std::string &str, int color, bool bold);
bool fechaValida (const std::string &str);
bool horaValida (const std::string &str);
int strGetHora(const std::string &str);
int strGetMinutos(const std::string &str);
bool solapanCitas(const Cita &c1, const Cita &c2);
bool isNumber(const std::string &str);
std::string lowerString(const std::string &str);

Paciente seleccionarPaciente();
Selection seleccionarCita(std::list<Cita> citas);
Selection seleccionarTratamiento(std::list<Tratamiento> tratamientos);

bool compFechas(const std::string &f1, const std::string &f2);
void printPacientes(std::list<Paciente> pacientes, int sel=-1);
void printCitas(std::list<Cita> citas, int sel=-1);
void printHistorial(std::list<EntradaHistorial> historial);
void printTratamientos(std::list<Tratamiento> tratamientos, int setl=-1);
void printPaciente(const Paciente &p);

#endif