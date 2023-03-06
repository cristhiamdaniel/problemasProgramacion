//
// Created by cristhiamdaniel
// Tema: Punteros
// Problema 5 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir una función que tenga como entrada una
 * cadena de caracteres en la que se introducen distintos
 * números reales separados por blancos y devuelva un
 * array de números reales (por ejemplo la cadena “25.56 23.4”
 * se ha de convertir en los correspondientes valore reales y retornarlos en un vector).
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

double *convertirCadena(char *cadena) {
    // Contamos la cantidad de numeros en la cadena
    int cantidadNumeros = 0;
    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] == ' ') {
            cantidadNumeros++;
        }
    }
    cantidadNumeros++;

    // Creamos el array de numeros
    double *numeros = new double[cantidadNumeros];

    // Convertimos los numeros
    char *token = strtok(cadena, " ");
    int i = 0;
    while (token != NULL) {
        numeros[i] = atof(token);
        token = strtok(NULL, " ");
        i++;
    }

    return numeros;
}

int main() {
    char cadena[100];
    cout << "Ingrese una cadena de numeros: ";
    cin.getline(cadena, 100);

    double *numeros = convertirCadena(cadena);

    cout << "Los numeros son: ";
    for (int i = 0; i < 2; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    delete[] numeros;

    return 0;
}