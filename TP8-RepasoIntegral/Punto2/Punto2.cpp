#include <iostream>
#include "IteradorInverso.h"
#include "IteradorPar.h"
#include "Contenedor.h"

using namespace std;

template <typename It>
void mostrarContenido(It& iterador) {
    while (iterador.hayMasElementos()) {
        std::cout << iterador.elementoActual() << " ";
        iterador.avanzar();
    }
    std::cout << std::endl;
}

int main() {
     // Contenedor de enteros
    Contenedor<int> contInt(10, -1);
    for (int i = 0; i < 10; ++i) {
        contInt.insertarElemento(i * 10, i);
    }

    // Contenedor de caracteres
    Contenedor<char> contChar(6, '-');
    contChar.insertarElemento('A', 0);
    contChar.insertarElemento('B', 1);
    contChar.insertarElemento('C', 2);
    contChar.insertarElemento('D', 3);
    contChar.insertarElemento('E', 4);

  
    IteradorPar<int> iterParInt(contInt);
    IteradorInverso<int> iterInvInt(contInt);

    std::cout << "Contenido (IteradorPar<int>): ";
    mostrarContenido(iterParInt);

    std::cout << "Contenido (IteradorInverso<int>): ";
    mostrarContenido(iterInvInt);

    
    IteradorInverso<char> iterInvChar(contChar);

    std::cout << "Contenido (IteradorInverso<char>): ";
    mostrarContenido(iterInvChar);

    return 0;

    // Contenedor<int> contenedorInt(5, -1);

    // contenedorInt.insertarElemento(10, 0);
    // contenedorInt.insertarElemento(20, 1);
    // contenedorInt.insertarElemento(30, 2);

    // for (unsigned int i = 0; i < contenedorInt.capacidad(); ++i) {
    //     cout << "Elemento en posicion " << i << ": " << contenedorInt.elemento(i) << endl;
    // }

    // contenedorInt.eliminarElemento(1);
    // cout << "Elemento en posicion 1 tras eliminar: " << contenedorInt.elemento(1) << endl;

    // Contenedor<string> contenedorStr(3, "N/A");
    // contenedorStr.insertarElemento("Hola", 0);
    // contenedorStr.insertarElemento("Mundo", 1);

    // for (unsigned int i = 0; i < contenedorStr.capacidad(); ++i) {
    //     cout << "Elemento en posicion " << i << ": " << contenedorStr.elemento(i) << endl;
    // }


    
}