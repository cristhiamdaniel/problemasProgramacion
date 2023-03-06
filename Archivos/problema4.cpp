//
// Created by cristhiamdaniel
// Tema: Archivos
// Problema 4 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa que gestione una base de datos con
 * los registros de una agenda de direcciones y teléfonos.
 * Cada registro debe tener datos sobre el nombre, la dirección,
 * el teléfono fijo, el teléfono móvil (celular),
 * la dirección de correo electrónico de una persona.
 * El programa debe mostrar un menú para poder añadir
 * nuevas entradas, modificar, borrar y buscar registros
 * de personas a partir del nombre.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Registro {
    string nombre;
    string direccion;
    string telefono_fijo;
    string telefono_movil;
    string correo_electronico;
};

void agregar_registro(Registro registro) {
    ofstream archivo("agenda.txt", ios::app);
    if (archivo.is_open()) {
        archivo << registro.nombre << endl;
        archivo << registro.direccion << endl;
        archivo << registro.telefono_fijo << endl;
        archivo << registro.telefono_movil << endl;
        archivo << registro.correo_electronico << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void modificar_registro(Registro registro) {
    ifstream archivo("agenda.txt");
    ofstream archivo_temporal("agenda_temporal.txt");
    if (archivo.is_open() && archivo_temporal.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea == registro.nombre) {
                archivo_temporal << registro.nombre << endl;
                archivo_temporal << registro.direccion << endl;
                archivo_temporal << registro.telefono_fijo << endl;
                archivo_temporal << registro.telefono_movil << endl;
                archivo_temporal << registro.correo_electronico << endl;
                getline(archivo, linea);
                getline(archivo, linea);
                getline(archivo, linea);
                getline(archivo, linea);
            } else {
                archivo_temporal << linea << endl;
            }
        }
        archivo.close();
        archivo_temporal.close();
        remove("agenda.txt");
        rename("agenda_temporal.txt", "agenda.txt");
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void eliminar_registro(string nombre) {
    ifstream archivo("agenda.txt");
    ofstream archivo_temporal("agenda_temporal.txt");
    if (archivo.is_open() && archivo_temporal.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea != nombre) {
                archivo_temporal << linea << endl;
            } else {
                getline(archivo, linea);
                getline(archivo, linea);
                getline(archivo, linea);
                getline(archivo, linea);
            }
        }
        archivo.close();
        archivo_temporal.close();
        remove("agenda.txt");
        rename("agenda_temporal.txt", "agenda.txt");
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

Registro buscar_registro(string nombre) {
    ifstream archivo("agenda.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea == nombre) {
                Registro registro;
                registro.nombre = linea;
                getline(archivo, linea);
                registro.direccion = linea;
                getline(archivo, linea);
                registro.telefono_fijo = linea;
                getline(archivo, linea);
                registro.telefono_movil = linea;
                getline(archivo, linea);
                registro.correo_electronico = linea;
                archivo.close();
                return registro;
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    Registro registro;
    registro.nombre = "";
    return registro;
}

void mostrar_registro(Registro registro) {
    cout << "Nombre: " << registro.nombre << endl;
    cout << "Direccion: " << registro.direccion << endl;
    cout << "Telefono fijo: " << registro.telefono_fijo << endl;
    cout << "Telefono movil: " << registro.telefono_movil << endl;
    cout << "Correo electronico: " << registro.correo_electronico << endl;
}

int main() {
    int opcion;
    do {
        cout << "1. Agregar registro" << endl;
        cout << "2. Modificar registro" << endl;
        cout << "3. Eliminar registro" << endl;
        cout << "4. Buscar registro" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1: {
                Registro registro;
                cout << "Nombre: ";
                getline(cin, registro.nombre);
                cout << "Direccion: ";
                getline(cin, registro.direccion);
                cout << "Telefono fijo: ";
                getline(cin, registro.telefono_fijo);
                cout << "Telefono movil: ";
                getline(cin, registro.telefono_movil);
                cout << "Correo electronico: ";
                getline(cin, registro.correo_electronico);
                agregar_registro(registro);
                break;
            }
            case 2: {
                Registro registro;
                cout << "Nombre: ";
                getline(cin, registro.nombre);
                cout << "Direccion: ";
                getline(cin, registro.direccion);
                cout << "Telefono fijo: ";
                getline(cin, registro.telefono_fijo);
                cout << "Telefono movil: ";
                getline(cin, registro.telefono_movil);
                cout << "Correo electronico: ";
                getline(cin, registro.correo_electronico);
                modificar_registro(registro);
                break;
            }
            case 3: {
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);
                eliminar_registro(nombre);
                break;
            }
            case 4: {
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);
                Registro registro = buscar_registro(nombre);
                if (registro.nombre != "") {
                    mostrar_registro(registro);
                } else {
                    cout << "No se encontro el registro" << endl;
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                break;
            }
        }
    } while (opcion != 5);
    return 0;
}