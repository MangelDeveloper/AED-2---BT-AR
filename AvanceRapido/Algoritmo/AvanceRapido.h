#ifndef BACKTRACKING_AVANCERAPIDO_ALGORITMO_H
#define BACKTRACKING_AVANCERAPIDO_ALGORITMO_H

#include <optional>
#include <vector>
#include <limits>
#include <unordered_set>

using namespace std;

class AvanceRapido {
    public:
        struct Resultado {
            int resultado;
            vector<int> nodos_resultados;
        };

        struct Arista {
            int A;
            int B;
            int distancia_total;
        };

        struct Caso {
            int n;
            int m;
            vector<Arista> aristas;
            vector<int> suma_total_distancias;
        };

        static Resultado avance_rapido(Caso caso);


    private:


};

#endif