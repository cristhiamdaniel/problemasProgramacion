//
// Created by cristhiamdaniel on 5/03/23.
//
/*
 * El juego del ahorcado se juega con dos personas (o una persona y una computadora).
 * Un jugador selecciona una palabra y el otro jugador trata de adivinar la palabra
 * adivinando letras individuales.
 * Diseñar un programa para jugar al ahorcado.
 * Sugerencia: almacenar una lista de palabras en un array
 * y seleccionar palabras aleatoriamente.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

void ahorcado(char *palabra) {
    int i = 0, j = 0, k = 0, contador = 0, longitud = 0, aciertos = 0;
    char letra = ' ';
    char *palabraOculta = new char[strlen(palabra)];
    while (palabra[i] != '\0') {
        if (palabra[i] == ' ') {
            palabraOculta[i] = ' ';
        } else {
            palabraOculta[i] = '_';
        }
        i++;
    }
    palabraOculta[i] = '\0';
    longitud = strlen(palabraOculta);
    while (contador < 6) {
        cout << "Adivina la palabra: " << palabraOculta << endl;
        cout << "Ingresa una letra: ";
        cin >> letra;
        letra = tolower(letra);
        i = 0;
        while (palabra[i] != '\0') {
            if (palabra[i] == letra) {
                palabraOculta[i] = letra;
                aciertos++;
            }
            i++;
        }
        if (aciertos == longitud) {
            cout << "Ganaste! La palabra era: " << palabraOculta << endl;
            break;
        }
        contador++;
    }
    if (contador == 6) {
        cout << "Perdiste! La palabra era: " << palabra << endl;
    }
}

int main() {
    char *palabras[] = {"hola", "mundo", "cristhiam", "daniel", "c++", "programacion", "joyanes", "luis"};
    srand(time(NULL));
    int aleatorio = rand() % 8;
    ahorcado(palabras[aleatorio]);
    return 0;
}
