//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 6 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//


/*
 * Escribir un programa que desplace una palabra leída
 * del teclado desde la izquierda hasta la derecha de la pantalla.
 */

#include <iostream>

using namespace std;

int main() {
    char palabra[20];
    int i, j;

    cout << "Introduzca una palabra: ";
    cin >> palabra;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < i; j++) {
            cout << " ";
        }
        cout << palabra << endl;
    }

    return 0;
}