//
// Created by cristhiamdaniel
// Tema: Estructuras
// Problema 2 - Programación en C++ un enfoque práctico
// Autor: Joyanes Luis
//
/*
 * Un número racional se caracteriza por el numerador y denominador.
 * Escribir un programa para operar con números racionales.
 * Las operaciones a definir son
 * la suma, resta, multiplicación y división;
 * además de una función para simplificar cada número racional.
 */

#include <iostream>

using namespace std;

struct Racional {
    int numerador;
    int denominador;
};

int mcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mcd(b, a % b);
}

Racional simplificar(Racional racional) {
    int mcdRacional = mcd(racional.numerador, racional.denominador);
    racional.numerador /= mcdRacional;
    racional.denominador /= mcdRacional;
    return racional;
}

Racional sumar(Racional racional1, Racional racional2) {
    Racional resultado;
    resultado.numerador = racional1.numerador * racional2.denominador + racional2.numerador * racional1.denominador;
    resultado.denominador = racional1.denominador * racional2.denominador;
    return simplificar(resultado);
}

Racional restar(Racional racional1, Racional racional2) {
    Racional resultado;
    resultado.numerador = racional1.numerador * racional2.denominador - racional2.numerador * racional1.denominador;
    resultado.denominador = racional1.denominador * racional2.denominador;
    return simplificar(resultado);
}

Racional multiplicar(Racional racional1, Racional racional2) {
    Racional resultado;
    resultado.numerador = racional1.numerador * racional2.numerador;
    resultado.denominador = racional1.denominador * racional2.denominador;
    return simplificar(resultado);
}

Racional dividir(Racional racional1, Racional racional2) {
    Racional resultado;
    resultado.numerador = racional1.numerador * racional2.denominador;
    resultado.denominador = racional1.denominador * racional2.numerador;
    return simplificar(resultado);
}

void imprimirRacional(Racional racional) {
    cout << racional.numerador << "/" << racional.denominador << endl;
}

int main() {
    Racional racional1 = {1, 2};
    Racional racional2 = {1, 3};
    imprimirRacional(sumar(racional1, racional2));
    imprimirRacional(restar(racional1, racional2));
    imprimirRacional(multiplicar(racional1, racional2));
    imprimirRacional(dividir(racional1, racional2));
    return 0;
}