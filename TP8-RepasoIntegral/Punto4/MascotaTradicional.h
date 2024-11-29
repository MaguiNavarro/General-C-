#ifndef MASCOTATRADICIONAL_H_
#define MASCOTATRADICIONAL_H_

#include <iostream>
#include <vector>
#include "Mascota.h"
class MascotaTradicional : public Mascota
{

public:
    MascotaTradicional(string nombre, string raza, Fecha fechaNac);
    ~MascotaTradicional();
};

MascotaTradicional::MascotaTradicional(string nombre, string raza, Fecha fechaNac)
    : Mascota(nombre, raza, fechaNac) {}

MascotaTradicional::~MascotaTradicional()
{
}

#endif /* MASCOTATRADICIONAL_H_ */