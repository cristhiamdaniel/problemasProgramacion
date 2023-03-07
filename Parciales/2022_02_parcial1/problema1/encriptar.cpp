#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para encriptar un caracter
char encriptar(char caracter) {
    // Si el caracter es una letra minúscula
    if (caracter >= 'a' && caracter <= 'z') {
        // Encriptar el caracter
        return 'z' - (caracter - 'a');
    }
    // Si el caracter es una letra mayúscula
    if (caracter >= 'A' && caracter <= 'Z') {
        // Encriptar el caracter
        return 'Z' - (caracter - 'A');
    }
    // Si el caracter no es una letra
    return caracter;
}

// Función para desencriptar un caracter
char desencriptar(char caracter) {
    // Si el caracter es una letra minúscula
    if (caracter >= 'a' && caracter <= 'z') {
        // Desencriptar el caracter
        return 'a' + ('z' - caracter);
    }
    // Si el caracter es una letra mayúscula
    if (caracter >= 'A' && caracter <= 'Z') {
        // Desencriptar el caracter
        return 'A' + ('Z' - caracter);
    }
    // Si el caracter no es una letra
    return caracter;
}

// Función para encriptar o desencriptar un mensaje
void encriptar_desencriptar(char *mensaje, int longitud, char (*funcion)(char)) {
    // Recorrer el mensaje
    for (int i = 0; i < longitud; i++) {
        // Encriptar o desencriptar el caracter
        mensaje[i] = funcion(mensaje[i]);
    }
}

int main() {
    // Abrir el archivo de entrada
    ifstream archivo_entrada("datos.txt");
    // Verificar si se pudo abrir el archivo
    if (!archivo_entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    // Leer el archivo de entrada caracter por caracter y mostrar su contenido en la pantalla
    char caracter;
    while (archivo_entrada.get(caracter)) {
        cout << caracter;
    }
    cout << endl;

    // Cerrar el archivo de entrada
    archivo_entrada.close();

    // Volver a abrir el archivo de entrada
    archivo_entrada.open("datos.txt");
    // Verificar si se pudo abrir el archivo
    if (!archivo_entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    // Leer el archivo de entrada y almacenar el mensaje en la variable "mensaje"
    string mensaje; // Declarar la variable para almacenar el mensaje
    int longitud; // Declarar la variable para almacenar

    // Leer el mensaje del archivo de entrada
    getline(archivo_entrada, mensaje);
    // Obtener la longitud del mensaje
    longitud = mensaje.length();

    // Cerrar el archivo de entrada
    archivo_entrada.close();

    // Encriptar el mensaje
    encriptar_desencriptar(&mensaje[0], longitud, encriptar);
    // Mostrar el mensaje encriptado
    cout << "Mensaje encriptado: " << mensaje << endl;

    // Desencriptar el mensaje
    encriptar_desencriptar(&mensaje[0], longitud, desencriptar);
    // Mostrar el mensaje desencriptado
    cout << "Mensaje desencriptado: " << mensaje << endl;

    return 0;
}