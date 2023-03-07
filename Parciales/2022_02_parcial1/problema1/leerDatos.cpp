//
// Created by cristhiamdaniel on 6/03/23.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Abrir el archivo de entrada
    ifstream archivo_entrada("datos.txt");
    // Verificar si se pudo abrir el archivo
    if (!archivo_entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    // Leer el archivo de entrada línea por línea y mostrar su contenido en la pantalla
    string linea;
    while (getline(archivo_entrada, linea)) {
        cout << linea << endl;
    }

    // Cerrar el archivo de entrada
    archivo_entrada.close();

    return 0;
}
