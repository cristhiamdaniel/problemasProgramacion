//
// Created by cristhiamdaniel
// Tema: Estructuras
// Problema 4 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa auxiliar que permita añadir nuevos campos a
 * la tabla de empleados, como por ejemplo, sueldo anual y porcentaje
 * de retenciones de impuestos.
 * Una vez modificado el array de estructuras,
 * escribir un programa que permita a un usuario elegir un
 * rango de registros de empleados especificando un apellido inicial
 */

#include <iostream>

using namespace std;

struct Empleado {
    char nombre[20];
    char apellido[20];
    int sueldoAnual;
    float porcentajeRetenciones;
};

void imprimirEmpleado(Empleado empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Apellido: " << empleado.apellido << endl;
    cout << "Sueldo anual: " << empleado.sueldoAnual << endl;
    cout << "Porcentaje de retenciones: " << empleado.porcentajeRetenciones << endl;
}

int main() {
    Empleado empleados[] = {
            {"Juan", "Perez", 100000, 0.1},
            {"Maria", "Gomez", 120000, 0.15},
            {"Pedro", "Gonzalez", 80000, 0.05},
            {"Jose", "Rodriguez", 90000, 0.1},
            {"Luis", "Martinez", 110000, 0.15},
            {"Ana", "Lopez", 130000, 0.2},
            {"Rosa", "Gutierrez", 95000, 0.1},
            {"Sofia", "Hernandez", 105000, 0.15},
            {"Luisa", "Diaz", 115000, 0.2},
            {"Miguel", "Perez", 125000, 0.25},
    };
    int n = sizeof(empleados) / sizeof(Empleado);
    char apellidoInicial;
    cout << "Ingrese la inicial del apellido: ";
    cin >> apellidoInicial;
    for (int i = 0; i < n; i++) {
        if (empleados[i].apellido[0] == apellidoInicial) {
            imprimirEmpleado(empleados[i]);
        }
    }
    return 0;
}

