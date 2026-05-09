#include <iostream>
#include "Controlador/Controlador.h"
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    int opcion = 0;
    cout << "1. Ejecutar el programa sin poda. " << endl;
    cout << "2. Ejecutar el programa con poda. " << endl;
    cout << "3. Generar Datos aleatorios." << endl;
    cout << "4. Generar Tiempos de los Casos con poda y sin poda." << endl;

    cout << "Escoge opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            cout << "Ejecutando programa sin poda... " << endl;
            Controlador::print_solucion_sin_poda();
            break;
        }
        case 2: {
            cout << "Ejecutando programa con poda... " << endl;
            Controlador::print_solucion_con_poda();
            break;
        }
        case 3: {
            cout << "Generando Casos Aleatorios..." << endl;
            int n = rand() % 100;
            int m = rand() % 10;
            Controlador::generar_caso(n,m);
            break;
        }
        case 4: {
            cout << "Generando Tiempos..." << endl;
            Controlador::crear_tabla_tiempos();
            break;
        }
        default:
            cout << "Opcion no valida!" << endl;
    }
    return 0;
}