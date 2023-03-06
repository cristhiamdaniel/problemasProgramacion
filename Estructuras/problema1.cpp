//
// Created by cristhiamdaniel
// Tema: Estructuras
// Problema 1 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa para calcular
 * el número de días que hay entre dos fechas;
 * declarar fecha como una estructura.
 */

#include <iostream>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

int main() {
    Fecha fecha1, fecha2;
    cout << "Ingrese la primera fecha (dd/mm/aaaa): ";
    cin >> fecha1.dia >> fecha1.mes >> fecha1.anio;
    cout << "Ingrese la segunda fecha (dd/mm/aaaa): ";
    cin >> fecha2.dia >> fecha2.mes >> fecha2.anio;
    int dias = 0;
    if (fecha1.anio == fecha2.anio) {
        if (fecha1.mes == fecha2.mes) {
            dias = fecha2.dia - fecha1.dia;
        } else {
            int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            dias = diasMeses[fecha1.mes - 1] - fecha1.dia;
            for (int i = fecha1.mes; i < fecha2.mes - 1; i++) {
                dias += diasMeses[i];
            }
            dias += fecha2.dia;
        }
    } else {
        int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        dias = diasMeses[fecha1.mes - 1] - fecha1.dia;
        for (int i = fecha1.mes; i < 12; i++) {
            dias += diasMeses[i];
        }
        for (int i = fecha1.anio + 1; i < fecha2.anio; i++) {
            dias += 365;
        }
        for (int i = 0; i < fecha2.mes - 1; i++) {
            dias += diasMeses[i];
        }
        dias += fecha2.dia;
    }
    cout << "Hay " << dias << " dias entre las dos fechas" << endl;
    return 0;
}