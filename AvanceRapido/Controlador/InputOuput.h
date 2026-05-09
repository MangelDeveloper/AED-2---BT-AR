#ifndef BACKTRACKING_AVANCERAPIDO_CONTROLADOR_H
#define BACKTRACKING_AVANCERAPIDO_CONTROLADOR_H

#include "../Algoritmo/AvanceRapido.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class InputOuput {
public:
    //Archivo de entrada versión extendida
    static const string INPUT_FILE;
    static const string OUTPUT_FILE;
    static const string TIEMPOS_FILE;

    static vector<AvanceRapido::Caso> leer_entrada();

private:
    static long long coeficiente_binomial(int n, int k);
};

#endif