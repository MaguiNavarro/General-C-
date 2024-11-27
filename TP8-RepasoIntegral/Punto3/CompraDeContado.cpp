#include "CompraDeContado.h"

CompraDeContado::CompraDeContado(int cod, Fecha fecha, const vector<Producto*> productos)
    : Compra(cod, fecha, productos) {}

double CompraDeContado::calcularMonto() const
{
    double total = 0;
    for (Producto *producto : productos)
    {
        total += producto->getPrecio();
    }
    return total += total * ( descuento ); // Aplica descuento
}

void CompraDeContado::escribirInfo()
{
    Compra::escribirInfo();
}

CompraDeContado::~CompraDeContado()
{
}