#include <iostream>
#include <fstream>

using namespace std;

void clasificarNumeros();
void ordenarArchivo(const string& nombreArchivo);
void mostrarArchivo(const string& nombreArchivo);

int main()
{
    int opcion;

    do {
        cout << endl << "CLASIFICADOR NUMERICO"  << endl;
        cout << "1. Clasificar numeros en pares e impares " << endl;
        cout << "2. Ordenar archivos" << endl;
        cout << "3. Ver resultados" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                clasificarNumeros();
                break;

            case 2:
                ordenarArchivo("Numpares.txt");
                ordenarArchivo("Numimpares.txt");
                cout << endl << "Los archivos han sido ordenados." << endl;
                break;

            case 3:
                cout << endl << "MOSTRANDO CONTENIDO DE LOS ARCHIVOS:" << endl;

                cout << endl << " datos.txt " << endl;
                mostrarArchivo("datos.txt");

                cout << endl << " Numpares.txt " << endl;
                mostrarArchivo("Numpares.txt");

                cout << endl << " Numimpares.txt " << endl;
                mostrarArchivo("Numimpares.txt");
                break;

            case 4:
                cout << endl << "Saliendo del programa..." << endl;
                break;

            default:
                cout << endl << "Opcion invalida, intente de nuevo." << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}

void clasificarNumeros() {

    ifstream archivo("datos.txt");
    ofstream pares("Numpares.txt");
    ofstream impares("Numimpares.txt");

    cout << endl << "Clasificando numeros..." << endl;

    if (!archivo) {
        cout << "No se pudo abrir datos.txt" << endl;
        return;
    }

    int num;
    while (archivo >> num) {
        if (num % 2 == 0)
            pares << num << endl;
        else
            impares << num << endl;
    }

    cout << "Clasificacion completa." << endl;

    archivo.close();
    pares.close();
    impares.close();

    cout << endl << "Numeros pares: " << endl;
    mostrarArchivo("Numpares.txt");

    cout << endl << "Numeros impares: " << endl;
    mostrarArchivo("Numimpares.txt");
}


void ordenarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int arreglo[200], n = 0;

    if (!archivo) {
        cout << "No se pudo abrir " << nombreArchivo << endl;
        return;
    }

    while (archivo >> arreglo[n]) {
        n++;
    }
    archivo.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

    ofstream salida(nombreArchivo);
    for (int i = 0; i < n; i++) {
        salida << arreglo[i] << endl;
    }

    salida.close();
}

void mostrarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int dato;

    if (!archivo) {
        cout << "No se pudo abrir " << nombreArchivo << endl;
        return;
    }

    while (archivo >> dato) {
        cout << dato << " ";
    }

    archivo.close();
    cout << endl;
}