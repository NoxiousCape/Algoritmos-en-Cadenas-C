#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<conio.h>

void contarVocales();

void pasarANombrePropio();

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

            case 2 :;
                break;

            case 3 :

                contarVocales();

                break;

            case 4 :;
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

    char palabra1;

    printf("Introduce una cadena:\n");

    int i = 0;

    char cadena1;

    int cont = 0;

    scanf("%s", &cadena);

    cadena1 += cadena1 + ' ';

    if (strlen((const char *) &cadena) > 2) {

        cont++;

        cadena[i] = toupper(cadena[i]);

    }

    printf("%d", cont);
    while (cadena[i] != '\0') {

        printf("%c", cadena[i]);

        i++;
    }

}

void contarVocales() {

    char palabra[30];

    printf("Ingrese una palabra:\n");

    fflush(stdin);

    gets(palabra);

    int cant = 0;
    int x = 0;

    while (palabra[x] != '\0') {

        if (palabra[x] == 'a' || palabra[x] == 'e' || palabra[x] == 'i' || palabra[x] == 'o' ||
            palabra[x] == 'u') {
            cant++;
        }
        x++;
    }
    printf("La cantidad de vocales que tiene la palabra '%s' es %i\n", palabra, cant);

}
