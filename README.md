# Prácticas de Algoritmos: Backtracking y Avance Rápido

## Descripción general

Este repositorio contiene dos implementaciones de algoritmos fundamentales de optimización y búsqueda:

- **Backtracking**, con versión sin optimizar y versión con poda.
- **Avance Rápido**

El objetivo principal del proyecto es **comparar enfoques algorítmicos, medir su rendimiento y estudiar su comportamiento ante distintos tamaños de entrada**.

---

## Compilar el proyecto

```bash
make 
```

### ¿Qué hace este comando?

- Compila todos los archivos `.cpp`
- Genera los archivos objeto `.o` en la carpeta `Compilacion`
- Enlaza todos los objetos
- Genera el ejecutable final

---

## Ejecutar el programa

```bash
make run
```

Este comando ejecuta el programa principal.

Al iniciarse, aparecerá un menú interactivo dependiendo del módulo (Backtracking o Avance Rápido).

---

## Limpiar el proyecto

```bash
make clean
```

Elimina:
- Archivos objeto (`*.o`)
- Ejecutable (`a.out`)

Permite dejar el proyecto listo para una recompilación desde cero.

---

# Backtracking

## Descripción

Este módulo implementa el algoritmo de **Backtracking** en dos versiones:

- Sin **poda** (exploración completa)
- Con **poda**

El objetivo es comparar el rendimiento entre ambas aproximaciones.

---
## Menú del programa

```text
1. Ejecutar el programa sin poda.
2. Ejecutar el programa con poda.
3. Generar Datos aleatorios.
4. Generar Tiempos de los Casos con poda y sin poda.
```

---

## Opciones del menú

### Sin poda

Ejecuta la versión clásica del algoritmo, por tanto explora todo el espacio de soluciones.

### Con poda

Ejecuta la versión con poda, por tanto reduce el espacio de soluciones eliminando caminos innecesarios.

### Generar datos aleatorios

Genera casos de prueba automáticamente:

```cpp
int n = rand() % 100;
int m = rand() % 10;
```

Permite probar el algoritmo con entradas variadas.

### Análisis de tiempos

Genera tablas comparativas de rendimiento:

- Backtracking sin poda
- Backtracking con poda

Permite analizar mejoras en tiempo de ejecución.

---
## Estructura del módulo Backtracking

```text
Algoritmo/
├── Backtracking.cpp
├── Backtracking.h

Controlador/
├── Controlador.cpp
├── Controlador.h

Compilacion/
├── *.o
├── a.out

main.cpp
Makefile
```

---

# Avance Rápido

## Descripción

Este módulo implementa un algoritmo de **Avance Rápido**, con herramientas de:

- Generación de datos
- Ejecución del algoritmo
- Análisis de rendimiento

---
## Menú del programa

```text
1. Ejecutar el programa.
2. Generar Datos aleatorios fijando n.
3. Generar Datos aleatorios fijando m.
4. Generar Tiempos de los Casos.
```

---

## Opciones del menú

### Ejecutar el programa

Ejecuta el algoritmo principal.

- Procesa datos de entrada
- Permite observar el comportamiento general

### Generar datos fijando n

Genera casos aleatorios manteniendo fijo **n**.

- Estudia variaciones del resto de parámetros
- Útil para análisis controlado

### Generar datos fijando m

Genera casos aleatorios manteniendo fijo **m**.

- Permite comparar configuraciones
- Complementa el análisis experimental

### Análisis de tiempos

Mide el rendimiento del algoritmo.

- Calcula tiempos de ejecución
- Analiza escalabilidad
- Genera comparativas experimentales

---
## Estructura del módulo Avance Rápido

```text
Algoritmo/
├── AvanceRapido.cpp
├── AvanceRapido.h

Controlador/
├── Controlador.cpp
├── Controlador.h
├── InputOuput.cpp
├── InputOuput.h

Compilacion/
├── *.o
├── a.out

main.cpp
Makefile
```
