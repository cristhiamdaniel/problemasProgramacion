//
// Created by cristhiamdaniel
// Tema: Punteros
// Problema 3 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Suponer que se tiene un catálogo de un almacén
 * con los datos de cada uno de los artículos en stock y
 * que se desea cambiar el orden en que aparecen en la tabla
 * pero sin modificar, en realidad, el orden en que fueron
 * almacenados los registros en el array.
 * Escribir un programa que añada un campo de tipo puntero al mismo
 * tipo de estructura a cada registro.
 * Una vez transformado el array el programa ha de hacer que el
 * puntero de cada estructura apunte a la estructura que estaría
 * a continuación según un nuevo orden, por ejemplo,
 * en orden creciente de número del artículo.
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Articulo {
    int numero;
    char descripcion[20];
    int stock;
    Articulo *siguiente;
};

void ordenarArticulos(Articulo *articulos, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (articulos[i].numero > articulos[j].numero) {
                Articulo aux = articulos[i];
                articulos[i] = articulos[j];
                articulos[j] = aux;
            }
        }
    }
}

void imprimirArticulos(Articulo *articulos, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Articulo " << i + 1 << endl;
        cout << "  Numero: " << articulos[i].numero << endl;
        cout << "  Descripcion: " << articulos[i].descripcion << endl;
        cout << "  Stock: " << articulos[i].stock << endl;
        cout << "  Siguiente: " << articulos[i].siguiente << endl;
    }
}

int main() {
    Articulo articulos[5] = {
            {1, "Articulo 1", 10},
            {2, "Articulo 2", 20},
            {3, "Articulo 3", 30},
            {4, "Articulo 4", 40},
            {5, "Articulo 5", 50}
    };

    ordenarArticulos(articulos, 5);

    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            articulos[i].siguiente = NULL;
        } else {
            articulos[i].siguiente = &articulos[i + 1];
        }
    }

    imprimirArticulos(articulos, 5);

    return 0;
}