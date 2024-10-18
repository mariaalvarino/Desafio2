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
float Surtidor::getTotalVendido() const {
    float total = 0;
    for (int i = 0; i < numeroTransacciones; ++i) {
        total += historicoTransacciones[i].getCantidad();
    }
    return total;
}
void Surtidor::calcularVentasPorCategoria(float& totalRegular, float& totalPremium, float& totalEcoExtra) const {
    for (int i = 0; i < numeroTransacciones; ++i) {
        string categoria = historicoTransacciones[i].getCategoria();
        float monto = historicoTransacciones[i].getMonto();
        if (categoria == "Regular") {
            totalRegular += monto;
        } else if (categoria == "Premium") {
            totalPremium += monto;
        } else if (categoria == "EcoExtra") {
            totalEcoExtra += monto;
        }
    }
}
void Surtidor::mostrarHistorico() const {
    for (int i = 0; i < numeroTransacciones; ++i) {
        historicoTransacciones[i].mostrarDetalles();
        cout << "-------------------" << endl;
    }
}
