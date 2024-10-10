#include <iostream>
#include "Class.h"
using namespace std;


int main() {
    /*
    Surtidor surtidor1(101, "Modelo A");

    // Crear una transacción
    Transaccion trans("2023-10-10", "10:00", 10.0, "Regular", "Efectivo", 12345678, 50.0);
    
    // Registrar la transacción en el surtidor
    surtidor1.registrarTransaccion(trans);

    // Mostrar el histórico de transacciones
    surtidor1.mostrarHistorico();

    return 0;
    */
    Tanque tanque(200.0, 150.0, 100.0); //Capacidad del tanque (cantidadRegular, cantidadPremium, cantidadEcoExtra)
    // Llenar el tanque con combustible
    tanque.llenarTanque("Regular", 150.0);
    tanque.llenarTanque("Premium", 100.0);
    
    // Vender combustible
    float vendidos = tanque.venderCombustible(60.0, "Regular");
    cout << "Se vendieron: " << vendidos << " litros de combustible Regular." << endl;
    
    vendidos = tanque.venderCombustible(200.0, "Premium");
    cout << "Se vendieron: " << vendidos << " litros de combustible Premium." << endl;

    // Verificar cantidades restantes
    cout << "Cantidad restante de Regular: " << tanque.getCantidadRegular() << " litros." << endl;
    cout << "Cantidad restante de Premium: " << tanque.getCantidadPremium() << " litros." << endl;

    return 0;
}
