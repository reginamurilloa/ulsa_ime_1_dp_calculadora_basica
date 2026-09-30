// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"

int main() {
    // Variables (siempre inicializadas)
    // TODO: opcion, a, b, resultado y simbolo.
    //       ¿De qué tipo es cada una? Revisa la sección 2 de tu README.
    //       ¿Con qué valor empieza un char?
    int opcion = 0;
    double a = 0.0;
    double b = 0.0;
    double resultado = 0.0;
    char simbolo = ' ';

    // Pasos 1 y 2: título y menú
    // TODO
    
    std::cout << "Calculadora básica\n";
    std::cout << "1. Suma 2. Resta 3. Multiplicación 4. División 5. Salir\n";

    // Paso 3: leer la opción con leerEntero y repetir si no está entre 1 y 4
    // TODO: ¿qué ciclo usaste en la Práctica 3 para volver a pedir un dato?

    while (true) {
        opcion = leerEntero("Elige una opción (1-4): ");

        if (opcion == 5) {
            return 0;
        }

        if (opcion < 1 || opcion > 4) {
            std::cout << "Opción inválida. Por favor, elige entre 1 y 4.\n";
            continue;
        }

        break;
    }

    // Pasos 4 y 5: leer los dos números con leerDecimal
    a = leerDecimal("Introduce el primer número: ");
    b = leerDecimal("Introduce el segundo número: ");

    // Paso 6: SOLO si la opción es división, ¿qué haces si b es 0?
    // TODO

    if (opcion ==4) {
        while (b == 0) {
            std::cout << "Error: No se puede dividir entre cero.\n";
            b = leerDecimal("Introduce un segundo número distinto de cero: ");
        }
    }

    // Paso 7: decisión múltiple
    // TODO: switch (opcion) { case 1: ... break; ... default: ... }
    //       ¿Qué pasa si olvidas un break? (Experimento A)
    switch (opcion) {
        case 1:
            resultado = a + b;
            simbolo = '+';
            break;
        case 2:
            resultado = a - b;
            simbolo = '-';
            break;
        case 3:
            resultado = a * b;
            simbolo = '*';
            break;
        case 4:
            resultado = a / b;
            simbolo = '/';
    }


    // Paso 8: salida -> a simbolo b = resultado
    // TODO
    std::cout << a << " " << simbolo << " " << b << " = " << resultado << "\n";
    // ¿Qué significa return 0;?
    return 0;
}