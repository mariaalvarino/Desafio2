#include "redestaciones.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Antes de instanciar" << endl;

    RedEstaciones redEstaciones(100);  // Se inicializa la red con capacidad para 100 estaciones

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
        std::cout << "\n*** MENÚ PRINCIPAL ***" << std::endl;
        std::cout << "1. Agregar Estación de Servicio" << std::endl;
        std::cout << "2. Eliminar Estación de Servicio" << std::endl;
        std::cout << "3. Agregar Surtidor a una Estación" << std::endl;
        std::cout << "4. Eliminar Surtidor de una Estación" << std::endl;
        std::cout << "5. Simular Venta de Combustible" << std::endl;
        std::cout << "6. Mostrar Historial de Transacciones de una Estación" << std::endl;
        std::cout << "7. Calcular Ventas Totales por Categoría" << std::endl;
        std::cout << "8. Fijar Precios de Combustible" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar Estación de Servicio
                std::string nombre, codigo, gerente, region;
                float lat, lon;
                std::cout << "\nIngrese el nombre de la estación: "; std::cin >> nombre;
                std::cout << "Ingrese el código de la estación: "; std::cin >> codigo;
                std::cout << "Ingrese el nombre del gerente: "; std::cin >> gerente;
                std::cout << "Ingrese la región (Norte/Centro/Sur): "; std::cin >> region;
                std::cout << "Ingrese la latitud de la estación: "; std::cin >> lat;
                std::cout << "Ingrese la longitud de la estación: "; std::cin >> lon;

                // Crear la estación y agregarla a la red
                EstacionServicio estacion(nombre, codigo, gerente, region, lat, lon, 150, 180, 170);
                redEstaciones.agregarEstacion(estacion);
                std::cout << "Estación de servicio agregada exitosamente." << std::endl;
                break;
            }
            case 2: {
                // Eliminar Estación de Servicio
                std::string codigo;
                std::cout << "\nIngrese el código de la estación a eliminar: "; std::cin >> codigo;
                redEstaciones.eliminarEstacion(codigo);
                break;
            }
            case 3: {
                // Agregar Surtidor a una Estación
                std::string codigoEstacion;
                int codigoSurtidor;
                std::string modeloSurtidor;
                std::cout << "\nIngrese el código de la estación: "; std::cin >> codigoEstacion;
                std::cout << "Ingrese el código del surtidor: "; std::cin >> codigoSurtidor;
                std::cout << "Ingrese el modelo del surtidor: "; std::cin >> modeloSurtidor;

                // Asegúrate de que el código de estación sea válido
                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->agregarSurtidor(codigoSurtidor, modeloSurtidor);
                        std::cout << "Surtidor agregado a la estación." << std::endl;
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                    std::cout << "Estación no encontrada." << std::endl;
                }
                break;
            }
            case 4: {
                // Eliminar Surtidor de una Estación
                std::string codigoEstacion;
                int codigoSurtidor;
                std::cout << "\nIngrese el código de la estación: "; std::cin >> codigoEstacion;
                std::cout << "Ingrese el código del surtidor a eliminar: "; std::cin >> codigoSurtidor;

                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->eliminarSurtidor(codigoSurtidor);
                        std::cout << "Surtidor eliminado de la estación." << std::endl;
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                    std::cout << "Estación no encontrada." << std::endl;
                }
                break;
            }
            case 5: {
                // Simular Venta de Combustible
                std::string codigoEstacion, categoria;
                float cantidadSolicitada;
                std::cout << "\nIngrese el código de la estación: "; std::cin >> codigoEstacion;
                std::cout << "Ingrese la categoría de combustible (Regular, Premium, EcoExtra): "; std::cin >> categoria;
                std::cout << "Ingrese la cantidad de combustible solicitada: "; std::cin >> cantidadSolicitada;

                bool estacionEncontrada = false;
                for (int i = 0; i < redEstaciones.getContadorEstaciones(); i++) {
                    EstacionServicio* estacion = redEstaciones.getEstacion(i);
                    if (estacion && estacion->getCodigo() == codigoEstacion) {
                        estacion->simularVenta(cantidadSolicitada, categoria, 12345); // Documento cliente por defecto
                        std::cout << "Venta simulada exitosamente." << std::endl;
                        estacionEncontrada = true;
                        break;
                    }
                }
                if (!estacionEncontrada) {
                    std::cout << "Estación no encontrada." << std::endl;
                }
                break;
            }
            case 6: {
                // Mostrar Historial de Transacciones
                std::string codigoEstacion;
                std::cout << "\nIngrese el código de la estación: "; std::cin >> codigoEstacion;

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
                    std::cout << "Estación no encontrada." << std::endl;
                }
                break;
            }
            case 7: {

            }
            case 8: {

            }
            case 9: 
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción inválida, por favor intente de nuevo." << std::endl;
        }
    } while (opcion != 9);

    return 0;
}

