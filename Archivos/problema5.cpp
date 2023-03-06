//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 5 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Mezclar dos archivos ordenados para producir otro archivo ordenado
 * consiste en ir leyendo un registro de cada uno de ellos y escribir
 * en otro archivo de salida el que sea menor de los dos,
 * repitiendo la operación con el registro no escrito y otro leído
 * del otro archivo, hasta que todos los registros de los dos archivos
 * hayan sido leídos y escritos en el archivo de salida.
 * Éste tendrá al final los registro de los dos archivos de entrada
 * pero ordenados. Suponer que la estructura de los registros es:
 * struct articulo {
 *  long clave;
 *  char nombre [20];
 *  int cantidad;
 *  char origen[10];
 * };
 * El campo clave es la referencia para la ordenación de los registros.
 */

#include <iostream>
#include <fstream>

using namespace std;

struct articulo {
    long clave;
    char nombre[20];
    int cantidad;
    char origen[10];
};

int main() {
    ifstream archivo1("archivo1.dat", ios::binary);
    ifstream archivo2("archivo2.dat", ios::binary);
    ofstream salida("salida.dat", ios::binary);

    articulo reg1, reg2;

    archivo1.read(reinterpret_cast<char*>(&reg1), sizeof(reg1));
    archivo2.read(reinterpret_cast<char*>(&reg2), sizeof(reg2));

    while (!archivo1.eof() && !archivo2.eof()) {
        if (reg1.clave < reg2.clave) {
            salida.write(reinterpret_cast<char*>(&reg1), sizeof(reg1));
            archivo1.read(reinterpret_cast<char*>(&reg1), sizeof(reg1));
        } else {
            salida.write(reinterpret_cast<char*>(&reg2), sizeof(reg2));
            archivo2.read(reinterpret_cast<char*>(&reg2), sizeof(reg2));
        }
    }

    while (!archivo1.eof()) {
        salida.write(reinterpret_cast<char*>(&reg1), sizeof(reg1));
        archivo1.read(reinterpret_cast<char*>(&reg1), sizeof(reg1));
    }

    while (!archivo2.eof()) {
        salida.write(reinterpret_cast<char*>(&reg2), sizeof(reg2));
        archivo2.read(reinterpret_cast<char*>(&reg2), sizeof(reg2));
    }

    archivo1.close();
    archivo2.close();
    salida.close();

    return 0;
}
