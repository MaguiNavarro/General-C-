#ifndef ITERADORINVERSO_H_
#define ITERADORINVERSO_H_
#include <iostream>
#include "Contenedor.h"
#include "Iterador.h"
using namespace std;

class IteradorInverso : public Iterador {
public:
    IteradorInverso(const Contenedor& c) : Iterador(c) {
        posicionActual = c.capacidad() - 1;
    }

    bool hayMasElementos() const override {
        return posicionActual >= 0;
    }

    int elementoActual() const override {
        if (posicionActual >= 0 && posicionActual < contenedor.capacidad()) {
            return contenedor.elemento(posicionActual);
        }
        return -1;
    }

    void avanzar() override {
        --posicionActual;
    }
};

 


#endif /* ITERADORINVERSO_H_ */