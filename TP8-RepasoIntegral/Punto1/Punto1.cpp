#include <sstream>
#include "IteradorInverso.h"
#include "IteradorPar.h"
#include "Contenedor.h"

template <typename Iterador>
void mostrarContenido(const Contenedor& contenedor, Iterador& iterador) { //ES UNA FUNCION EXTERNA(Funcion generica)
    // Recorrer y mostrar los elementos utilizando el iterador proporcionado
    while (iterador.hayMasElementos()) {
        cout << iterador.elementoActual() << " ";
        iterador.avanzar(); // Mueve el iterador a la siguiente posición
    }
    cout << endl; 
}
int main() {
    // Crear un contenedor con capacidad 5 y valor indefinido de -1
    Contenedor cont(5, -1);
    cont.insertarElemento(10, 0);
    cont.insertarElemento(20, 1);
    cont.insertarElemento(30, 2);
    cont.insertarElemento(40, 3);
    cont.insertarElemento(50, 4);

  
    IteradorInverso itInv(cont);

    cout << "Contenido usando IteradorInverso:" << endl;
    mostrarContenido(cont, itInv);


    IteradorPar itPar(cont);

    // Llamar a la función para mostrar el contenido con el iterador par
    cout << "Contenido usando IteradorPar:" << endl;
    mostrarContenido(cont, itPar);

    return 0;
}