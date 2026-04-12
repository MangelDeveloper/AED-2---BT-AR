#include <iostream>
#include "Controlador/Controlador.h"
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    //Controlador::print_solucion_con_poda();
    //Controlador::print_solucion_sin_poda();
    srand(time(NULL));
    Controlador::crear_tabla_tiempos();

    return 0;
}