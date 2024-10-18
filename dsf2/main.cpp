#include "redestacion.h"
#include <iostream>
using namespace std;

int main() {

    RedEstacion redEstaciones(100);  // Se inicializa la red con capacidad para 100 estaciones

    // Crear estaciones de servicio
    EstacionServicio estacion1("Estación Norte", "321", "Gerente1", "Norte", 10.0, -74.0, 200, 150, 100);
    EstacionServicio estacion2("Estación Centro", "E002", "Gerente2", "Centro", 5.0, -75.0, 250, 200, 150);
    
    // Agregar estaciones a la red
    redEstaciones.agregarEstacion(estacion1);
    redEstaciones.agregarEstacion(estacion2);

    // Agregar surtidores a las estaciones
    estacion1.agregarSurtidor(101, "Modelo A");
    estacion1.agregarSurtidor(102, "Modelo B");
    estacion2.agregarSurtidor(201, "Modelo C");

    int opcion;

    do {
        cout <<endl<< "         MENU PRINCIPAL    " << endl;
        cout << "1 Agregar estacion de servicio" << endl;
        cout << "2 Eliminar estacion de Servicio" << endl;
        cout << "3 Agregar surtidor a una estacion" << endl;
        cout << "4 Eliminar surtidor de una estacion" << endl;
        cout << "5 Simular venta de combustible" << endl;
        cout << "6 Mostrar historial de transacciones de una estacion" << endl;
        cout << "7 Calcular ventas totales por categoria" << endl;
        cout << "8 Fijar precios de combustible por region" << endl;
        cout << "9 verificar fugas de combustible" << endl;
        cout << "10 Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1: {
                // Agregar Estación de Servicio
                string nombre, codigo, gerente, region;
                float lat, lon;
                cout <<endl<< "Ingrese el nombre de la estacion: "; cin >>nombre;
                cout << "Ingrese el codigo de la estacion: "; cin >> codigo;
                cout << "Ingrese el nombre del gerente: "; cin >> gerente;
                cout << "Ingrese la region (Norte/Centro/Sur): "; cin >> region;
                cout << "Ingrese la latitud de la estacion: "; cin >> lat;
                cout << "Ingrese la longitud de la estacion: "; cin >> lon;

                // Crear la estacion y agregarla a la red
                EstacionServicio estacion(nombre, codigo, gerente, region, lat, lon, 150, 180, 170);
                redEstaciones.agregarEstacion(estacion);
                cout << "Estacion de servicio agregada exitosamente." <<endl;
                break;
            }
            case 2: {
                // Eliminar Estacion de Servicio
                string codigo;
                cout << endl<<"Ingrese el codigo de la estacion a eliminar: "; cin >> codigo;
                redEstaciones.eliminarEstacion(codigo);
                break;
            }
            case 3: {
                // Agregar Surtidor a una Estación
                string codigoEstacion;
                int codigoSurtidor;
                string modeloSurtidor;
                cout <<endl<< "Ingrese el codigo de la estacion: "; cin >> codigoEstacion;
                cout << "Ingrese el codigo del surtidor: "; cin >> codigoSurtidor;
                cout << "Ingrese el modelo del surtidor: "; cin >> modeloSurtidor;


                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->agregarSurtidor(codigoSurtidor, modeloSurtidor);
                        cout << "Surtidor agregado a la estacion." << endl;
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                    cout << "Estacion no encontrada." << std::endl;
                }
                break;
            }
            case 4: {
                // Eliminar Surtidor de una Estacion
                string codigoEstacion;
                int codigoSurtidor;
                cout << endl<<"Ingrese el codigo de la estacion: ";cin >> codigoEstacion;
                cout << "Ingrese el codigo del surtidor a eliminar: ";cin >> codigoSurtidor;

                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->eliminarSurtidor(codigoSurtidor);
                        cout << "Surtidor eliminado de la estacion." <<endl;
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                   cout << "Estacion no encontrada" <<endl;
                }
                break;
            }
            case 5: {
                // Simular Venta de Combustible
                string codigoEstacion, categoria;
                float cantidadSolicitada;
                cout <<endl<< "Ingrese el codigo de la estacion: ";cin >> codigoEstacion;
                cout << "Ingrese la categoria de combustible (Regular, Premium, EcoExtra): ";cin >> categoria;
                cout << "Ingrese la cantidad de combustible solicitada: "; cin >> cantidadSolicitada;

                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->simularVenta(cantidadSolicitada, categoria, 12345); // Documento cliente por defecto
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                   cout << "Estacion no encontrada" <<endl;
                }
                break;
            }
            case 6: {
                // Mostrar Historial de Transacciones
                string codigoEstacion;
                cout <<endl<< "Ingrese el codigo de la estacion: ";cin >> codigoEstacion;

                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->mostrarSurtidores();
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                   cout << "No se encontro la estacion" <<endl;
                }
                break;
            }
            case 7: {
                float totalRegular = 0, totalPremium = 0, totalEcoExtra = 0;
                redEstaciones.calcularVentasTotal(totalRegular, totalPremium, totalEcoExtra);

                cout<<endl<< "Ventas Totales en la red:" <<endl;
                cout<<"Regular:"<< totalRegular<< " pesos"<<endl;
                cout<<"Premium:"<<totalPremium<<" pesos"<<endl;
                cout<<"EcoExtra:"<< totalEcoExtra<<" pesos"<<endl;
                break;

            }
            case 8: {
                // Fijar precios de combustible
                float precioRegNorte, precioPremNorte, precioEcoNorte;
                float precioRegCentro, precioPremCentro, precioEcoCentro;
                float precioRegSur, precioPremSur, precioEcoSur;

                cout<<"Ingrese el precio de Regular para Norte:";cin>>precioRegNorte;
                cout<<"Ingrese el precio de Premium para Norte:"; cin>>precioPremNorte;
                cout<<"Ingrese el precio de EcoExtra para Norte:";cin>> precioEcoNorte;

                cout<<"Ingrese el precio de Regular para Centro: ";cin>>precioRegCentro;
                cout<<"Ingrese el precio de Premium para Centro: ";cin>>precioPremCentro;
                cout<<"Ingrese el precio de EcoExtra para Centro: ";cin>> precioEcoCentro;

                cout << "Ingrese el precio de Regular para Sur: ";cin>>precioRegSur;
                cout << "Ingrese el precio de Premium para Sur: ";cin>>precioPremSur;
                cout << "Ingrese el precio de EcoExtra para Sur: ";cin>>precioEcoSur;

                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion->getRegion() == "Norte") {
                        estacion->precios.precioRegularNorte = precioRegNorte;
                        estacion->precios.precioPremiumNorte = precioPremNorte;
                        estacion->precios.precioEcoNorte = precioEcoNorte;
                    } else if (estacion->getRegion() == "Centro") {
                        estacion->precios.precioRegularCentro = precioRegCentro;
                        estacion->precios.precioPremiumCentro = precioPremCentro;
                        estacion->precios.precioEcoCentro = precioEcoCentro;
                    } else if (estacion->getRegion() == "Sur") {
                        estacion->precios.precioRegularSur = precioRegSur;
                        estacion->precios.precioPremiumSur = precioPremSur;
                        estacion->precios.precioEcoSur = precioEcoSur;
                    }
                }
                cout<<"Precios de combustible actualizados" <<endl;
                break;

            }
            case 9:{
                // Verificar Fugas de Combustible
                string codigoEstacion;
                cout<<"Ingrese el codigo de la estacion para verificar fugas: ";cin>>codigoEstacion;
                if (redEstaciones.verificarFugas(codigoEstacion)){
                    cout<<"Se detecto fuga en la estacion"<<endl;
                } else {
                    cout<<"No se detectaron fugas en la estacion"<<endl;
                }
                break;
            }
            case 10:
                cout<<"Saliendo del programa gracias por usar nuestros servcios"<<endl;
                break;
            default:
                cout<<"Opcion invalida intente de nuevo"<<endl;
        }
    } while (opcion!=10);

    return 0;
}

