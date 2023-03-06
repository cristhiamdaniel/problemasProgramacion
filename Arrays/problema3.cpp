//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 3 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir una función que acepte como parámetro un vector
 * que puede contener elementos duplicados.
 * La función debe sustituir cada valor repetido por –5 y
 * devolver al punto donde fue llamado el vector modificado
 * y el número de entradas modificadas
 */

#include <iostream>
using namespace std;

// El numero de entradas modificadas debe ser igual a cuantos -5 hay en el vector

void modificarVector(int vector[], int tamano) {
    int contador = 0;
    bool modificados[tamano] = { false }; // Para solucionar este error se debe usar arreglo dinamico

    for (int i = 0; i < tamano; i++) {
        if (modificados[i]) {
            continue; // ya se modificó este elemento, continuar con el siguiente
        }

        for (int j = i + 1; j < tamano; j++) {
            if (vector[i] == vector[j]) {
                vector[j] = -5;
                modificados[j] = true;
                contador++;
            }
        }
    }

    cout << "El numero de entradas modificadas es: " << contador << endl;
}


int main() {
    int tamano;
    cout << "Ingrese el tamano del vector: ";
    cin >> tamano;

    int vector[tamano];

    for (int i = 0; i < tamano; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> vector[i];
    }

    modificarVector(vector, tamano);

    cout << "El vector modificado es: ";
    for (int i = 0; i < tamano; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    return 0;
}