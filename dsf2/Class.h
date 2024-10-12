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
    //calcular total de ventas
    float calcularVentasTotal() const{
        float total =0;
        for (int i=0;i<numeroTransacciones;i++){
            total+=historicoTransacciones[i].getMonto();
        }
        return total;
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
class EstacionServicio{
    string nombre;
    string codigo;
    string gerente;
    string region;
    float coordenadas[2]; //[LATITUD,LONGITUD]
    Tanque tanque;
    Surtidor surtidores[12]; //Arreglo de surtidores
    int surtidorCount; //contador de surtidores

    //constructor con parametros
    EstacionServicio(string n, string c, string g , string r, float lat, float lon, float capReg, float capPrem, float capEco )
        : nombre(n), codigo (c), gerente (g), region(r), surtidorCount(0), tanque(capReg, capPrem, capEco){
        coordenadas[0]=lat;
        coordenadas[1]=lon;
    }
     //metodo para agregar surtidores
    bool agragarSurtidor(int codigo,sting modelo){
        if (surtidorCount<12){
            surtidores[surtidorCount]=Surtidor(codigo,modelo);//establecer el surtidor
            surtidorCount++;
            return true;
        }
        cout << "No se pueden agregar mas surtidores.  "<<endl;
        return false;
    }


    //metodo para eliminar surtidor
    bool eliminarSurtidor (int codigo){
        for (int i =0;i<surtidorCount;i++){
            if (surtidores[i].getCodigo()==codigo){
                //despazar hacia izquierda
                for (int j=i;j<surtidorCount-1;j++){
                    surtidores[j]=surtidores[j+1];
                }
                surtidorCount--;
                cout << "Surtidor"<<codigo<<" eliminado."<<endl;
                return true;
            }
        }
        cout <<"Surtidor no encontrado."<<endl;
        return false;
    }


    //Metodo para calcular total de ventas
    float calcularVentasTotal() const{
        float total=0;
        for (int i=0;i<surtidorCount;i++){
            total += surtidores[i].calcularVentasTotal();//consulta total del surtidor actual
        }
        return total;
    }
    //metodo para reportar litros vendidos segun categoria
    void reportarLitrosVendidos (string categoria) const{
        float totalLitros =0;

        for (int i =0;i< surtidorCount; i++){
            for (int j=0;j<100;j++){
                if (surtidores[i].isActivo() && surtidores[i].historicoTransacciones[j].getCantidad()==categoria){
                    totalLitros+=surtidores[i].historicoTransacciones[j].getCantidad();
                }
            }
        }

        cout<< "Total litros vendidos de "<<categoria<<": "<<totalLitros<<" litros"<<endl;
    }

    //Metodo para simular una venta de combustible
    void simularVenta(float cantidadSolicitada, float precioPorLitro, const string& categoria, int documentoCliente){
        if (surtidorCount>0){
            cout<<"No hay surtidores disponibles para realizar la venta. "<<endl;
            return;
        }

        float cantidadVendida = tanque.venderCombustible(cantidadSolicitada, categoria);
        if (cantidadVendida>0){
            string fecha= "2023-10-01"; //Puede ser dinamico
            string hora ="12:00";//puede ser dinamico
            float monto=cantidadVendida*precioPorLitro;

            Transaccion nuevaTransaccion(fecha,hora,cantidadVendida,categoria,"Efectivo",documentoCliente,monto);
            surtidores[0].registrarTransaccion(nuevaTransaccion);//se registra el primer surtidor

            cout << "Venta realizada: "<<cantidadVendida<<" litros de "<< categoria<<" por " << monto<<endl;
        } else {
            cout << "No hay suficiente combustible disponible para la venta solicitada."<<endl;
        }
    }
    //historico de transacciones de cada surtidor
    void mostrarSurtidores() const{
        for(int i=0;i<surtidorCount;i++){
            cout<<"Surtidor: "<<surtidores[i].getCodigo()<<", Modelo: "<< surtidores[i].getModelo()<<endl;
            surtidores[i].mostrarHistorico();//mostrar historial de transacciones
        }
    }

};
