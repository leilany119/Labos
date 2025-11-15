#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int convertirFecha(string fecha) {
    int dia = (fecha[0] - '0') * 10 + (fecha[1] - '0');
    int mes = (fecha[3] - '0') * 10 + (fecha[4] - '0');
    int anio = (fecha[6] - '0') * 1000 +
               (fecha[7] - '0') * 100 +
               (fecha[8] - '0') * 10 +
               (fecha[9] - '0');

    return anio * 10000 + mes * 100 + dia;
}

void comprasDeCliente(string codigoBuscado) {
    ifstream archivo("compras.txt");
    string codigo, fecha;
    float monto;

    int contador = 0;
    float suma = 0;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.";
        return;
    }

    while (archivo >> codigo >> fecha >> monto) {
        if (codigo == codigoBuscado) {
            contador++;
            suma += monto;
        }
    }

    archivo.close();

    if (contador == 0)
     {
        cout << "No hay compras para ese cliente.";
    } else {
        cout << "Cantidad de compras: " << contador << endl;
        cout << "Promedio: " << (suma / contador) << endl;
    }
}


void comprasEntreFechas(string f1, string f2) {
    ifstream archivo("compras.txt");
    string codigo, fecha;
    float monto;

    int fecha1 = convertirFecha(f1);
    int fecha2 = convertirFecha(f2);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.";
        return;
    }

    cout << "Compras registradas entre " << f1 << " y " << f2 << ": ";

    while (archivo >> codigo >> fecha >> monto) {
        int f = convertirFecha(fecha);

        if (f >= fecha1 && f <= fecha2) {
            cout << codigo << " " << fecha << " $" << monto << endl;
        }
    }

    archivo.close();
}

void comprasClienteFechas(string codigoBuscado, string f1, string f2) {
    ifstream archivo("compras.txt");
    string codigo, fecha;
    float monto;

    int fecha1 = convertirFecha(f1);
    int fecha2 = convertirFecha(f2);

    if (!archivo.is_open())
     {
        cout << "No se pudo abrir el archivo.";
        return;
    }

    cout << "Compras del cliente " << codigoBuscado 
         << " entre " << f1 << " y " << f2 << ":";

    while (archivo >> codigo >> fecha >> monto) {
        int f = convertirFecha(fecha);

        if (codigo == codigoBuscado && f >= fecha1 && f <= fecha2) {
            cout << codigo << " " << fecha << " $" << monto << endl;
        }
    }

    archivo.close();
}

int main() {
    string codigo, f1, f2;
    int opcion;

    cout << "MENU";
    cout << "1. Compras de un cliente";
    cout << "2. Compras entre dos fechas";
    cout << "3. Compras de un cliente entre dos fechas";
    cout << "Elija una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Codigo del cliente: ";
        cin >> codigo;
        comprasDeCliente(codigo);
    }
    else if (opcion == 2) {
        cout << "Fecha inicial (dd/mm/aaaa): ";
        cin >> f1;
        cout << "Fecha final (dd/mm/aaaa): ";
        cin >> f2;
        comprasEntreFechas(f1, f2);
    }
    else if (opcion == 3) {
        cout << "Codigo del cliente: ";
        cin >> codigo;
        cout << "Fecha inicial (dd/mm/aaaa): ";
        cin >> f1;
        cout << "Fecha final (dd/mm/aaaa): ";
        cin >> f2;
        comprasClienteFechas(codigo, f1, f2);
    }
    else {
        cout << "Opcion invalida.";
    }

    return 0;
}
