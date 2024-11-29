#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include "Mascota.h"
#include "MascotaExotica.h"
#include "MascotaTradicional.h"
using namespace std;

class Cliente
{
private:
  int codigo;
    string nombre;
    string correo;
    vector<Mascota*> mascotas;

public:
     Cliente(int codigo, string nombre, string correo );
     string getNombre();
     void registrarMascota(string nombre, string raza, Fecha fechaNac, string desc, bool esExotica);
     double calcularMontoMes(int mes, int anio) const ;
     void listarMascotasConControlProx() const ;
     ~Cliente();
};

Cliente::Cliente(int codig, string nomb, string correo)
{
    this->codigo=codig;
    this->nombre= nomb;
    this->correo= correo;
}
 string Cliente:: getNombre(){
      return this->nombre;
 }
void Cliente:: registrarMascota(string nombre, string raza, Fecha fechaNac, string desc, bool esExotica){
    Mascota* mascota;
        if (esExotica)
        {
            mascota= new MascotaExotica(nombre, raza, fechaNac,desc);
        }else
        {
            mascota= new MascotaTradicional(nombre, raza, fechaNac);
        }
        mascotas.push_back(mascota);
}

 double Cliente::calcularMontoMes(int mes, int anio) const {
        double total = 0;
        for (Mascota* mascota : mascotas) {
            total += mascota->calcularMontoMes(mes, anio);
        }
        return total;
    }


     void Cliente:: listarMascotasConControlProx() const {
        cout << "Mascotas con control proximo:\n";
        for (Mascota* mascota : mascotas) {
            if (mascota->tieneControlProximo()) {
                 mascota->mostrarInfo();
            }
        }
    }

Cliente::~Cliente()
{
}


#endif /* CLIENTE_H_ */