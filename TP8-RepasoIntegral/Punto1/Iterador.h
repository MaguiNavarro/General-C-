#ifndef ITERADOR_H_
#define ITERADOR_H_
using namespace std;

class Contenedor;

class Iterador
{
  protected:

  const Contenedor& contenedor;
  int posicionActual;  
public:
      Iterador (const Contenedor& c): contenedor(c), posicionActual(0){}
     // Métodos puramente virtuales (abstractos)
    virtual bool hayMasElementos() const = 0;
    virtual int elementoActual() const = 0;
    virtual void avanzar() = 0;

    // Destructor virtual
    virtual ~Iterador() {}

};




#endif // ITERADOR_H_


