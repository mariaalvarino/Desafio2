#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <string>
using namespace std;

class Transaccion {
private:
    string fecha;
    string hora;
    float cantidad;
    string categoria;
    string metodoPago;
    int documentoCliente;
    float monto;

public:

    Transaccion();// Constructor por defecto
    // Constructor con parametros
    Transaccion(string f, string h, float c, string cat, string metodo, int doc, float m);
    // Getters
    string getFecha() const;
    string getHora() const;
    float getCantidad() const;
    string getCategoria() const;
    string getMetodoPago() const;
    int getDocumentoCliente() const;
    float getMonto() const;
    void mostrarDetalles() const;
};

#endif // TRANSACCION_H
