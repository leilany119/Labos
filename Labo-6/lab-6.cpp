#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante estudiantes[], int cantidad);
void mostrarEstudiantes(Estudiante estudiantes[], int cantidad);
int buscarEstudiante(Estudiante estudiantes[], int cantidad, string nombre);
void modificarEstudiante(Estudiante estudiantes[], int cantidad);

int main() {
    Estudiante estudiantes[100];
    int cantidad;
    int opcion = 0;

    cout << "GESTION DE ESTUDIANTES" << endl;
    cout << "Cuantos estudiantes desea registrar? ";
    cin >> cantidad;

    while (opcion != 5) {
        cout << "MENU" << endl;
        cout << "1. Ingresar estudiantes" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            ingresarEstudiantes(estudiantes, cantidad);
        } else if (opcion == 2) {
            mostrarEstudiantes(estudiantes, cantidad);
        } else if (opcion == 3) {
            string nombreBuscado;
            cout << "Ingrese el nombre del estudiante a buscar: ";
            cin.ignore();
            getline(cin, nombreBuscado);
            int encontrado = buscarEstudiante(estudiantes, cantidad, nombreBuscado);
            if (encontrado == 1) {
                cout << "El estudiante si se encuentra en la lista." << endl;
            } else {
                cout << "El estudiante no se encuentra en la lista." << endl;
            }
        } else if (opcion == 4) {
            modificarEstudiante(estudiantes, cantidad);
        } else if (opcion == 5) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opcion no valida, intente otra vez." << endl;
        }
    }
    return 0;
}

void ingresarEstudiantes(Estudiante estudiantes[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << " Ingresando datos del estudiante " << i + 1 << " ===" << endl;
        cin.ignore();
        cout << "Nombre completo: ";
        getline(cin, estudiantes[i].nombre);
        cout << "Edad: ";
        cin >> estudiantes[i].edad;
        cin.ignore();
        cout << "Calle: ";
        getline(cin, estudiantes[i].direccion.calle);
        cout << "Numero de casa: ";
        cin >> estudiantes[i].direccion.numero;
        cin.ignore();
        cout << "Ciudad: ";
        getline(cin, estudiantes[i].direccion.ciudad);
        cout << "Ingrese las 5 calificaciones:" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }
    }
}

void mostrarEstudiantes(Estudiante estudiantes[], int cantidad) {
    cout << " LISTA DE ESTUDIANTES " << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante #" << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Direccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
        cout << "Notas: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << endl;
    }
}

int buscarEstudiante(Estudiante estudiantes[], int cantidad, string nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombre) {
            return 1;
        }
    }
    return 0;
}
//utilise ignore para que quedase mas ordenado y getline para que pueda ingresar el nombre con espacios porque al ejecutar el codigo el codigo me tiraba error
void modificarEstudiante(Estudiante estudiantes[], int cantidad) {
    string nombreModificar;
    cout << "Ingrese el nombre del estudiante a modificar: ";
    cin.ignore();
    getline(cin, nombreModificar);
    int existe = 0;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreModificar) {
            existe = 1;
            cout << " Modificando datos de " << estudiantes[i].nombre << " ===" << endl;
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;
            cin.ignore();
            cout << "Nueva calle: ";
            getline(cin, estudiantes[i].direccion.calle);
            cout << "Nuevo numero de casa: ";
            cin >> estudiantes[i].direccion.numero;
            cin.ignore();
            cout << "Nueva ciudad: ";
            getline(cin, estudiantes[i].direccion.ciudad);
            cout << "Ingrese las nuevas 5 calificaciones:" << endl;
            for (int j = 0; j < 5; j++) {
                cout << "Nota " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }
            cout << "Datos actualizados correctamente." << endl;
        }
    }
    if (existe == 0) {
        cout << "Estudiante no encontrado." << endl;
    }
}