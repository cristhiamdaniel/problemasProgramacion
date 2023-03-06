//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 4 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir un programa que lea una colección de cadenas de caracteres de longitud arbitraria.
 * Por cada cadena leída, su programas hará lo siguiente:
 * a) Visualizar la longitud de la cadena.
 * b) Contar el número de ocurrencia de palabras de cuatro letras.
 * c) Sustituir cada palabra de cuatro letras por una cadena de cuatro asteriscos e imprimir la nueva cadena.

 */

#include <iostream>

using namespace std;

int main() {
    const int MAX_CADENAS = 100;
    const int MAX_LONGITUD = 100;

    char cadenas[MAX_CADENAS][MAX_LONGITUD];

    // Leer las cadenas de entrada
    int num_cadenas = 0;
    while (num_cadenas < MAX_CADENAS && cin.getline(cadenas[num_cadenas], MAX_LONGITUD)) {
        num_cadenas++;
    }

    // Procesar cada cadena
    for (int i = 0; i < num_cadenas; i++) {
        // Visualizar la longitud de la cadena
        int longitud = 0;
        while (cadenas[i][longitud] != '\0') {
            longitud++;
        }
        cout << "Longitud de la cadena: " << longitud << endl;

        // Contar el número de palabras de cuatro letras
        int contador = 0;
        for (int j = 0; j < longitud; j++) {
            if (isalpha(cadenas[i][j])) {
                int k = j + 1;
                while (k < longitud && isalpha(cadenas[i][k])) {
                    k++;
                }
                if (k - j == 4) {
                    contador++;
                    for (int l = j; l < k; l++) {
                        cadenas[i][l] = '*';
                    }
                }
                j = k;
            }
        }
        cout << "Número de palabras de cuatro letras: " << contador << endl;

        // Sustituir las palabras de cuatro letras por ****
        cout << "Cadena modificada: " << cadenas[i] << endl;
    }

    return 0;
}
