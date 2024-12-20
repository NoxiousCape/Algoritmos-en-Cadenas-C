# Manipulación de Cadenas en C

Programa en C que implementa diferentes funciones para manipular cadenas de caracteres, incluyendo operaciones como conversión de texto, búsqueda, conteo y validación.

## Características

El programa ofrece un menú interactivo con las siguientes funcionalidades:

1. Conversión a nombre propio
2. Búsqueda de cadenas
3. Conteo de vocales
4. Cálculo de minutos hasta año nuevo
5. Llenado de caracteres
6. Borrado de caracteres
7. Intersección de cadenas
8. Eliminación de caracteres repetidos
9. Conteo de palabras repetidas
10. Validación de correo electrónico

## Requisitos

- Compilador de C (GCC recomendado)
- Biblioteca estándar de C
- Sistema operativo compatible (Windows/Linux/Mac)

## Estructura del Programa

```c
├── main.c           # Archivo principal con todas las funciones
├── Funciones:
    ├── pasarANombrePropio()
    ├── buscarCadena()
    ├── contarVocales()
    ├── anioNuevo()
    ├── llenar_caracteres()
    ├── removerCaracteres()
    ├── interseccion()
    ├── eliminarRepetidos()
    ├── cantPalabrasRepetidas()
    └── validarCorreo()
```

## Compilación y Ejecución

Para compilar el programa:

```bash
gcc main.c -o string_manipulator
```

Para ejecutar:

```bash
./string_manipulator
```

## Descripción de Funciones

### 1. pasarANombrePropio()
Convierte una cadena de texto a formato de nombre propio (primera letra de cada palabra en mayúscula).

### 2. buscarCadena()
Busca una subcadena dentro de una cadena principal y cuenta las ocurrencias.

### 3. contarVocales()
Cuenta la cantidad de vocales en una palabra o frase.

### 4. anioNuevo()
Calcula los minutos restantes hasta la medianoche basado en una hora ingresada en formato 24 horas.

### 5. llenar_caracteres()
Rellena una cadena con caracteres específicos a la izquierda o derecha.

### 6. removerCaracteres()
Elimina caracteres específicos de una cadena.

### 7. interseccion()
Encuentra los caracteres comunes entre dos cadenas.

### 8. eliminarRepetidos()
Elimina caracteres repetidos en una cadena.

### 9. cantPalabrasRepetidas()
Cuenta la cantidad de palabras que se repiten en un texto.

### 10. validarCorreo()
Verifica si una dirección de correo electrónico tiene un formato válido.

## Uso del Programa

1. Ejecute el programa
2. Seleccione una opción del menú (1-11)
3. Siga las instrucciones en pantalla para cada función
4. Use la opción 11 para salir del programa

## Limitaciones

- Tamaño máximo de cadenas: 50 caracteres (definido por TAM)
- Las funciones de entrada utilizan `gets()` y `scanf()`, que pueden ser vulnerables a desbordamiento de buffer
- El programa no maneja caracteres especiales o Unicode

## Mejoras Futuras Sugeridas

1. Implementar manejo seguro de cadenas
2. Agregar validación de entrada más robusta
3. Aumentar el límite de caracteres
4. Mejorar el manejo de memoria
5. Agregar soporte para caracteres Unicode

## Contribución

Para contribuir al proyecto:

1. Fork del repositorio
2. Crear una rama para nuevas características
3. Commit de cambios
4. Push a la rama
5. Crear Pull Request

## Notas

- El programa utiliza funciones de la biblioteca estándar de C
- Se recomienda compilar con las banderas de advertencia activadas: `-Wall -Wextra`
