//
// Created by cristhiamdaniel
// Tema: Punteros
// Problema 2 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Se quiere e valuar las funciones f(x), g(x), h(x) y z(x)
 * para todos los valores de x en el intervalo 0 ≤ x < 3.5
 * con incremento de 0.2.
 * Escribir un programa que evalúe dichas funciones,
 * utilizando un array de punteros a función.
 * Las funciones son las siguientes:
 * f(x) = 3*ex –2x;
 * g(x) = –x*sin(x)+ 1.5
 * h(x) = = cos(x) +tan(x);
 * z(x) = x^3 – 2x + 1
 */

#include <iostream>
#include <cmath>

using namespace std;

// Definimos las funciones a evaluar
double f(double x) {
    return 3 * exp(x) - 2 * x;
}

double g(double x) {
    return -x * sin(x) + 1.5;
}

double h(double x) {
    return cos(x) + tan(x);
}

double z(double x) {
    return pow(x, 3) - 2 * x + 1;
}

int main() {
    // Creamos un array de punteros a función
    double (*functions[4])(double) = {f, g, h, z};

    // Evaluamos las funciones para los valores de x en el intervalo dado
    double x = 0.0;
    while (x < 3.5) {
        cout << "x = " << x << endl;
        for (int i = 0; i < 4; i++) {
            double result = (*functions[i])(x);
            cout << "  f" << i+1 << "(x) = " << result << endl;
        }
        x += 0.2;
    }

    return 0;
}
