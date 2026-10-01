# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con una división donde primero escribes 0 como segundo número. -->

```
Elige una opción (1-4): 4
Introduce el primer número: 12
Introduce el segundo número: 0
Error: No se puede dividir entre cero. 
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | std::cout << "Calculadora básica\n";
    std::cout << "1. Suma 2. Resta 3. Multiplicación 4. División 5. Salir\n"; |

| 3. Leer y validar la opción |  while (true) {
        opcion = leerEntero("Elige una opción (1-4): ");

        if (opcion == 5) {
            return 0;
        }

        if (opcion < 1 || opcion > 4) {
            std::cout << "Opción inválida. Por favor, elige entre 1 y 4.\n";
            continue;
        }

        break;
    } |
| 4 y 5. Leer `a` y `b` | a = leerDecimal("Introduce el primer número: ");
    b = leerDecimal("Introduce el segundo número: "); |

| 6. Validar el divisor | if (opcion ==4) {
        while (b == 0) {
            std::cout << "Error: No se puede dividir entre cero.\n";
            b = leerDecimal("Introduce un segundo número distinto de cero: ");
        }
    } |
| 7. Decisión múltiple (un `case`) | switch (opcion) 
        case 1:
            resultado = a + b;
            simbolo = '+';
            break; |

| 8. Mostrar el resultado |  std::cout << a << " " << simbolo << " " << b << " = " << resultado << "\n"; |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
El paso 3, ya que muchas veces me marcaba error en el codigo y no podia compilar

## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
Como no esta el break sigue al caso dos y no ejecuta la operación como deberia de hacerse

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
marca 5/0 = inf
no tiene sentido ya que no arroja un número, algo valido para la operación

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
7/2 da 3 descarta los decimales 

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | 8+5=13 | 13 | si
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | 3-5=-2 | -2 | si
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | 2.5 * 4 = 10 | 10 | si
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | -3 * 4 = -12 | -12 |si
| División | 4, 7, 2 | 7 / 2 = 3.5 | 7 / 2 = 3.5 | 3.5 |si
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | 0 / 5 = 0 | 0 |si
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | que primero marque error y luego te de un resultado| Error: No se puede dividir entre cero. Introduce un segundo número distinto de cero: 2 | 5 / 2 = 2.5 |si
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | 5 + 0 = 5 | 5 | si me dio resultado de la suma
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | si pongo el 5 me saca del programa y luego ya puedo volver a realizar la suma | 8 + 5 = 13  | si
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | Me dice que ponga una opción valida | me pide otra opcion y luego ya me da la suma | si
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | que ponga una opción valida  | me pide una opción valida y luego me da el resultado correcto 3 - 5 = -2 | si
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | Entrada no valida, ingresa un número | primero no valido y luego 8 + 5 = 13 |si
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | No valido, ingresar un número | Entrada no valida, escribe un número (ej 5) 8 + 5 = 13 | si
| Caso propio 1 | 4, 8, 3 | 8/3= 2.66 | me de va división correcta | 8 / 3 = 2.66667 | si
| Caso propio 2 | 2, 5, 6 | 5-6 = -1 |  realizar la resta  | 5 - 6 = -1  | si

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | el paso 3, se me complico mucho | pedi ayuda, investigue | si |


**¿Encontré algo que la receta no contemplaba? ¿Qué?**
La parte de la división agregar que no se pudiera dividir entre 0 y te pidiera otro termino


## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ninguna |  |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
A crear el codigo yo sola y usar nuevos comandos para crearlo

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
prestar más atención para crear el codigo

**¿Qué fue lo más difícil y cómo lo resolví?**
La parte de leer la opción con leerEntero y repetir si no está entre 1 y 4, como poner el codigo en esa parte


**¿Qué pregunta me quedó sin responder?**
ninguna

**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
Siento que me tarde más porque tenia que analizar más cosas ya que no sabia bien como empezar el codigo, por una parte se me hizo más facil y por otra no

**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
Alomejor no hubiera pensado que las divisiones no aceptaran el 0

## 14. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 7 a 13 (no quedan `_____`)
- [ ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 4 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom