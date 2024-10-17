#include "tanque.h"

//defecto
Tanque::Tanque():capacidadRegular(0),capacidadPremium(0),capacidadEcoExtra(0), cantidadRegular(0), cantidadPremium(0), cantidadEcoExtra(0) {}

//parametros
Tanque::Tanque(float capReg,float capPrem,float capEco)
    :capacidadRegular(capReg),capacidadPremium(capPrem),capacidadEcoExtra(capEco),
    cantidadRegular(0),cantidadPremium(0),cantidadEcoExtra(0){}

//getters
float Tanque::getCantidadRegular()const{return cantidadRegular;}
float Tanque::getCantidadPremium()const{return cantidadPremium;}
float Tanque::getCantidadEcoExtra()const{return cantidadEcoExtra;}
float Tanque::getCapacidadRegular()const{return capacidadRegular;}
float Tanque::getCapacidadPremium()const{return capacidadPremium;}
float Tanque::getCapacidadEcoExtra()const{return capacidadEcoExtra;}

float Tanque::venderCombustible(float cantidad, const string& categoria) {
    float cantidadVendida= 0;

    if (categoria=="Regular"){
        if (cantidad<=cantidadRegular){
            cantidadRegular-=cantidad;
            cantidadVendida=cantidad;
        } else{
            cantidadVendida= cantidadRegular;
            cantidadRegular=0;
        }
    } else if (categoria=="Premium") {
        if (cantidad<=cantidadPremium) {
            cantidadPremium-=cantidad;
            cantidadVendida=cantidad;
        } else {
            cantidadVendida = cantidadPremium;
            cantidadPremium = 0;
        }
    } else if (categoria =="EcoExtra") {
        if (cantidad <= cantidadEcoExtra) {
            cantidadEcoExtra-=cantidad;
            cantidadVendida=cantidad;
        } else {
            cantidadVendida=cantidadEcoExtra;
            cantidadEcoExtra=0;
        }
    } else {
        cout<<"Categoria de combustible no valida." <<endl;
    }

    return cantidadVendida;
}

void Tanque::llenarTanque(const string& categoria,float cantidad) {
    if (categoria =="Regular"){
        if (cantidadRegular+cantidad<=capacidadRegular) {
            cantidadRegular+=cantidad;
        } else {
            cantidadRegular=capacidadRegular;
        }
    } else if (categoria=="Premium"){
        if (cantidadPremium+cantidad<=capacidadPremium) {
            cantidadPremium+=cantidad;
        } else {
            cantidadPremium=capacidadPremium;
        }
    } else if (categoria=="EcoExtra") {
        if (cantidadEcoExtra+cantidad <= capacidadEcoExtra) {
            cantidadEcoExtra+= cantidad;
        } else {
            cantidadEcoExtra=capacidadEcoExtra;
        }
    } else {
        cout <<"Categoria de combustible no valida"<<endl;
    }
}

void Tanque::asignarCapacidadAleatoria() {
    srand(static_cast<unsigned int>(time(0)));
    capacidadRegular =rand()%101+100;
    capacidadPremium =rand()% 101+100;
    capacidadEcoExtra =rand() % 101+100;

    cout<<"Capacidades asignadas:"<<endl;
    cout<<"Regular: "<<capacidadRegular << " litros"<<endl;
    cout<<"Premium: "<<capacidadPremium <<" litros"<<endl;
    cout<<"EcoExtra: "<<capacidadEcoExtra <<" litros"<<endl;
}
