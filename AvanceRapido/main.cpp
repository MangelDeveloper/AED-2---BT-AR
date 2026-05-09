#include <iostream>

#include "Controlador/Controlador.h"
#include "Controlador/InputOuput.h"
using namespace std;

int main()
{
    int opcion = 0;
    cout << "1. Ejecutar el programa. " << endl;
    cout << "2. Generar Datos aleatorios fijando n." << endl;
    cout << "3. Generar Datos aleatorios fijando m." << endl;
    cout << "4. Generar Tiempos de los Casos." << endl;

    cout << "Escoge opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            cout << "Ejecutando programa... " << endl;
            Controlador::ejecutar_programa();
            break;
        }
        case 2: {
            cout << "Generando Casos Aleatorios..." << endl;
            Controlador::generar_datos(true);
            break;
        }
        case 3: {
            cout << "Generando Casos Aleatorios..." << endl;
            Controlador::generar_datos(false);
            break;
        }
        case 4: {
            cout << "Generando Tiempos..." << endl;
            Controlador::test_tiempo();
            break;
        }
        default:
            cout << "Opcion no valida!" << endl;
    }



    return 0;
}