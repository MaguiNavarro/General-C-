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
      Mascota* buscarMascota( string nombreMascota) const; // Nuevo método
    void registrarControlEnMascota(string nombreMascota,  string desc, 
                                    double monto, Fecha proxControl, Fecha control);
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
            total = total + mascota->calcularMontoMes(mes, anio);
        }
        return total;
    }
    Mascota* Cliente::buscarMascota(string nombreMascota) const {
    for (Mascota* mascota : mascotas) {
        if (mascota->getNombre() == nombreMascota) {
            return mascota;
        }
    }
    return nullptr; // Mascota no encontrada
}

void Cliente::registrarControlEnMascota(string nombreMascota, string desc, 
                                        double monto, Fecha proxControl, Fecha control) {
    Mascota* mascota = buscarMascota(nombreMascota);
    if (mascota) {
        mascota->registrarControl(desc, monto, proxControl, control);
        mascota->mostrarInfo();
    } else {
        cout << "Error: Mascota con nombre '" << nombreMascota << "' no encontrada.\n";
    }
}

     void Cliente:: listarMascotasConControlProx() const {
        cout << "Mascotas con control proximo:\n";
        for (Mascota* mascota : mascotas) {
            if (mascota->tieneControlProximo()) {
                 mascota->mostrarInfo();
            }else
            {
                cout<< "\n NO Hay"<<endl;
            }
            
        }
    }

Cliente::~Cliente()
{
    for (Mascota* mascota : mascotas){
        delete mascota;
    }
    mascotas.clear();
}


#endif /* CLIENTE_H_ */