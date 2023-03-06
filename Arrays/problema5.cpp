//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 5 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir un programa que lea una frase,
 * sustituya todas las secuencias de dos o
 * más blancos por un solo blanco y
 * visualice la frase restante.
 */

#include <iostream>

using namespace std;

int main() {
    char frase[100];
    int i, j;

    cout << "Introduzca una frase: ";
    cin.getline(frase, 100);

    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == ' ') {
            for (j = i; frase[j] == ' '; j++);
            i = j - 1;
        }
        cout << frase[i];
    }

    return 0;
}