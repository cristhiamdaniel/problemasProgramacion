//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 2 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa que visualice por pantalla las líneas
 * de texto de un archivo, numerando cada línea del mismo.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream archivo("archivo.txt"); // Nombre del archivo a leer
    int numero_linea = 1;
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << numero_linea << ": " << linea << endl;
            numero_linea++;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return 0;
}