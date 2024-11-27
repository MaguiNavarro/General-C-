#ifndef ITERADORPAR_H_
#define ITERADORPAR_H_
#include <iostream>
#include "Contenedor.h"
#include "Iterador.h"
using namespace std;



class IteradorPar : public Iterador {
public:
    IteradorPar(const Contenedor& c) : Iterador(c) {
        if (contenedor.capacidad() > 0 && posicionActual % 2 != 0) {
            ++posicionActual;
        }
    }

    bool hayMasElementos() const override {
        return posicionActual < contenedor.capacidad();
    }

    int elementoActual() const override {
        if (posicionActual >= 0 && posicionActual < contenedor.capacidad()) {
            return contenedor.elemento(posicionActual);
        }
        return -1;
    }

    void avanzar() override {
        posicionActual += 2;
    }
};



 






#endif /* ITERADORPAR_H_ */