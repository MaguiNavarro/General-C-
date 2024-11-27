#ifndef ITERADORPAR_H_
#define ITERADORPAR_H_
#include <iostream>
#include "Contenedor.h"
#include "Iterador.h"
using namespace std;


template <typename T>
class IteradorPar : public Iterador<T> {
public:
    IteradorPar(const Contenedor<T>& c) : Iterador<T>(c) {
        if (this->contenedor.capacidad() > 0 && this->posicionActual  % 2 != 0) {
            ++this->posicionActual;
        }
    }

    bool hayMasElementos() const override {
        return this->posicionActual < this->contenedor.capacidad();
    }

    T elementoActual() const override {
        if (this->posicionActual  >= 0 && this->posicionActual < this->contenedor.capacidad()) {
            return this->contenedor.elemento(this->posicionActual);
        }
        return -1;
    }

    void avanzar() override {
        this->posicionActual  += 2;
    }
};



 






#endif /* ITERADORPAR_H_ */