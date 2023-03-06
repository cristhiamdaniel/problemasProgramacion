//
// Created by cristhiamdaniel
// Tema: Punteros
// Problema 1 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Dado un array que contiene una serie de registros
 * con los datos de clientes de un establecimiento,
 * realizar una función en el que se de cómo entrada
 * un puntero al inicio del array y el apellido de un cliente.
 * La función debe devolver la dirección del registro que
 * contiene los datos del cliente buscado o NULL si no lo encuentra.
 * Incluir la función en un programa que utilice el puntero resultado
 * para imprimir los datos del cliente.
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Cliente {
    char nombre[20];
    char apellido[20];
    int edad;
};

Cliente *buscarCliente(Cliente *clientes, const char *apellido) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i].apellido, apellido) == 0) {
            return &clientes[i];
        }
    }
    return NULL;
}

int main() {
    Cliente clientes[5] = {
            {"Juan", "Perez", 20},
            {"Maria", "Gomez", 25},
            {"Pedro", "Rodriguez", 30},
            {"Jose", "Lopez", 35},
            {"Ana", "Martinez", 40}
    };

    Cliente *cliente = buscarCliente(clientes, "Lopez");

    if (cliente != NULL) {
        cout << "Nombre: " << cliente->nombre << endl;
        cout << "Apellido: " << cliente->apellido << endl;
        cout << "Edad: " << cliente->edad << endl;
    } else {
        cout << "No se encontro el cliente" << endl;
    }

    return 0;
}