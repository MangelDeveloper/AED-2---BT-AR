CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

BUILD = Compilacion

CONTROLADOR_O = $(BUILD)/controladorBT.o
ALGORITMO_O = $(BUILD)/algoritmoBT.o
MAIN_O = $(BUILD)/main.o

OBJ = $(MAIN_O) $(ALGORITMO_O) $(CONTROLADOR_O)

$(BUILD)/a.out: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BUILD)/a.out

$(MAIN_O): main.cpp $(ALGORITMO_O)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(MAIN_O)

$(ALGORITMO_O): Algoritmo/Backtracking.cpp Algoritmo/Backtracking.h Controlador/Controlador.h
	$(CXX) $(CXXFLAGS) -c Algoritmo/Backtracking.cpp -o $(ALGORITMO_O)

$(CONTROLADOR_O): Controlador/Controlador.cpp Controlador/Controlador.h
	$(CXX) $(CXXFLAGS) -c Controlador/Controlador.cpp -o $(CONTROLADOR_O)

run:
	$(BUILD)/a.out

clean:
	rm -f $(BUILD)/*.o $(BUILD)/a.out