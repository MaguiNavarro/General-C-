#ifndef COMPRADECONTADO_H_
#define COMPRADECONTADO_H_

#include <iostream>
#include <vector>
#include "Compra.h"
class CompraDeContado : public Compra
{
private:
  const  double descuento= 1.5;

public:
    CompraDeContado(int cod, Fecha fecha, const vector<Producto *> productos);
    double calcularMonto() const override;
    void escribirInfo() override;
    ~CompraDeContado();
};


#endif /* COMPRADECONTADO_H_ */
