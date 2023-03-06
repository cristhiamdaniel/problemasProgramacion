//
// Created by cristhiamdaniel on 6/03/23.
//
/*
 * Crear un archivo de unas estructuras en 2 archivos binarios
 * y llenar la informacion necesaria
 * archivo1.dat
 * archivo2.dat
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
    ofstream archivo1("archivo1.dat", ios::binary);
    ofstream archivo2("archivo2.dat", ios::binary);

    articulo reg1, reg2;

    reg1.clave = 1;
    strcpy(reg1.nombre, "Lapiz");
    reg1.cantidad = 10;
    strcpy(reg1.origen, "China");

    reg2.clave = 2;
    strcpy(reg2.nombre, "Borrador");
    reg2.cantidad = 5;
    strcpy(reg2.origen, "Mexico");

    archivo1.write(reinterpret_cast<char*>(&reg1), sizeof(reg1));
    archivo2.write(reinterpret_cast<char*>(&reg2), sizeof(reg2));

    archivo1.close();
    archivo2.close();

    return 0;
}