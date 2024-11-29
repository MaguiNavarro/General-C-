#ifndef CONTROL_H_
#define CONTROL_H_

#include <iostream>
#include "Fecha.h"
using namespace std;

class Control
{
private:
    string descripcion;
    double monto;
    Fecha fechaControl;
    Fecha fechaProximoControl;

public:
    Control(string desc, double monto, Fecha control, Fecha prox);
    double getMonto() const;
    Fecha getProxControl() const;
    Fecha getFechaControl() const;
    string getDescripcion() const;
    void escribirInfo() const;

    ~Control();
};

Control::Control(string desc, double precio, Fecha control, Fecha prox)
{
    this->descripcion = desc;
    this->monto = precio;
    this->fechaControl = control;
    this->fechaProximoControl = prox;
}
double Control::getMonto() const
{
    return this->monto;
}
Fecha Control::getProxControl() const
{
    return this->fechaProximoControl;
}
Fecha Control::getFechaControl() const
{
    return this->fechaControl;
}
string Control::getDescripcion() const
{
    return this->descripcion;
}
void Control::escribirInfo() const
{
    cout << "\n Fecha Control: " << this->fechaControl
         << "\n Descripción: " << this->descripcion
         << "\n Monto: $" << this->monto
         << "\n Fecha Próximo Control: " << this->fechaProximoControl << endl;
}
Control::~Control()
{
}

#endif /* CONTROL_H_ */