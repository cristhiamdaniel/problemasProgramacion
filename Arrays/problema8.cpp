//
// Created by cristhiamdaniel
// Tema: Arrays
// Problema 8 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//

/*
 * Escribir una función con versión que reciba como parámetro
 * una cadena representando una fecha en formato 'dd/mm/aa',
 * como 17/11/91
 * y la devuelva en formato de texto: 17 noviembre 1991.
 */

#include <iostream>

using namespace std;

void fechaTexto(char *fecha) {
    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int dia = 0, mes = 0, anio = 0;
    sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio);
    cout << dia << " " << meses[mes - 1] << " " << anio << endl;
}

int main() {
    char fecha[] = "17/11/91";
    fechaTexto(fecha);
    return 0;
}