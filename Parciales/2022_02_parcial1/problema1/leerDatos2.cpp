//
// Created by cristhiamdaniel on 6/03/23.
//
#include <iostream>
#include <fstream>

using namespace std;

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

    return 0;
}
