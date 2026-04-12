#include "Controlador.h"

//Archivo de entrada versión extendida del problema
const string Controlador::INPUT_FILE = "../Utils/InputOutput/Entrada_Backtracking.in";
const string Controlador::TIEMPOS_FILE = "../Utils/tiempos.txt";

vector<Backtracking::Caso> Controlador::leer_entrada() {
    ifstream archivo (INPUT_FILE);
    vector<Backtracking::Caso> casos;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << INPUT_FILE << "\n";
        return casos;
    }

    //Lee el número de casos de prueba
    int N;
    archivo >> N;
    casos.reserve(N);

    for (int i = 0; i < N; i++) {
        //Leemos el presupuesto disponible (M) y el número de prendas a comprar (C)
        int M,C;
        archivo >> M >> C;

        Backtracking::Caso caso;
        caso.presupuesto = M;
        caso.num_prendas = C;

        //Creamos espacio suficiente para cada prenda
        caso.prendas.resize(C);
        for (int j = 0; j < C; j++) {
            //Leemos el número de modelos de dicha prenda (K)
            archivo >> caso.prendas[j].num_modelos;

            const int num_modelos = caso.prendas[j].num_modelos;

            //Creamos espacio suficiente para cada modelo poner su correspondiente precio
            caso.prendas[j].precios.resize(num_modelos);
            for (int k = 0; k < num_modelos; k++) {
                //Leemos los precios de cada modelo de la prenda j
                archivo >> caso.prendas[j].precios[k];
            }

            //Ordenamos los precios de mayor a menor de los modelos, para de esta manera obtener el valor máximo antes
            //Y de esta manera con la cota superior fiable podar antes.
            sort(caso.prendas[j].precios.begin(),caso.prendas[j].precios.end(),greater<int>());
        }

        //Calculamos el mínimo y máximo precio a gastar desde i hasta el final
        caso.max_restante.resize(C);
        caso.min_restante.resize(C);
        int last = C - 1;
        caso.max_restante[last] = caso.prendas[last].precios[0];
        caso.min_restante[last] = caso.prendas[last].precios.back();
        for (int k = last-1; k >= 0; k--) {
            caso.max_restante[k] = caso.prendas[k].precios[0] + caso.max_restante[k+1];
            caso.min_restante[k] = caso.prendas[k].precios.back() + caso.min_restante[k+1];
        }

        //Insertamos caso de prueba
        casos.push_back(move(caso));
    }

    //Cerramos conexión con el archivo que hemos leido
    archivo.close();
    //Devolvemos todos los casos de prueba
    return casos;
}

void Controlador::print_solucion_con_poda() {
    vector <Backtracking::Caso> casos = leer_entrada();
    auto it_casos = casos.begin();

    while (it_casos != casos.end()) {
        Backtracking::Caso caso = *it_casos;
        Backtracking::Resultado resultado = Backtracking::backtracking_con_poda(caso);

        if (resultado.voa == numeric_limits<int>::min()) cout << "no solution" << endl;
        else cout << resultado.voa << endl;

        ++it_casos;
    }
}

void Controlador::print_solucion_sin_poda() {
    vector <Backtracking::Caso> casos = leer_entrada();
    auto it_casos = casos.begin();

    while (it_casos != casos.end()) {
        Backtracking::Caso caso = *it_casos;
        Backtracking::Resultado resultado = Backtracking::backtracking_sin_poda(caso);

        if (resultado.voa == numeric_limits<int>::min()) cout << "no solution" << endl;
        else cout << resultado.voa << endl;

        ++it_casos;
    }
}

Backtracking::Caso Controlador::generar_caso(int n, int m){

    Backtracking::Caso caso;
    caso.num_prendas = n;
    caso.prendas.resize(n);

    int suma_max = 0;

    for(int i=0;i<n;i++){

        caso.prendas[i].num_modelos = m;
        caso.prendas[i].precios.resize(m);

        for(int j=0;j<m;j++){
            caso.prendas[i].precios[j] = rand()%200 + 1;
        }

        // ordenar de mayor a menor (como en leer_entrada)
        sort(caso.prendas[i].precios.begin(),caso.prendas[i].precios.end(),greater<int>());

        suma_max += caso.prendas[i].precios[0];
    }

    // Presupuesto cercano al valor máximo
    caso.presupuesto = suma_max - (rand()% (n * 10));

    caso.max_restante.resize(n);
    caso.min_restante.resize(n);

    int last = n-1;
    caso.max_restante[last] = caso.prendas[last].precios[0];
    caso.min_restante[last] = caso.prendas[last].precios.back();

    for(int k = last-1; k >= 0; k--){
        caso.max_restante[k] = caso.prendas[k].precios[0] + caso.max_restante[k+1];
        caso.min_restante[k] = caso.prendas[k].precios.back() + caso.min_restante[k+1];
    }

    return caso;
}

double Controlador::medir_tiempo_sin_poda(Backtracking::Caso &caso) {
    auto inicio = high_resolution_clock::now();
    Backtracking::backtracking_sin_poda(caso);
    auto fin = high_resolution_clock::now();

    return duration<double>(fin - inicio).count();
}

double Controlador::medir_tiempo_con_poda(Backtracking::Caso &caso) {
    auto inicio = high_resolution_clock::now();
    Backtracking::backtracking_con_poda(caso);
    auto fin = high_resolution_clock::now();

    return duration<double>(fin - inicio).count();
}

double Controlador::calcular_mediana(vector<double> &tiempos) {
    sort(tiempos.begin(),tiempos.end());
    return tiempos[tiempos.size()/2];
}

void Controlador::crear_tabla_tiempos() {
    ofstream f(TIEMPOS_FILE);

    f << fixed << setprecision(8);

    for(int n=2; n<=16; n+=2){

        vector<double> tiempos_sin_poda;
        vector<double> tiempos_con_poda;

        for(int i=0;i<5;i++){
            Backtracking::Caso caso = generar_caso(n,4);

            tiempos_sin_poda.push_back(medir_tiempo_sin_poda(caso));
            tiempos_con_poda.push_back(medir_tiempo_con_poda(caso));
        }

        double mediana_sin_poda = calcular_mediana(tiempos_sin_poda);
        double mediana_con_poda = calcular_mediana(tiempos_con_poda);

        f << n << " " << mediana_sin_poda << " " << mediana_con_poda << endl;
    }
}
