//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 3 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa para listar el contenido de un determinado subdirectorio,
 * pasado como parámetro a la función main( ).
 */

#include <iostream>
#include <fstream>
#include <dirent.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <directorio>" << endl;
        return 1;
    }

    DIR *directorio = opendir(argv[1]);
    if (directorio == NULL) {
        cout << "No se pudo abrir el directorio" << endl;
        return 1;
    }

    struct dirent *archivo;
    while ((archivo = readdir(directorio)) != NULL) {
        cout << archivo->d_name << endl;
    }

    closedir(directorio);
    return 0;
}