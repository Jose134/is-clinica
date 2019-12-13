#ifndef HELPERS_H
#define HELPERS_H

#include "Cita.h"

int strGetHora(const std::string &str);
int strGetMinutos(const std::string &str);
bool solapanCitas(const Cita &c1, const Cita &c2);

#endif