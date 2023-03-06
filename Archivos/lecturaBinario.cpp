//
// Created by cristhiamdaniel on 6/03/23.
//
/*
 * LEctura de archivo binario que es una estructura:
 * * struct articulo {
 *  long clave;
 *  char nombre [20];
 *  int cantidad;
 *  char origen[10];
 * };
 * llamado salida.dat
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct articulo {
    long clave;
    char nombre[20];
    int cantidad;
    char origen[10];
};

int main() {
    ifstream salida("salida.dat", ios::binary);

    articulo reg;

    salida.read(reinterpret_cast<char*>(&reg), sizeof(reg));

    while (!salida.eof()) {
        cout << "Clave: " << reg.clave << endl;
        cout << "Nombre: " << reg.nombre << endl;
        cout << "Cantidad: " << reg.cantidad << endl;
        cout << "Origen: " << reg.origen << endl;
        cout << endl;

        salida.read(reinterpret_cast<char*>(&reg), sizeof(reg));
    }

    salida.close();

    return 0;
}