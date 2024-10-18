#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H
#include"preciocombustible.h"
#include "surtidor.h"
#include "tanque.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>



using namespace std;

class EstacionServicio {
private:
    string nombre;
    string codigo;
    string gerente;
    string region;
    float coordenadas[2];
    Surtidor surtidores[12];// Arreglo de surtidores
    int surtidorCount;// Contador de surtidores
    Tanque tanque;// Objeto tanque


public:
    preciocombustible precios;
    // Constructor por defecto
    EstacionServicio();


    EstacionServicio(string n, string c, string g, string r, float lat, float lon, float capReg, float capPrem, float capEco);

    // Métodos
    string getRegion() const;
    string getCodigo() const;
    bool agregarSurtidor(int codigo, string modelo);
    bool eliminarSurtidor(int codigo);
    void reportarLitrosVendidos(string categoria) const;
    void simularVenta(float cantidadSolicitada, const string& categoria, int documentoCliente);
    void mostrarSurtidores() const;
    bool tieneSurtidoresActivos() const;
    void calcularVentasPorCategoria(float& totalRegular, float& totalPremium, float& totalEcoExtra) const;
    Tanque& getTanque();
    short int obtenerPrecioPorCategoria(const std::string& categoria) const;
    bool verificarFugas() const;
};

#endif // ESTACIONSERVICIO_H
