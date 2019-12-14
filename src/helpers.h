#ifndef HELPERS_H
#define HELPERS_H

#include "Cita.h"
#include "paciente.h"

#include <list>

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

void colorPrint (const std::string &str, int color, bool bold);
int strGetHora(const std::string &str);
int strGetMinutos(const std::string &str);
bool solapanCitas(const Cita &c1, const Cita &c2);

void printPacientes (std::list<Paciente> pacientes);

#endif