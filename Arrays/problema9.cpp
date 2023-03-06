//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 9 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa que permita escribir en sentido inverso una cadena de caracteres.
 */

#include <iostream>

using namespace std;

void invertir(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0) {
        cout << cadena[i];
        i--;
    }
    cout << endl;
}

int main() {
    char cadena[] = "Hola mundo";
    invertir(cadena);
    return 0;
}