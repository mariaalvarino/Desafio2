#ifndef TANQUE_H
#define TANQUE_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Tanque {
private:
    float capacidadRegular;
    float capacidadPremium;
    float capacidadEcoExtra;
    float cantidadRegular;
    float cantidadPremium;
    float cantidadEcoExtra;

public:

    Tanque(); //defecto
    //parametros
    Tanque(float capReg, float capPrem, float capEco);

    // Getters
    float getCantidadRegular() const;
    float getCantidadPremium() const;
    float getCantidadEcoExtra() const;
    float getCapacidadRegular() const;
    float getCapacidadPremium() const;
    float getCapacidadEcoExtra() const;

    // Métodos
    float venderCombustible(float cantidad, const string& categoria);
    void llenarTanque(const string& categoria, float cantidad);
    void asignarCapacidadAleatoria();
};

#endif // TANQUE_H
