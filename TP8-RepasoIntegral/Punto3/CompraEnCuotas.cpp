#include "CompraEnCuotas.h"

CompraEnCuotas::CompraEnCuotas(int cod, Fecha fecha, const vector<Producto *> productos, int cuotas)
    : Compra(cod, fecha, productos), cantCuotas(cuotas) {}

double CompraEnCuotas::calcularMonto() const
{
    double total = 0;
    for (Producto *producto : productos)
    {
        total += producto->getPrecio();
    }
    if (cantCuotas == 3)
    {
        total += total * interes3Cuotas;
    }
    else
    {
        total += total * interes6Cuotas;
    }

    return total;
}
int CompraEnCuotas::getCuotas() const { return cantCuotas; }

void CompraEnCuotas::escribirInfo()
{
    Compra::escribirInfo();
}
CompraEnCuotas::~CompraEnCuotas()
{
}