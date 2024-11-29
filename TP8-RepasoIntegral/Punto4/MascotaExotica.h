#ifndef MASCOTAEXOTICA_H_
#define MASCOTAEXOTICA_H_

#include <iostream>
#include <vector>
#include "Mascota.h"

class MascotaExotica : public Mascota
{
private:
    string descripcion;

public:
    MascotaExotica(string nombre, string raza, Fecha fechaNac, string desc);
    double calcularMontoControl(Control *control) const override;
    void mostrarInfo() const override;
    ~MascotaExotica();
};

MascotaExotica::MascotaExotica(string nombre, string raza, Fecha fechaNac, string desc)
    : Mascota(nombre, raza, fechaNac), descripcion(desc)
{
}
double MascotaExotica::calcularMontoControl(Control *control) const
{
    double total= control->getMonto() * 1.10;
    return total; // Incremento del 10%
}

void MascotaExotica::mostrarInfo() const
{
    Mascota::mostrarInfo();
    cout << "Descripcion: " << this->descripcion << endl;
}
MascotaExotica::~MascotaExotica()
{
}

#endif /* MASCOTAEXOTICA_H_ */