#include "InputOuput.h"

//Archivo de entrada versión extendida del problema
const string InputOuput::INPUT_FILE = "./Utils/InputOutput/Entrada_Avance_Rapido.in";
const string InputOuput::OUTPUT_FILE = "./Utils/InputOutput/Salida_Avance_Rapido.out";
const string InputOuput::TIEMPOS_FILE = "./Utils/tiempos.txt";

long long InputOuput::coeficiente_binomial(const int n, int k) {
    if (k > n - k) k = n - k;

    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}

vector<AvanceRapido::Caso> InputOuput::leer_entrada() {
    ifstream archivo (INPUT_FILE);
    vector<AvanceRapido::Caso> casos;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << INPUT_FILE << "\n";
        return casos;
    }

    //Lee el número de casos de prueba
    int T;
    archivo >> T;
    casos.reserve(T);

    for (int t = 0; t < T; t++) {
        AvanceRapido::Caso caso;
        archivo >> caso.n >> caso.m;
        int n = caso.n;

        vector distancias(n, vector<int>(n));
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                archivo >> distancias[j][k];

        //Reservamos el número de aristas diferentes para n nodos (simplificando desde i a j , j a i en una sola arista)
        //El motivo de usar el coeficiente binomial es para calcular de cuantas maneras diferentes puedo agrupar n nodos
        //en grupos de 2, de esta manera sé de antemanos cuál es el número de aristas al simplificar el grafo
        vector<AvanceRapido::Arista> aristas(coeficiente_binomial(n,2));
        vector<int> suma_total_distancias(n);
        //Creamos todas las combinaciones de aristas con sus distancias sumadas
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                AvanceRapido::Arista arista;
                arista.A = i;
                arista.B = j;
                arista.distancia_total = distancias[i][j] + distancias[j][i];
                int distancia_aux = arista.distancia_total;

                //Insertamos la distancia total máxima que encontremos por el principio siempre.
                if (!aristas.empty() && distancia_aux > aristas.front().distancia_total)
                    aristas.insert(aristas.begin(), arista);
                else
                    aristas.push_back(arista);

                suma_total_distancias[i] += distancia_aux;
                suma_total_distancias[j] += distancia_aux;
            }
        }

        caso.aristas = aristas;
        caso.suma_total_distancias = suma_total_distancias;

        //Insertamos caso de prueba
        casos.push_back(move(caso));
    }

    //Cerramos conexión con el archivo que hemos leido
    archivo.close();
    //Devolvemos todos los casos de prueba
    return casos;
}
