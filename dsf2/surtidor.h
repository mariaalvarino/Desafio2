#ifndef SURTIDOR_H
#define SURTIDOR_H

#include "transaccion.h"

class Surtidor {
private:
    int codigo;
    string modelo;
    bool activo;
    Transaccion historicoTransacciones[100];
    int numeroTransacciones;

public:
    // Constructor por defecto
    Surtidor();

    // Constructor con parámetros
    Surtidor(int cod, string mod);

    // Getters
    int getCodigo() const;
    string getModelo() const;
    bool isActivo() const;
    int getNumeroTransacciones() const;
    const Transaccion& getTransaccion(int index) const;

    // Métodos
    void activar();
    void desactivar();
    void registrarTransaccion(const Transaccion& transaccion);
    void mostrarHistorico() const;
    void calcularVentasPorCategoria(float& totalRegular, float& totalPremium, float& totalEcoExtra) const;
};

#endif // SURTIDOR_H