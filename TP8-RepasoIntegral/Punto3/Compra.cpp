#include <sstream>
#include "Compra.h"


Compra::Compra(int cod, Fecha fecha, vector<Producto*> prods)
{
	this->codigo = cod;
	this->fechaCompra = fecha;
	this->productos = prods;
}

// double Compra::calcularMonto()
// {

// 	// MODIFICAR DE ACUERDO AL DISEÑO(Listo)

// 	return totalProductos(); // Por defecto, retorna el total sin modificaciones
// }

double Compra::totalProductos()
{

	double total = 0;

	// COMPLETAR CON LA SUMA DE PRECIOS DE LOS PRODUCTOS COMPRADOS (LISTO)
	for (Producto *p : productos)
	{
		total = total + p->getPrecio();
	}

	return total;
}

void Compra::escribirInfo()
{
	cout << "Codigo de compra: " << this->codigo   << endl;
	cout << "Fecha " << this->fechaCompra << endl;
	cout << "Productos: " << endl;
	

	// COMPLETAR MOSTRANDO POR PANTALLA EL RESUMEN DE
	// CADA UNO DE LOS PRODUCTOS DE LA COMPRA (LISTO)
	for (Producto *p : productos)
	{   
		
		cout << p->resumenProducto() << endl;
	}
}

Fecha Compra::getFecha()
{
	return this->fechaCompra;
}

Compra::~Compra()
{
	// SI ES NECESARIO COMPLETAR EL DESTRUCTOR (LISTO)
	for (Producto *p : productos)
	{
		delete p;
	}
}
