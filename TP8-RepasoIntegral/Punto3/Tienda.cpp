#include "Tienda.h"

Tienda::Tienda(string nomb, string dir)
{
	this->nombre = nomb;
	this->direccion = dir;

	// COMPLETAR INICIALIZACI�N DE ATRIBUTOS SI ES NECESARIO
}

void Tienda::generarCompra(int cod, Fecha fec, vector<Producto *> productos, bool esContado, int cuotas)
{
	// COMPLETAR DE ACUERDO A LOS PARAMETROS RECIBIDOS
	Compra *compra;
	if (esContado)
	{
		compra = new CompraDeContado(cod, fec, productos);
	}
	else
	{
		compra = new CompraEnCuotas(cod, fec, productos, cuotas);
	}

	compras.push_back(compra);
}

void Tienda::resumenCompras(int mes, int anio)
{

	cout << "Tienda " << this->nombre << endl;
	cout << "Direccion: " << this->direccion << endl;
	cout << "Resumen compras: " << mes << "/" << anio << endl;

	// COMPLETAR MOSTRANDO POR PANTALLA LA INFORMACION DE CADA UNA DE LAS COMPRAS DE LA TIENDA
	// QUE SE HICIERON EN ESE MES/ANIO

	for (Compra *compra : compras)
	{
		if (compra->getFecha().getMes() == mes && compra->getFecha().getAnio() == anio)
		{
			compra->escribirInfo(); // Llama al método para mostrar la información
			cout << "=========================" << endl;
		}
	}
}

Tienda::~Tienda()
{
	// SI ES NECESARIO COMPLETAR EL DESTRUCTOR
	for (Compra *compra : compras)
	{
		delete compra;
	}
	compras.clear();
}
