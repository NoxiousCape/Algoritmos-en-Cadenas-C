#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void contarVocales();

void pasarANombrePropio();

void buscarCadena();

void anioNuevo();

int main() {

    int option = 0;

    char *menu = "\nHola!, digite una opcion:\n\n"
                 "1. Conversion en nombre propio\n"
                 "2. Buscar cadena de caracteres\n"
                 "3. Contar vocales\n"
                 "4. Anio nuevo\n"
                 "5. Llenar caracteres\n"
                 "6. Borrar caracteres\n"
                 "7. Intersección\n"
                 "8. Eliminar repetidos\n"
                 "9. Contar palabras\n"
                 "10.Validar direccion de correo\n\n"
                 "11. Salir\n";

    while (toupper(option) != 11) {

        printf(menu);

        scanf("%d", &option);

        switch (option) {

            case 1 :

                pasarANombrePropio();

                break;

            case 2 :;

                buscarCadena();

                break;

            case 3 :

                contarVocales();

                break;

            case 4 :

                anioNuevo();

                break;

            case 5 :;
                break;

            case 6 :;
                break;

            case 7 :;
                break;

            case 8 :;
                break;

            case 9 :;
                break;

            case 10 :

                break;
        }

    }

    return 0;
}

void pasarANombrePropio() {

    char cadena[35];

    printf("Introduce una cadena:\n");

    fflush(stdin);

    gets(cadena);

    for (char *palabra = strtok(cadena, " "); palabra; palabra = strtok(NULL, " ")) {

        if (strlen(palabra) > 1) {

            palabra[0] = toupper(palabra[0]);

        }

        printf("%s ", palabra);

    }
}

void buscarCadena() {

    char cadena[30];

    char cadenaABuscar[30];

    int i = 0;

    int j = 0;

    int cant = 0;

    printf("Ingrese una cadena\n");

    fflush(stdin);

    gets(cadena);

    printf("Ingrese la cadena que desea buscar\n");

    fflush(stdin);

    gets(cadenaABuscar);

    while (cadenaABuscar[i] != '\0') {

        cadenaABuscar[i] = tolower(cadenaABuscar[i]);

        i++;
    }

    while (cadena[j] != '\0') {

        cadena[j] = tolower(cadena[j]);

        j++;
    }

    for (char *palabra = strtok(cadena, " "); palabra; palabra = strtok(NULL, " ")) {

        if (strstr(cadena, palabra) != NULL) {

            cant++;
        }
    }

    printf("La cantidad de veces que se repite la palabra '%s' es %i\n", cadenaABuscar, cant);

}

void contarVocales() {

    char palabra[30];

    printf("Ingrese una palabra:\n");

    fflush(stdin);

    gets(palabra);

    int cant = 0;
    int i = 0;

    while (palabra[i] != '\0') {

        if (tolower(palabra[i]) == 'a' || tolower(palabra[i]) == 'e' || tolower(palabra[i]) == 'i' ||
            tolower(palabra[i]) == 'o' ||
            tolower(palabra[i]) == 'u') {

            cant++;
        }
        i++;
    }

    printf("La cantidad de vocales que tiene la palabra '%s' es %i\n", palabra, cant);
}

void anioNuevo() {

    time_t tiempo;

    time(&tiempo);

    struct tm *mitiempo = localtime(&tiempo);

    int tiempoTranscurridoMin = (mitiempo->tm_hour * 60) + mitiempo->tm_min;

    int tiempoFaltanteMin = 1440 - tiempoTranscurridoMin;

    int tiempoTranscurridoSec = (mitiempo->tm_hour * 3600) + mitiempo->tm_sec;

    int tiempoFaltanteSec = 86400 - tiempoTranscurridoSec;

    printf("Faltan %d minuto(s) y %d segundo(s) para media noche\n", tiempoFaltanteMin, tiempoFaltanteSec);

}
