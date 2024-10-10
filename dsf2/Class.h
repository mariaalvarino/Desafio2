#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Transaccion{
    private:
    string fecha;
    string hora;
    float cantidad;
    string categoria; // Regular, Premium, EcoExtra
    string metodoPago; // Efectivo, TDebito, TCredito
    int documentoCliente;
    float monto;

    public:
    //contructor por defecto 
    Transaccion() 
        : fecha(""), hora(""), cantidad(0), categoria(""), metodoPago(""), documentoCliente(0), monto(0) {}
    // Constructor con parámetros
    Transaccion(string f, string h, float c, string cat, string metodo, int doc, float m) 
        : fecha(f), hora(h), cantidad(c), categoria(cat), metodoPago(metodo), documentoCliente(doc), monto(m) {}

    //funciones get
    string getFecha() const { return fecha; }
    string getHora() const { return hora; }
    float getCantidad() const { return cantidad; }
    string getCategoria() const { return categoria; }
    string getMetodoPago() const { return metodoPago; }
    int getDocumentoCliente() const { return documentoCliente; }
    float getMonto() const { return monto; }

    //funciones set
    void mostrarDetalles() const {
        cout << "Detalles de la Transacción:\n"
             << "Fecha: " << fecha << "\n"
             << "Hora: " << hora << "\n"
             << "Cantidad: " << cantidad << "\n"
             << "Categoría: " << categoria << "\n"
             << "Método de Pago: " << metodoPago << "\n"
             << "Documento Cliente: " << documentoCliente << "\n"
             << "Monto: " << monto << "\n";
    }

};
class Surtidor {
    private:
    int codigo;
    string modelo;
    bool activo;
    Transaccion historicoTransacciones[100]; // Array estático para almacenar hasta 100 transacciones
    int numeroTransacciones; // Contador de transacciones registradas

    public:
    // Constructor por defecto
    Surtidor() : codigo(0), modelo(""), activo(false), numeroTransacciones(0) {}

    // Constructor con parámetros
    Surtidor(int cod, string mod)
     : codigo(cod), modelo(mod), activo(true), numeroTransacciones(0) {}

    //funciones gets
    int getCodigo() const { return codigo; }
    string getModelo() const { return modelo; }
    bool isActivo() const { return activo; }
    //METODOS
    // Activar  surtidor
    void activar() { activo = true; }

    // Desactivar surtidor
    void desactivar() { activo = false; }
    //Registrar transacción
    void registrarTransaccion(const Transaccion &transaccion) {
        if (numeroTransacciones < 100) { // Asegurarse de no exceder el límite
            historicoTransacciones[numeroTransacciones++] = transaccion;
        } else {
            cout << "Límite de transacciones alcanzado." << endl;
        }
    }
    //Mostrar  história de transacciones
    void mostrarHistorico() const {
        cout << "Historial de Transacciones para Surtidor " << codigo << " (" << modelo << "):" << endl;
        for (int i = 0; i < numeroTransacciones; ++i) {
            historicoTransacciones[i].mostrarDetalles(); // Mostrar detalles completos de cada transacción
            
            cout << endl; // Separador entre transacciones
        }
    }

};
class Tanque {
private:
    float capacidadRegular;
    float capacidadPremium;
    float capacidadEcoExtra;
    float cantidadRegular;
    float cantidadPremium;
    float cantidadEcoExtra;
public:
    // Constructor por defecto
    Tanque()
        : capacidadRegular(0), capacidadPremium(0), capacidadEcoExtra(0),
          cantidadRegular(0), cantidadPremium(0), cantidadEcoExtra(0) {}

    // Constructor con parámetros
    Tanque(float capReg, float capPrem, float capEco)
        : capacidadRegular(capReg), capacidadPremium(capPrem), capacidadEcoExtra(capEco),
          cantidadRegular(0), cantidadPremium(0), cantidadEcoExtra(0) {}


    // gets
    float getCantidadRegular() const { return cantidadRegular; }
    float getCantidadPremium() const { return cantidadPremium; }
    float getCantidadEcoExtra() const { return cantidadEcoExtra; }
    float getCapacidadRegular() const { return capacidadRegular; }
    float getCapacidadPremium() const { return capacidadPremium; }
    float getCapacidadEcoExtra() const { return capacidadEcoExtra; }

    //Metodo para vender combistuble
    float venderCombustible(float cantidad, const string& categoria){
        float cantidadVendida=0.0;
        if (categoria=="Regular"){
            if (cantidad<=cantidadRegular){
                cantidadRegular -= cantidad;
                cantidadVendida = cantidad;
            }
            else {
                cantidadVendida=cantidadRegular;//En caso de que se pida una cantidad mayor a la cantidad almacenada
                cantidadRegular=0;
            }

        }
        else if (categoria == "Premium") {
            if (cantidad <= cantidadPremium) {
                cantidadPremium -= cantidad; 
                cantidadVendida = cantidad;    
            } else {
                cantidadVendida = cantidadPremium;
                cantidadPremium = 0; 
            }
        } 
        else if (categoria == "EcoExtra") {
            if (cantidad <= cantidadEcoExtra) {
                cantidadEcoExtra -= cantidad; 
                cantidadVendida = cantidad;    
            } else {
                cantidadVendida = cantidadEcoExtra;
                cantidadEcoExtra = 0; 
            }
        } 
        else {
            cout << "Categoría de combustible no válida." << endl;
        }

        return cantidadVendida;
    }
    // Metodo para llenar el tanque 
    void llenarTanque(const string& categoria, float cantidad) {
        if (categoria == "Regular") {
            if (cantidadRegular + cantidad <= capacidadRegular) {
                cantidadRegular += cantidad; // Aumenta la cantidad de combustible regular
            } else {
                cantidadRegular = capacidadRegular; // Rellena hasta la capacidad máxima
            }
        } 
        else if (categoria == "Premium") {
            if (cantidadPremium + cantidad <= capacidadPremium) {
                cantidadPremium += cantidad; 
            } else {
                cantidadPremium = capacidadPremium; 
            }
        } 
        else if (categoria == "EcoExtra") {
            if (cantidadEcoExtra + cantidad <= capacidadEcoExtra) {
                cantidadEcoExtra += cantidad; 
            } else {
                cantidadEcoExtra = capacidadEcoExtra; 
            }
        } 
        else {
            cout << "Categoría de combustible no válida." << endl;
        }
    }

};