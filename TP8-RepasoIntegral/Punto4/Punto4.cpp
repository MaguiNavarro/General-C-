#include <iostream>
#include <vector>
#include "Control.h"
#include "Fecha.h"
#include "Sucursal.h"
#include "Cliente.h"
#include "MascotaExotica.h"
#include "MascotaTradicional.h"


int main() {

    Sucursal sucursal(1, "Av.gobernador 123");
      // Crear clientes
    Cliente* cliente1 = new Cliente(101, "Juan Perez", "juan.perez@mail.com");
    Cliente* cliente2 = new Cliente(102, "Maria Lopez", "maria.lopez@mail.com");

   
    sucursal.agregarCliente(cliente1);
    sucursal.agregarCliente(cliente2);

     // Registrar controles para las mascotas de cliente1
    cliente1->registrarMascota("Firulais", "Golden Retriever", Fecha(2020, 5, 12), "", false);
    cliente1->registrarMascota("Coco", "Guacamayo", Fecha(2021, 8, 4), "Ave tropical colorida", true);
    cliente1->registrarControlEnMascota("Firulais", "Vacuna anual", 500.0, Fecha(2024, 12, 10), Fecha(2024, 11, 27));
    cliente1->registrarControlEnMascota("Coco", "Revision general", 800.0, Fecha(2025, 1, 15), Fecha(2024, 11, 27));
    
   
    cout << "Mascotas registradas para " << cliente1->getNombre() << ".\n";
    cliente1->listarMascotasConControlProx();

    sucursal.generarResumen(11,2024);
   

   delete cliente1;
   delete cliente2;
    return 0;
 }