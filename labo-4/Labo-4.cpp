#include <iostream>

using namespace std;

int main (){
 string usuario_correcto = "admin";
    string contra_correcta = "1234";
    string usuario_ingresado;
    string contra_ingresada;
    bool sesion_iniciada = false;

 while (!sesion_iniciada) {
        cout << " Inicio de Sesion " << endl;
        cout << "Usuario: ";
        cin >> usuario_ingresado;
        cout << "Contraseña: ";
        cin >> contra_ingresada;
    if (usuario_ingresado == usuario_correcto && contra_ingresada == contra_correcta) {
            sesion_iniciada = true;
            cout << "¡Inicio de sesion exitoso!" << endl;
        } else {
            cout << "Usuario o contrasena incorrectos. Intentalo de nuevo." << endl;
        }
    }
        bool salir_calculadora = false;
        while (!salir_calculadora) {
          cout << "--- Calculadora ---" << endl;
          cout << "1. Suma" << endl;
          cout << "2. Resta" << endl;
          cout << "3. Multiplicacion" << endl;
          cout << "4. Division" << endl;
          cout << "5. Salir" << endl;
          cout << "Selecciona una opcion: ";
     int opcion;
          cin >> opcion;

        if (opcion == 5) {
            salir_calculadora = true;
               cout << "Cerrando la calculadora. ¡Hasta luego!" << endl;
        } else {
            double num1, num2;
            cout << "Ingresa el primer numero: ";
            cin >> num1;
            cout << "Ingresa el segundo numero: ";
            cin >> num2;

            double resultado;

            if (opcion == 1) {
                resultado = num1 + num2;
                cout << "Resultado: " << resultado << endl;
            } else if (opcion == 2) {
                resultado = num1 - num2;
                cout << "Resultado: " << resultado << endl;
            } else if (opcion == 3) {
                resultado = num1 * num2;
                   cout << "Resultado: " << resultado << endl;
            } else if (opcion == 4) {
                if (num2 != 0) {
                    resultado = num1 / num2;
                       cout << "Resultado: " << resultado << endl;
                } else {
                         cout << "Error: Division por cero no permitida." << endl;
                }
            } else {
                     cout << "Opcion no valida." << endl;
            }
               cout << endl; 
        }
    }

    return 0;
}
