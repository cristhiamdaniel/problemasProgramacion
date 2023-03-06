//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 1 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Se quiere obtener una estadística de un archivo de caracteres.
 * Escribir un programa para contar el número de palabras de que consta un archivo,
 * así como una estadística de cada longitud de palabra
 */

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream archivo("archivo.txt"); // Nombre del archivo a leer
    bool leyendo_palabra = false;
    int total_palabras = 0, longitud_actual = 0;

    if (archivo.is_open()) {
        char c;
        while (archivo.get(c)) {
            if (isalpha(c)) {
                if (!leyendo_palabra) {
                    leyendo_palabra = true;
                    total_palabras++;
                }
                longitud_actual++;
            } else {
                if (leyendo_palabra) {
                    leyendo_palabra = false;
                    longitud_actual = 0;
                }
            }
        }
        archivo.close();

        int *estadistica = new int[total_palabras + 1]; // Crear arreglo con tamaño igual al número de palabras contadas
        for (int i = 0; i <= total_palabras; i++) {
            estadistica[i] = 0;
        }

        archivo.open("archivo.txt"); // Volver a abrir el archivo
        leyendo_palabra = false;
        while (archivo.get(c)) {
            if (isalpha(c)) {
                if (!leyendo_palabra) {
                    leyendo_palabra = true;
                }
                longitud_actual++;
            } else {
                if (leyendo_palabra) {
                    leyendo_palabra = false;
                    estadistica[longitud_actual]++;
                    longitud_actual = 0;
                }
            }
        }
        archivo.close();
        cout << "Total de palabras: " << total_palabras << endl;
        cout << "Estadistica de longitud de palabra: " << endl;
        for (int i = 1; i <= total_palabras; i++) {
            if (estadistica[i] != 0) {
                cout << "Longitud " << i << ": " << estadistica[i] << " palabras" << endl;
            }
        }
        delete[] estadistica; // Liberar memoria del arreglo
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return 0;
}
