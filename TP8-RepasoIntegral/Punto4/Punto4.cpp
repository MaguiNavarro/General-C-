#include <iostream>
#include <vector>
#include "Control.h"
#include "Fecha.h"
#include "Sucursal.h"
#include "Cliente.h"
#include "MascotaExotica.h"
#include "MascotaTradicional.h"


int main() {
    // Crear sucursal
    Sucursal sucursal(1, "Av.gobernador 123");
    // Registrar clientes
    sucursal.registrarCliente(101, "Juan Perez", "juan.perez@mail.com");
    sucursal.registrarCliente(102, "Maria Lopez", "maria.lopez@mail.com");

    // Registrar mascotas para el cliente 101
    Cliente cliente1(101, "Juan Perez", "juan.perez@mail.com");
    cliente1.registrarMascota("Firulais", "Golden Retriever", Fecha(2020, 5, 12), "", false);
    cliente1.registrarMascota("Coco", "Guacamayo", Fecha(2021, 8, 4), "Ave tropical colorida", true);
    cout << "Mascotas registradas para Juan Perez.\n";

       // Registrar controles para las mascotas
     Mascota* firulais = new MascotaTradicional("Firulais", "Golden Retriever", Fecha(2020, 5, 12));
    firulais->registrarControl("Control general", 50.0, Fecha(2024, 12, 1), Fecha(2024, 11, 15));

    Mascota* coco = new MascotaExotica("Coco", "Guacamayo", Fecha(2021, 8, 4), "Ave tropical colorida");
    coco->registrarControl("Vacuna exótica", 100.0, Fecha(2024, 11, 30), Fecha(2024, 11, 10));


    // Calcular montos
    double montoMesJuan = cliente1.calcularMontoMes(11, 2024);
    cout << "Monto total para Juan en noviembre de 2024: $" << montoMesJuan << endl;

    
    cout << "\nMascotas con controles proximos de Juan:\n";
    cliente1.listarMascotasConControlProx();

  
    sucursal.generarResumen(11, 2024);

    
    delete firulais;
    delete coco;

   return 0;
 

 }