#ifndef COMPRA_H_
#define COMPRA_H_

#include <iostream>
#include "Producto.h"
#include "Fecha.h"
#include <vector>
using namespace std;

class Compra {

protected:
	int codigo;
	Fecha fechaCompra;

	//COMPLETAR ATRIBUTOS(LISTO)
     vector<Producto*> productos;
	double totalProductos();

public:
	Compra(int cod, Fecha fec, vector<Producto*> productos);

	virtual double calcularMonto()const = 0; //MODIFICAR DE ACUERDO AL DISEÑO(LISTO)
	virtual void escribirInfo();
	Fecha getFecha() ;
	virtual ~Compra();
};

#endif /* COMPRA_H_ */
