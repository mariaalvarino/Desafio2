#ifndef PRECIOCOMBUSTIBLE_H
#define PRECIOCOMBUSTIBLE_H

class preciocombustible
{
public:
    float precioRegularNorte;
    float precioPremiumNorte;
    float precioEcoNorte;

    float precioRegularCentro;
    float precioPremiumCentro;
    float precioEcoCentro;

    float precioRegularSur;
    float precioPremiumSur;
    float precioEcoSur;
    preciocombustible(){
        precioRegularNorte = 10000;
        precioPremiumNorte = 12000;
        precioEcoNorte = 9100;

        precioRegularCentro = 11000;
        precioPremiumCentro = 13000;
        precioEcoCentro = 9550;

        precioRegularSur = 10500;
        precioPremiumSur = 12500;
        precioEcoSur = 9200;
    }
};

#endif // PRECIOCOMBUSTIBLE_H
