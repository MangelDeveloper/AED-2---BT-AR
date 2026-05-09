
#ifndef AVANCERAPIDO_CONTROLADOR_H
#define AVANCERAPIDO_CONTROLADOR_H

#include "./InputOuput.h"
#include <chrono>
#include <cmath>

using namespace std::chrono;

class Controlador {

public:
    static void ejecutar_programa();
    static void generar_datos(bool n);
    static void test_tiempo();
};


#endif //AVANCERAPIDO_CONTROLADOR_H