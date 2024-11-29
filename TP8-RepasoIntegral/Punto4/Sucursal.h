#ifndef SUCURSAL_H_
#define SUCURSAL_H_

#include <iostream>
#include "Cliente.h"
class Sucursal
{
private:
     int codigo;
    string direccion;
    vector<Cliente*> clientes;
public:
    Sucursal(int cod, string direc);
    void agregarCliente(Cliente *cliente);
      void generarResumen(int mes, int anio) const;

    ~Sucursal();
};

Sucursal::Sucursal(int cod, string direc)
{
    this->codigo=cod;
    this->direccion=direc;
}
void Sucursal:: agregarCliente(Cliente *cliente){
       
        clientes.push_back(cliente);
    }
     void Sucursal::generarResumen(int mes, int anio) const {
        double totalRecaudado = 0;
        cout << "Resumen de Sucursal " << codigo << " - " << direccion << ":\n";
        for (Cliente* cliente : clientes) {
            double montoCliente = cliente->calcularMontoMes(mes, anio);
            totalRecaudado += montoCliente;
            cout << "\nCliente: " << cliente->getNombre() << ",\n Monto: $" << montoCliente << endl;
        }
        cout << "\nTotal RECAUDADO: $" << totalRecaudado << endl;
    }
Sucursal::~Sucursal()
{
}


#endif /* SUCURSAL_H_ */