//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 1 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir un programa que convierta un número romano
 * (en forma de cadena de caracteres) en número arábigo.
 * Reglas de conversión:
 * M = 1000
 * D = 500
 * C = 100
 * L = 50
 * X = 10
 * V = 5
 * I = 1
 */

#include <iostream>

using namespace std;

int main() {
    string numeroRomano;
    int numeroArabigo = 0;

    cout << "Ingrese el numero romano: ";
    cin >> numeroRomano;

    for (int i = 0; i < numeroRomano.length(); i++) {
        switch (numeroRomano[i]) {
            case 'M':
                numeroArabigo += 1000;
                break;
            case 'D':
                numeroArabigo += 500;
                break;
            case 'C':
                numeroArabigo += 100;
                break;
            case 'L':
                numeroArabigo += 50;
                break;
            case 'X':
                numeroArabigo += 10;
                break;
            case 'V':
                numeroArabigo += 5;
                break;
            case 'I':
                numeroArabigo += 1;
                break;
        }
    }

    cout << "El numero arabigo es: " << numeroArabigo << endl;

    return 0;
}