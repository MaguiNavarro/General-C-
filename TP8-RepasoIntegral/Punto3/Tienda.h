#ifndef TIENDA_H_
#define TIENDA_H_

#include <iostream>
#include <vector>

#include "CompraDeContado.h"
#include "CompraEnCuotas.h"

class Tienda {
	string nombre;
	string direccion;
  
	//COMPLETAR ATRIBUTOS
    vector<Compra*> compras;
public:
	Tienda(string nomb, string dir);
	void generarCompra(int cod, Fecha fechaCom, vector<Producto*> producto, bool esContado, int cuotas);
	void resumenCompras(int mes, int anio);
	virtual ~Tienda();
};

#endif /* TIENDA_H_ */
