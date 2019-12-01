#include "paciente.h"

void Paciente::addCita (const Cita &c) {
    _citas.push_back(c);
}

void Paciente::addTratamiento (const Tratamiento &t) {
    _tratamientos.push_back(t);
}

void Paciente::addHistorial (const EntradaHistorial &h) {
    _historial.push_back(h);
}