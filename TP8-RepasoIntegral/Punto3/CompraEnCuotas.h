#ifndef COMPRAENCUOTAS_H_
#define COMPRAENCUOTAS_H_

#include <iostream>
#include <vector>
#include "Compra.h"

class CompraEnCuotas : public Compra
{
private:
    int cantCuotas;
    const double interes3Cuotas = 0.1;
    const double interes6Cuotas = 0.2;

public:
    CompraEnCuotas(int cod, Fecha fec, const vector<Producto *> productos, int cuotas);
    double calcularMonto() const override;
    int getCuotas() const;
    void escribirInfo()override;
    ~CompraEnCuotas();
};


#endif /* COMPRAENCUOTAS_H_ */