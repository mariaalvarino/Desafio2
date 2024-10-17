#include "redestacion.h"

#include <iostream>

//inicializacion
RedEstacion::RedEstacion(int maxEstaciones)
    : contadorEstaciones(0),maxEstaciones(maxEstaciones) {
    estaciones=new EstacionServicio*[maxEstaciones];  // Asignar memoria para arreglo de punteros a estaciones
    for (int i=0;i<maxEstaciones;++i) {
        estaciones[i]=nullptr;//inicializa los punteros en nullptr
    }
}

// Destructor que libera la memoria utilizada
RedEstacion::~RedEstacion() {
    for (int i= 0;i<contadorEstaciones;++i) {
        delete estaciones[i];//liberar la memoria en las esatciones
    }
    delete[] estaciones;//liberar la memoria en los punteros
}

//nueva estacion
void RedEstacion::agregarEstacion(const EstacionServicio& estacion) {
    if (contadorEstaciones < maxEstaciones){
        estaciones[contadorEstaciones]=new EstacionServicio(estacion);  // Asignar memoria y copiar la estación
        contadorEstaciones++;
    } else {
        cout<<"No es posible agregar mas estcaiones" <<endl;
    }
}

//eliminar una estacion
void RedEstacion::eliminarEstacion(const std::string& codigo) {
    for (int i=0;i<contadorEstaciones;++i) {
        if (estaciones[i]->getCodigo()==codigo) {
            if (estaciones[i]->tieneSurtidoresActivos()) {
                cout << "No se puede eliminar la estacion"<<codigo<<" porque tiene surtidores activos"<<endl;
                return;
            }
            delete estaciones[i];//liberar memoria
            //mover estaciones
            for (int j=i;j<contadorEstaciones-1;++j) {
                estaciones[j]=estaciones[j+1];
            }
            estaciones[contadorEstaciones-1]=nullptr;
            contadorEstaciones--;
            cout<< "Estacion "<<codigo<<" eliminada." <<endl;
            return;
        }
    }
    cout<<"No se encontro la estacion"<<endl;
}

//ventas totales
void RedEstacion::calcularVentasTotal(float& totalRegular, float& totalPremium, float& totalEcoExtra) const {
    totalRegular=0.0;
    totalPremium=0.0;
    totalEcoExtra= 0.0;
    for (int i= 0;i<contadorEstaciones;++i) {
        estaciones[i]->calcularVentasPorCategoria(totalRegular, totalPremium, totalEcoExtra);
    }
}

EstacionServicio* RedEstacion::getEstacion(int index) {
    if (index<0||index >=contadorEstaciones) {
        cout<< "fuera de rango: " << index << endl;
        return nullptr;  //nullptr indice es invalido
    }
    return estaciones[index];//puntero de estacion
}

//cantidad actual de estaciones
int RedEstacion::getContadorEstaciones()const {
    return contadorEstaciones;
}

bool RedEstacion::verificarFugas(const string& codigoEstacion) const {
    EstacionServicio* estacion=getEstacionPorCodigo(codigoEstacion);
    if (estacion)
    {
        return estacion->verificarFugas();
    } else {
        cout << "Estacion no encontrada" <<endl;
        return false; //false si no es encontrada la estacion
    }
}
