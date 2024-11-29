#ifndef MASCOTA_H_
#define MASCOTA_H_

#include <iostream>
#include <vector>
#include "Control.h"

class Mascota
{
protected:
    string Nombre;
    string Raza;
    Fecha fechaNacimiento;
    vector<Control *> controles;

public:
    Mascota(string nombre, string raza, Fecha fechaNac);
    void registrarControl(string desc, double monto, Fecha proxControl, Fecha control);
    double calcularMontoMes(int mes, int anio) const;
    virtual double calcularMontoControl(Control *control) const;
    bool tieneControlProximo() const;
    virtual void mostrarInfo() const;
    virtual ~Mascota();
};

Mascota::Mascota(string nombre, string raza, Fecha fechaNac)
{
    this->Nombre = nombre;
    this->Raza = raza;
    this->fechaNacimiento = fechaNac;
}
void Mascota::registrarControl(string desc, double monto, Fecha proxControl, Fecha Fcontrol)
{
    Control *control = new Control(desc, monto, Fcontrol, proxControl);
    controles.push_back(control);
}

double Mascota::calcularMontoMes(int mes, int anio) const
{
    double total = 0;
    for (Control *control : controles)
    {

        if (control->getFechaControl().getMes() == mes && control->getFechaControl().getAnio() == anio)
        {
            total += calcularMontoControl(control);
        }
    }
    return total;
}

double Mascota::calcularMontoControl(Control *control) const
{
    return control->getMonto();
}

bool Mascota::tieneControlProximo() const
{

    for (Control *control : controles)
    {

        if (control->getProxControl().getDia() >= 0 && control->getProxControl().getDia() < 5)
        {
            return true;
        }
    }
    return false;
}
void Mascota::mostrarInfo() const
{
    cout << "\nNombre: " << this->Nombre << "\nRaza: " << this->Raza << "\nFecha Nacimiento: " << this->fechaNacimiento << endl;
    cout << "Historial de controles para " << this->Nombre << ":\n";
    for (Control *control : controles)
    {
        control->escribirInfo();
    }
}

Mascota::~Mascota()
{
    for (Control *control : controles)
    {
        delete control;
    }
    controles.clear();
}

#endif /* MASCOTA_H_ */