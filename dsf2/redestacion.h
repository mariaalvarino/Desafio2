#ifndef REDESTACION_H
#define REDESTACION_H

#include "estacionservicio.h"
#include <string>

class RedEstacion {
private:
    EstacionServicio** estaciones;//Puntero a puntero para un arreglo dinamico
    int contadorEstaciones;
    int maxEstaciones;//capacidad maxima

public:
    RedEstacion(int maxEstaciones);//capacidad maxima
    ~RedEstacion();//liberar memoria

    void agregarEstacion(const EstacionServicio& estacion);//agregar una nueva estacion
    void eliminarEstacion(const std::string& codigo);//eliminar estacion por codigo
    void calcularVentasTotal(float& totalRegular,float& totalPremium, float& totalEcoExtra) const;//ventas totales
    bool verificarFugas(const std::string& codigoEstacion) const;
    //estacion por indice
    EstacionServicio* getEstacion(int index);//puntero para manejar errores sin excepciones
    EstacionServicio* getEstacionPorCodigo(const string& codigo) const;
    int getContadorEstaciones()const;//cantidad actual de estaciones
};


#endif // REDESTACION_H
