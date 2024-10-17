#include "transaccion.h"

// Constructor por defecto
Transaccion::Transaccion() : fecha(""), hora(""), cantidad(0), categoria(""), metodoPago(""), documentoCliente(0), monto(0) {}

// Constructor con parámetros
Transaccion::Transaccion(string f, string h, float c, string cat, string metodo, int doc, float m)
    : fecha(f), hora(h), cantidad(c), categoria(cat), metodoPago(metodo), documentoCliente(doc), monto(m) {}

// Getters
string Transaccion::getFecha() const { return fecha; }
string Transaccion::getHora() const { return hora; }
float Transaccion::getCantidad() const { return cantidad; }
string Transaccion::getCategoria() const { return categoria; }
string Transaccion::getMetodoPago() const { return metodoPago; }
int Transaccion::getDocumentoCliente() const { return documentoCliente; }
float Transaccion::getMonto() const { return monto; }

// Mostrar detalles de la transacción
void Transaccion::mostrarDetalles() const {
    cout << "Detalles de la Transacción:\n"
         << "Fecha: " << fecha << "\n"
         << "Hora: " << hora << "\n"
         << "Cantidad: " << cantidad << " litros\n"
         << "Categoría: " << categoria << "\n"
         << "Método de Pago: " << metodoPago << "\n"
         << "Documento Cliente: " << documentoCliente << "\n"
         << "Monto: $" << monto << endl;
}
