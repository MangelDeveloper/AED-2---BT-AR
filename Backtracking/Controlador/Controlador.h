#ifndef BACKTRACKING_AVANCERAPIDO_CONTROLADOR_H
#define BACKTRACKING_AVANCERAPIDO_CONTROLADOR_H

#include "../Algoritmo/Backtracking.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class Controlador {
public:
    //Archivo de entrada versión extendida
    static const string INPUT_FILE;
    static const string TIEMPOS_FILE;

    static vector<Backtracking::Caso> leer_entrada();
    static void print_solucion_con_poda();
    static void print_solucion_sin_poda();
    static Backtracking::Caso generar_caso(int n, int m);
    static double medir_tiempo_sin_poda(Backtracking::Caso &caso);
    static double medir_tiempo_con_poda(Backtracking::Caso &caso);
    static double calcular_mediana(vector<double> &tiempos);
    static void crear_tabla_tiempos();
};

#endif