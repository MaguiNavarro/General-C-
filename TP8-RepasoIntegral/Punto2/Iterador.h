#ifndef ITERADOR_H_
#define ITERADOR_H_
#include "Contenedor.h"
using namespace std;



template <typename T>
class Iterador
{
  protected:
  const Contenedor<T>& contenedor;
  int posicionActual;  
public:
      Iterador (const Contenedor<T>& c): contenedor(c), posicionActual(0){}
     // Métodos puramente virtuales (abstractos)
    virtual bool hayMasElementos() const = 0;
    virtual T elementoActual() const = 0;
    virtual void avanzar() = 0;

    // Destructor virtual
    virtual ~Iterador() {}

};




#endif // ITERADOR_H_


