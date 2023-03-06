//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 2 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir una función a la que se le proporcione una fecha
 * (día, mes, año), así como un número de días a añadir a esta fecha.
 * La función debe calcular la nueva fecha y visualizarla.
 */

#include <iostream>
using namespace std;

void nuevaFecha(int dia, int mes, int anio, int dias) {
    int diasMeses[12] = {31, 28, 31, 30, 31,
                         30, 31, 31, 30, 31,
                         30, 31}; // dias de cada mes
    int diasMes = diasMeses[mes - 1]; // dias del mes actual
    int diasAnio = 365; // dias del anio actual

    if (anio % 4 == 0) { // si es bisiesto
        diasAnio = 366;
    }

    if (dia + dias > diasMes) { // si la suma de dias es mayor a los dias del mes
        dias -= diasMes - dia;
        dia = 1;
        mes++;

        if (mes > 12) { // si el mes es mayor a 12
            mes = 1;
            anio++;
        }

        nuevaFecha(dia, mes, anio, dias);
    } else {
        dia += dias;
        cout << "La nueva fecha es: " << dia << "/" << mes << "/" << anio << endl;
    }
}

int main() {
    int dia, mes, anio, dias;

    cout << "Ingrese el dia: ";
    cin >> dia;

    cout << "Ingrese el mes: ";
    cin >> mes;

    cout << "Ingrese el anio: ";
    cin >> anio;

    cout << "Ingrese los dias a sumar: ";
    cin >> dias;

    nuevaFecha(dia, mes, anio, dias);

    return 0;
}

