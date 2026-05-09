#include "AvanceRapido.h"

#include <set>
AvanceRapido::Resultado AvanceRapido::avance_rapido(Caso caso) {
    int n = caso.n;
    int m = caso.m;
    int max_distancia_total = 0;

    vector<Arista> aristas = caso.aristas;
    vector<int> suma_total_distancias = caso.suma_total_distancias;

    Resultado resultado;
    vector nodos_resultado(n, 0);
    set<int> nodos;

    // Elegir nodo inicial
    int nodo_A = 0;
    int suma_max = suma_total_distancias[nodo_A];

    for (int i = 1; i < n; i++) {
        if (suma_total_distancias[i] > suma_max) {
            nodo_A = i;
            suma_max = suma_total_distancias[i];
        }
    }

    nodos.insert(nodo_A);
    nodos_resultado[nodo_A] = 1;

    // Vector de contribuciones
    vector contribucion(n, 0);

    // Inicializar contribuciones respecto a nodo_A
    for (const auto& arista : aristas) {
        if (arista.A == nodo_A)
            contribucion[arista.B] += arista.distancia_total;
        else if (arista.B == nodo_A)
            contribucion[arista.A] += arista.distancia_total;
    }

    // Construcción voraz
    for (int nodos_por_elegir = m - 1; nodos_por_elegir > 0; nodos_por_elegir--) {

        int mejor_nodo = -1;
        int mejor_valor = std::numeric_limits<int>::min();

        for (int candidato = 0; candidato < n; candidato++) {
            if (nodos.find(candidato) != nodos.end()) continue;

            if (contribucion[candidato] > mejor_valor) {
                mejor_valor = contribucion[candidato];
                mejor_nodo = candidato;
            }
        }

        // Añadir nodo elegido
        nodos.insert(mejor_nodo);
        nodos_resultado[mejor_nodo] = 1;
        max_distancia_total += mejor_valor;

        // Actualizar contribuciones
        for (const auto& arista : aristas) {
            if (arista.A == mejor_nodo)
                contribucion[arista.B] += arista.distancia_total;
            else if (arista.B == mejor_nodo)
                contribucion[arista.A] += arista.distancia_total;
        }
    }

    resultado.resultado = max_distancia_total;
    resultado.nodos_resultados = nodos_resultado;
    return resultado;
}