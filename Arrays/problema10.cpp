//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 10 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Buscar una palabra en una cadena y calcular su frecuencia de aparición.
 */

#include <iostream>

using namespace std;

int main() {
    char cadena[] = "Hola mundo, hola mundo, hola mundo";
    char palabra[] = "mundo";
    int i = 0, j = 0, k = 0, contador = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] == palabra[j]) {
            j++;
            if (palabra[j] == '\0') {
                contador++;
                j = 0;
            }
        } else {
            j = 0;
        }
        i++;
    }
    cout << "La palabra " << palabra << " aparece " << contador << " veces" << endl;
    return 0;
}