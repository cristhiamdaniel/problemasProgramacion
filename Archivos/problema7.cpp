//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 8 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * En un archivo de texto se conserva la salida de las transacciones
 * con los proveedores de una cadena de tienda.
 * Se ha perdido el listado original de proveedores y se desea
 * reconstruir a partir del archivo de transacciones.
 * Se sabe que cada línea del archivo comienza con el nombre del proveedor.
 * Se pide escribir un programa que lea el archivo de transacciones,
 * obtenga el nombre del proveedor con los caracteres hasta el primer
 * espacio en blanco y muestre una lista con todos los proveedores
 * diferentes con los que se trabaja en las tiendas.
 */

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    ifstream archivo("transacciones.txt");
    string linea;
    set<string> proveedores;

    while (getline(archivo, linea)) {
        string proveedor = linea.substr(0, linea.find(" "));
        proveedores.insert(proveedor);
    }

    archivo.close();

    cout << "Lista de proveedores:" << endl;
    for (const auto& proveedor : proveedores) {
        cout << proveedor << endl;
    }

    return 0;
}
