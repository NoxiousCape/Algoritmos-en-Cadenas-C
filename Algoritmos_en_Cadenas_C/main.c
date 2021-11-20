#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TAM 50

void contarVocales();

void pasarANombrePropio();

void buscarCadena();

void anioNuevo();

void removerCaracteres();

char llenar_caracteres();

int interseccion();


int busqueda(const char b[], int llave, int tamanio);

int cantPalabrasRepetidas();

int toLower(char *cadena);

int eliminarRepetidos();

void validarCorreo();

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

            case 2 :
                buscarCadena();
                break;

            case 3 :
                contarVocales();
                break;

            case 4 :
                anioNuevo();
                break;

            case 5 :
                llenar_caracteres();
                break;

            case 6 :
                removerCaracteres();
                break;

            case 7 :
                interseccion();
                break;

            case 8 :
                eliminarRepetidos();
                break;

            case 9 :
                cantPalabrasRepetidas();
                break;

            case 10 :
                validarCorreo();
                break;
        }

    }

    return 0;
}


void pasarANombrePropio() {

    char cadena[35];

    printf("Introduce una cadena:\n");
    getchar();
    fflush(stdin);
    gets(cadena);

    for (char *palabra = strtok(cadena, " "); palabra; palabra = strtok(NULL, " ")) {
        if (strlen(palabra) > 1) {
            palabra[0] = toupper(palabra[0]);

        }
        printf("%s ", palabra);
    }
    getchar();
}

void buscarCadena() {

    char cadena[30];
    char cadenaABuscar[30];
    int i = 0;
    int j = 0;
    int cant = 0;
    printf("Ingrese una cadena\n");
    getchar();
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
    getchar();
}

void contarVocales() {

    char palabra[30];

    printf("Ingrese una palabra:\n");
    getchar();
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
    getchar();
}

void anioNuevo() {
    char cadena[30];
    printf("Escriba una hora en formato 24 horas, por ejemplo, 15:30\n");
    fflush(stdin);
    gets(cadena);
    char *hora;
    char *min;
    int cant = 0;
    for (char *ho = strtok(cadena, ":"); ho; ho = strtok(NULL, ":")) {
        if (cant == 0) {
            hora = ho;
        }
        if (cant == 1) {
            min = ho;
        }
        cant++;
    }
    int h = strtol(hora,NULL,10);
    int m = strtol(min,NULL,10);
    int total = 1440 - ((h * 60) + m);
    printf("Faltan %d minuto(s) para media noche\n", total);
    getchar();
}

int eliminarRepetidos() {
    int x = 0;
    char frase[TAM];
    char frase_2[TAM] = {""};

    printf("Introduze una frase: ");
    getchar();
    fgets(frase, 50, stdin);

    for (int i = 0; i < 50 && frase[i] != '\n'; i++) {
        if (busqueda(frase_2, frase[i], 50) == -1) {
            frase_2[x] = frase[i];
            x++;
        }
    }
    printf("La frase SIN CARACTERES REPETIDOS es: %s\n", frase_2);
    getchar();
    return 0;
}

int busqueda(const char b[], int llave, int tamanio) {
    if (isalpha(llave)) {
        for (int i = 0; i < tamanio; ++i) {
            if (b[i] == llave) {
                return i;
            }
        }
    }
    return -1;
}

int cantPalabrasRepetidas() {

    char cadena[1000];
    char aux[strlen(cadena)];
    printf("Introduce una cadena:\n");
    getchar();
    fflush(stdin);
    gets(cadena);
    strcpy(aux, cadena);
    int nPalabras = toLower(aux);
    char tokens[nPalabras][30];
    char *token = strtok(aux, " ,.!?");

    nPalabras = 0;
    while (token != NULL) {
        strcpy(tokens[nPalabras++], token);
        token = strtok(NULL, " ,.-!?");
    }

    int contPal[nPalabras];
    int palRep = 0;
    int suma = 0;

    for (int i = 0; i < nPalabras; i++) {
        contPal[i] = 0;
    }

    for (int i = 0; i < nPalabras - 1; i++) {
        for (int j = i + 1; j < nPalabras; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0 && strcmp(tokens[i], "*") != 0) {
                strcpy(tokens[j], "*");
                contPal[palRep]++;
            }
        }

        if (strcmp(tokens[i], "*") != 0) {
            suma += contPal[palRep];
            palRep++;
        }
    }
    printf("\nEn la cadena de texto ingresada y sin contar la palabra original, hay un TOTAL de %d palabras repetidas.\n\n",
           suma);
    getchar();
}

int toLower(char *cadena) {
    int n = 0;
    for (int i = 0; i < strlen(cadena); i++) {
        cadena[i] = tolower(cadena[i]);
        if (cadena[i] == ' ') {
            n++;
        }
    }

    return n + 1;
}


void validarCorreo() {

    char email[50];
    printf("Ingrese un correo:\n");
    getchar();
    fflush(stdin);
    gets(email);

    int tam = strlen(email);
    int arroba = 0, punto = 0, antesPunto = 0, despuesPunto = 0, i;

    for (i = 0; i < tam; i++) {
        char c = email[i];
        if (c == '@') {
            if (arroba)
                break;
            arroba = 1;
            if (i < 3)
                break;
        } else if (arroba) {
            if (punto) {
                despuesPunto++;
            } else if (c == '.') {
                punto = 1;
                if (antesPunto < 3) {
                    break;
                }
            } else {
                antesPunto++;
            }
        }
    }
    if (i == tam && despuesPunto > 1)
        printf("El correo electrónico ingresado es VALIDO");
    else
        printf("ERROR en el formato del correo electrónico ingresado");

    getchar();
}

char llenar_caracteres() {
    char cadena[30];
    char caracter[30];
    int cant, opc;

    printf("cadena \n");
    scanf("%s", &cadena);
    printf("caracter a implenetar \n");
    scanf("%s", &caracter);
    printf("cantidad de veces \n");
    scanf("%d", &cant);
    printf("1. Derecha \n");
    printf("2. Izquierda \n");
    scanf("%d", &opc);

    if (opc == 1) {
        for (int i = 0; i <= cant; i++) {
            strcat(cadena, caracter);
        }
        printf("cadena: %s", cadena);


    }
    if (opc == 2) {
        for (int i = 0; i <= cant; i++) {
            strcat(cadena, caracter);
        }

        printf("cadena: %s", caracter);


    }

}

void removerCaracteres() {
    char cadena[30];
    char caracteres[30];

    printf("La cadena es: \n");
    scanf("%s", &cadena);
    printf("Y los caracteres que se quitan son: \n");
    scanf("%s", &caracteres);

    int indiceCadena = 0, indiceCadenaLimpia = 0;
    int deberiaAgregarCaracter = 1;
    while (cadena[indiceCadena]) {
        deberiaAgregarCaracter = 1;
        int indiceCaracteres = 0;
        while (caracteres[indiceCaracteres]) {
            if (cadena[indiceCadena] == caracteres[indiceCaracteres]) {
                deberiaAgregarCaracter = 0;
            }
            indiceCaracteres++;
        }
        if (deberiaAgregarCaracter) {
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }
        indiceCadena++;
    }
    cadena[indiceCadenaLimpia] = 0;
    printf("Despues de remover es: '%s'\n", cadena);
}

int interseccion() {

    char str1[100];
    char str2[100];


    printf("Primera cadena :");
    scanf("%s", &str1);


    printf("Segunda cadena :");
    scanf("%s", &str2);


    int i, j, k = 0;
    char str3[100];

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                str3[k] = str1[i];
                k++;
            }
        }
    }

    str3[k] = '\0';

    for (size_t i = 0, j = 0; str3[i] != '\0';) {
        if (str3[++i] != str3[j] && str3[i] != '\n') {
            if (i != ++j) str3[j] = str3[i];
        }
    }

    printf("\nResultado es:%s", str3);

}
