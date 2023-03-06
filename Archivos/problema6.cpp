//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 7 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Un profesor tiene 30 estudiantes y cada estudiante
 * tiene tres calificaciones en el primer parcial.
 * Almacenar los datos en un archivo, dejando espacio para
 * dos notas más y la nota final.
 * Incluir un menú de opciones, para añadir más estudiantes,
 * visualizar datos de un estudiante, introducir nuevas notas
 * y calcular la nota final como media del resto de las calificaciones.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct estudiante {
    char nombre[30];
    int calificaciones[5];
};

void menu();
void agregarEstudiante();
void mostrarEstudiante();
void agregarCalificaciones();
void calcularNotaFinal();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;

    do {
        cout << "MENU DE OPCIONES" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar datos de un estudiante" << endl;
        cout << "3. Agregar calificaciones de un estudiante" << endl;
        cout << "4. Calcular nota final de un estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiante();
                break;
            case 3:
                agregarCalificaciones();
                break;
            case 4:
                calcularNotaFinal();
                break;
            case 5:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);
}

void agregarEstudiante() {
    estudiante est;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    cin.getline(est.nombre, 30);

    for (int i = 0; i < 5; i++) {
        est.calificaciones[i] = 0;
    }

    ofstream archivo("estudiantes.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo.close();

    cout << "Estudiante agregado exitosamente." << endl;
}

void mostrarEstudiante() {
    int indice;
    estudiante est;

    cout << "Ingrese el numero de estudiante (1 a 30): ";
    cin >> indice;

    ifstream archivo("estudiantes.dat", ios::binary);
    archivo.seekg((indice - 1) * sizeof(estudiante));
    archivo.read(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo.close();

    cout << "Nombre: " << est.nombre << endl;
    cout << "Calificaciones: ";
    for (int i = 0; i < 5; i++) {
        cout << est.calificaciones[i] << " ";
    }
    cout << endl;
}

void agregarCalificaciones() {
    int indice, examen;
    estudiante est;

    cout << "Ingrese el numero de estudiante (1 a 30): ";
    cin >> indice;

    ifstream archivo("estudiantes.dat", ios::binary);
    archivo.seekg((indice - 1) * sizeof(estudiante));
    archivo.read(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo.close();

    cout << "Ingrese el numero de examen (1 a 3): ";
    cin >> examen;
    cout << "Ingrese la calificacion: ";
    cin >> est.calificaciones[examen - 1];

    ofstream archivo2("estudiantes.dat", ios::binary);
    archivo2.seekp((indice - 1) * sizeof(estudiante));
    archivo2.write(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo2.close();

    cout << "Calificacion agregada exitosamente." << endl;
}

void calcularNotaFinal() {
    int indice;
    estudiante est;

    cout << "Ingrese el numero de estudiante (1 a 30): ";
    cin >> indice;

    ifstream archivo("estudiantes.dat", ios::binary);
    archivo.seekg((indice - 1) * sizeof(estudiante));
    archivo.read(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo.close();

    int suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += est.calificaciones[i];
    }
    est.calificaciones[3] = suma / 3;

    ofstream archivo2("estudiantes.dat", ios::binary);
    archivo2.seekp((indice - 1) * sizeof(estudiante));
    archivo2.write(reinterpret_cast<char*>(&est), sizeof(estudiante));
    archivo2.close();

    cout << "Nota final calculada exitosamente." << endl;
}


