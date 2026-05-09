#include "Controlador.h"

#define CASOS 7

void Controlador::ejecutar_programa() {
    ofstream output(InputOuput::OUTPUT_FILE);
    vector<AvanceRapido::Caso> casos = InputOuput::leer_entrada();

    for (auto i : casos) {
        AvanceRapido::Resultado res = AvanceRapido::avance_rapido(i);
        output << res.resultado << endl;
        for (auto j : res.nodos_resultados) {
            output << j << " ";
        }
        output << endl;
    }
    output.close();
}

/**
* El coste temporal depende de esta función: D(n,m).
* Por tanto para simplificar, fijamos una de las variables y estudiamos su evolución
* en el tiempo.
* En este caso establecemos por defecto
* n=1000*2^10;
*
*/
void Controlador::generar_datos(bool fijar_n) {
    srand(time(nullptr));
    ofstream inputFile(InputOuput::INPUT_FILE);

    int n=0, m=0;
    int constante_multiplicativa = 20;

    if (fijar_n) n = constante_multiplicativa*(1 << CASOS);
    else
    {
        m = 130;
        constante_multiplicativa += m;
    }

    //printf("Valor de m: %d\n",constante_multiplicativa);

    inputFile << CASOS << endl;

    for (int i = 0; i < CASOS; i++) {
        if (fijar_n) m = constante_multiplicativa*(1 << i);
        else n = constante_multiplicativa*(1 << i);

        printf("Valor de n_%d: %d\n",i,n);

        //Primera fila.
        inputFile << n;
        inputFile << " " << m;
        inputFile << endl;

        //Generacion de datos.
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < n; z++) {
             //Le ponemos 50 de maximo de manera arbitraria.
             if (j == z) inputFile << 0;
             else inputFile << rand()%50+1;

             inputFile << " ";
            }
            inputFile<< endl;
        }
    }
    inputFile.close();
}

/**
 * Esta función sirve para obtener al menos 10 datos temporales
 * por para caso ofrecido por el input.
 */
void Controlador::test_tiempo() {
    ofstream tiempoFichero(InputOuput::TIEMPOS_FILE);
    vector<AvanceRapido::Caso> listaCasos = InputOuput::leer_entrada();

    int const N_CASOS = listaCasos.size();
    //Cabecera.
    for (int i = 0; i < N_CASOS-1; i++) {
        tiempoFichero << "i" << i << ",";
    }
    tiempoFichero << "i" << N_CASOS-1 << endl;

    //Fila tiempos.
    for (int fila = 0; fila<10; fila++) {
        //Columna de cada caso.
        for (int col = 0; col < N_CASOS; col++) {

            //Simulamos y medimos los tiempos de ejecución.
            auto empezar = steady_clock::now();
            AvanceRapido::Resultado res = AvanceRapido::avance_rapido(listaCasos[col]);
            auto terminar = steady_clock::now();
            auto duracion = duration_cast<milliseconds>(terminar - empezar);

            //Obtenemos los datos en milisegundos.
            tiempoFichero << duracion.count();

            //Cerramos fila.
            if (col != N_CASOS-1) tiempoFichero  << ",";
            else tiempoFichero << endl;

        }
        cout << "Terminado fila " << fila << "." << endl;
    }

    //Cerramos el recurso.
    tiempoFichero.close();
}