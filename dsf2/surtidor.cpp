#include "surtidor.h"
#include <iostream>

Surtidor::Surtidor() : codigo(0), modelo(""), activo(false), numeroTransacciones(0) {}

Surtidor::Surtidor(int cod, string mod) : codigo(cod), modelo(mod), activo(true), numeroTransacciones(0) {}

int Surtidor::getCodigo() const { return codigo; }
string Surtidor::getModelo() const { return modelo; }
bool Surtidor::isActivo() const { return activo; }

int Surtidor::getNumeroTransacciones() const {
    return numeroTransacciones;
}

const Transaccion& Surtidor::getTransaccion(int index) const {
    if (index < 0 || index >= numeroTransacciones) {
        throw out_of_range("indice fuera de rango.");
    }
    return historicoTransacciones[index];
}

void Surtidor::activar() { activo = true; }
void Surtidor::desactivar() { activo = false; }

void Surtidor::registrarTransaccion(const Transaccion& transaccion) {
    if (numeroTransacciones<100) {
        historicoTransacciones[numeroTransacciones++]=transaccion;
    } else {
        cout<<"Limite de transacciones alcanzado" <<endl;
    }
}
