//
// Created by cristhiamdaniel
// Tema: Punteros
// Problema 7 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Se pretende gestionar un vídeo club; se dispone de los datos de
 * todas las películas que se pueden alquilar y de los clientes abonados.
 * Escribir un programa que cree dos arrays de estructuras uno para
 * las películas de vídeo y otro para los clientes con todos sus datos.
 * La estructura de cada película tendrá un puntero a la estructura de
 * la tabla de clientes al registro del cliente que ha alquilado.
 * También al revés, el registro de cada cliente tendrá un puntero
 * al registro de la película que tiene alquilada.
 * El programa pedirá continuamente el nombre de cada cinta y a quién
 * se presta o quién la devuelve, colocando a continuación los
 * punteros de forma que apunten a los registros que correspondan.
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Pelicula {
    char titulo[20];
    char genero[20];
    int duracion;
    Pelicula *alquilada;
};

struct Cliente {
    char nombre[20];
    char apellido[20];
    int edad;
    Pelicula *alquilada;
};

int main() {
    Pelicula peliculas[5] = {
            {"El padrino", "Drama", 175, NULL},
            {"El padrino 2", "Drama", 200, NULL},
            {"El padrino 3", "Drama", 220, NULL},
            {"El caballero oscuro", "Accion", 152, NULL},
            {"El caballero 1", "Accion", 165, NULL}
    };

    Cliente clientes[5] = {
            {"Juan", "Perez", 20, NULL},
            {"Maria", "Gomez", 25, NULL},
            {"Pedro", "Rodriguez", 30, NULL},
            {"Jose", "Lopez", 35, NULL},
            {"Ana", "Martinez", 40, NULL}
    };

    char nombre[20];
    char apellido[20];
    char titulo[20];

    while (true) {
        cout << "Ingrese el nombre del cliente: ";
        cin >> nombre;
        cout << "Ingrese el apellido del cliente: ";
        cin >> apellido;
        cout << "Ingrese el titulo de la pelicula: ";
        cin >> titulo;

        Cliente *cliente = NULL;
        Pelicula *pelicula = NULL;

        for (int i = 0; i < 5; i++) {
            if (strcmp(clientes[i].nombre, nombre) == 0 && strcmp(clientes[i].apellido, apellido) == 0) {
                cliente = &clientes[i];
            }
            if (strcmp(peliculas[i].titulo, titulo) == 0) {
                pelicula = &peliculas[i];
            }
        }

        if (cliente != NULL && pelicula != NULL) {
            cliente->alquilada = pelicula;
            pelicula->alquilada = (Pelicula*)cliente;
            ;
        } else {
            cout << "No se encontro el cliente o la pelicula" << endl;
        }
    }

    return 0;
}