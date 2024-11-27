#include <iostream>
#include "Tienda.h"
#include <vector>
using namespace std;

int main()
{
    Tienda T1("Paradigmas", "Av. Independencia 1800");

    // CREAR 3 PRODUCTOS
    Producto *prod1 = new Producto(1, "Laptop", 2000);
    Producto *prod2 = new Producto(2, "Mouse", 1200);
    Producto *prod3 = new Producto(1, "Ipad", 1000);

    vector<Producto *> productos = {prod1, prod2, prod3};
    // GENERAR 1 COMPRA DE CONTADO CON FECHA 22/09/2024 CON 1 PRODUCTO DE LA TIENDA
    Fecha fecha1(22, 9, 2024);
    T1.generarCompra(1, fecha1, productos, true, 0);
    // GENERAR 1 COMPRA EN 3 CUOTAS CON FECHA 06/08/2024 QUE CONTENGA 3 PRODUCTOS DE LA TIENDA
    Fecha fecha2(6, 8, 2024);
    T1.generarCompra(2, fecha2, productos, false, 3);
    // GENERAR 1 COMPRA EN 6 CUOTAS CON FECHA 15/09/2024 QUE CONTENGA 2 PRODUCTOS DE LA TIENDA
    Fecha fecha3(15, 9, 2024);
    T1.generarCompra(3, fecha3, productos, false, 6);

    T1.resumenCompras(9, 2024);

    delete prod1;
    delete prod2;
    delete prod3;
    return 0;
}
