#ifndef ITERADORINVERSO_H_
#define ITERADORINVERSO_H_
#include <iostream>
#include "Contenedor.h"
#include "Iterador.h"
using namespace std;

template <typename T>
class IteradorInverso : public Iterador<T> {
public:
    IteradorInverso(const Contenedor<T>& c) : Iterador<T>(c) {
        this->posicionActual  = c.capacidad() - 1;
    }

    bool hayMasElementos() const override {
        return this->posicionActual >= 0;
    }

    T elementoActual() const override {
        if (this->posicionActual  >= 0 && this->posicionActual < this->contenedor.capacidad()) {
            return this->contenedor.elemento(this->posicionActual );
        }
        return -1;
    }

    void avanzar() override {   //RETROCEDER SE LLAMARIA LA FN
       --this->posicionActual ;
    }
};

 


#endif /* ITERADORINVERSO_H_ */