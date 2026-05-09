CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

BUILD = Compilacion

CONTROLADOR_O = $(BUILD)/controladorAR.o
INOUT_O =  $(BUILD)/inputOutputAR.o
ALGORITMO_O = $(BUILD)/algoritmoAR.o
MAIN_O = $(BUILD)/main.o

OBJ = $(MAIN_O) $(ALGORITMO_O) $(INOUT_O) $(CONTROLADOR_O)

$(BUILD)/a.out: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BUILD)/a.out

$(MAIN_O): main.cpp $(CONTROLADOR_O) $(INOUT_O) $(ALGORITMO_O)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD)/main.o

$(CONTROLADOR_O): Controlador/Controlador.cpp Controlador/Controlador.h $(INOUT_O) $(ALGORITMO_O)
	$(CXX) $(CXXFLAGS) -c Controlador/Controlador.cpp -o $(BUILD)/controladorAR.o

$(INOUT_O): Controlador/InputOuput.cpp Controlador/InputOuput.h
	$(CXX) $(CXXFLAGS) -c Controlador/InputOuput.cpp -o $(BUILD)/inputOutputAR.o

$(ALGORITMO_O): Algoritmo/AvanceRapido.cpp Algoritmo/AvanceRapido.h
	$(CXX) $(CXXFLAGS) -c Algoritmo/AvanceRapido.cpp -o $(BUILD)/algoritmoAR.o

run:
	$(BUILD)/a.out

clean:
	rm -f $(BUILD)/*.o $(BUILD)/a.out