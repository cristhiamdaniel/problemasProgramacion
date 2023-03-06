//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 7 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir un programa que lea una serie de cadenas,
 * a continuación, determine si la cadena es un identificador válido C++.
 * Sugerencias: utilizar los siguientes subprogramas:
 * longitud (tamaño del identificador en el rango permitido);
 * primero (determinar si el nombre comienza con un símbolo permitido);
 * restantes (comprueba si los restantes son caracteres permitidos).
 */

#include <iostream>

using namespace std;

int longitud(char palabra[]) {
    int i = 0;
    while (palabra[i] != '\0') {
        i++;
    }
    return i;
}

bool primero(char palabra[]) {
    if (palabra[0] == '_' || (palabra[0] >= 'a' && palabra[0] <= 'z') || (palabra[0] >= 'A' && palabra[0] <= 'Z')) {
        return true;
    }
    return false;
}

bool restantes(char palabra[]) {
    int i = 1;
    while (palabra[i] != '\0') {
        if (palabra[i] == '_' || (palabra[i] >= 'a' && palabra[i] <= 'z') || (palabra[i] >= 'A' && palabra[i] <= 'Z') || (palabra[i] >= '0' && palabra[i] <= '9')) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    char palabra[20];
    int i, j;

    cout << "Introduzca una palabra: ";
    cin >> palabra;

    if (longitud(palabra) >= 1 && longitud(palabra) <= 20 && primero(palabra) && restantes(palabra)) {
        cout << "Es un identificador valido" << endl;
    } else {
        cout << "No es un identificador valido" << endl;
    }

    return 0;
}