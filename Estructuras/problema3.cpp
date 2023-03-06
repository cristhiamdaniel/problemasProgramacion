//
// Created by cristhiamdaniel
// Tema: Estructuras
// Problema 3 - Programacion en C++ un enfoque practico
// Autor: Joyanes Luis
//
/*
 * Escribir un programa que gestione una agenda
 * de direcciones. Los datos de la agenda se almacenan en
 * memoria en un array de estructuras, cada una de las cuales
 * tiene los siguientes campos:
 * nombre, dirección, teléfono fijo, teléfono móvil, dirección de correo electrónico.
 * El programa debe permitir añadir una nue va entrada a la agenda,
 * borrar una entrada, buscar por nombre y
 * eliminar una entrada determinada por el nombre.
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ENTRIES = 100;

struct Entry {
    char name[50];
    char address[100];
    char phone[15];
    char mobile[15];
    char email[50];
};

struct Agenda {
    Entry entries[MAX_ENTRIES];
    int count;
};

void addEntry(Agenda& agenda);
void removeEntry(Agenda& agenda);
void searchEntry(Agenda& agenda);
void deleteEntry(Agenda& agenda);

int main() {
    Agenda agenda = { {}, 0 };
    int option;

    do {
        cout << "1. Añadir entrada" << endl;
        cout << "2. Borrar entrada" << endl;
        cout << "3. Buscar por nombre" << endl;
        cout << "4. Eliminar entrada por nombre" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1:
                addEntry(agenda);
                break;
            case 2:
                removeEntry(agenda);
                break;
            case 3:
                searchEntry(agenda);
                break;
            case 4:
                deleteEntry(agenda);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }

        cout << endl;

    } while (option != 5);

    return 0;
}

void addEntry(Agenda& agenda) {
    if (agenda.count >= MAX_ENTRIES) {
        cout << "No se pueden agregar más entradas." << endl;
        return;
    }

    Entry newEntry;
    cout << "Ingrese el nombre: ";
    cin >> newEntry.name;
    cout << "Ingrese la dirección: ";
    cin >> newEntry.address;
    cout << "Ingrese el teléfono fijo: ";
    cin >> newEntry.phone;
    cout << "Ingrese el teléfono móvil: ";
    cin >> newEntry.mobile;
    cout << "Ingrese el correo electrónico: ";
    cin >> newEntry.email;

    agenda.entries[agenda.count] = newEntry;
    agenda.count++;

    cout << "Entrada agregada exitosamente." << endl;
}

void removeEntry(Agenda& agenda) {
    if (agenda.count == 0) {
        cout << "La agenda está vacía." << endl;
        return;
    }

    int index;
    cout << "Ingrese el índice de la entrada a borrar (entre 1 y " << agenda.count << "): ";
    cin >> index;

    if (index < 1 || index > agenda.count) {
        cout << "Índice inválido." << endl;
        return;
    }

    for (int i = index-1; i < agenda.count-1; i++) {
        agenda.entries[i] = agenda.entries[i+1];
    }

    agenda.count--;

    cout << "Entrada eliminada exitosamente." << endl;
}

void searchEntry(Agenda& agenda) {
    if (agenda.count == 0) {
        cout << "La agenda está vacía." << endl;
        return;
    }

    char name[50];
    cout << "Ingrese el nombre a buscar: ";
    cin >> name;

    for (int i = 0; i < agenda.count; i++) {
        if (strcmp(agenda.entries[i].name, name) == 0) {
            cout << "Nombre: " << agenda.entries[i].name << endl;
            cout << "Dirección: " << agenda.entries[i].address << endl;
            cout << "Teléfono fijo: " << agenda.entries[i].phone << endl;
            cout << "Teléfono móvil: " << agenda.entries[i].mobile << endl;
            cout << "Correo electrónico: " << agenda.entries[i].email << endl;
            return;
        }
    }

    cout << "No se encontró ninguna entrada con ese nombre." << endl;

}

void deleteEntry(Agenda& agenda) {
    if (agenda.count == 0) {
        cout << "La agenda está vacía." << endl;
        return;
    }

    char name[50];
    cout << "Ingrese el nombre de la entrada a eliminar: ";
    cin >> name;

    for (int i = 0; i < agenda.count; i++) {
        if (strcmp(agenda.entries[i].name, name) == 0) {
            for (int j = i; j < agenda.count-1; j++) {
                agenda.entries[j] = agenda.entries[j+1];
            }
            agenda.count--;
            cout << "Entrada eliminada exitosamente." << endl;
            return;
        }
    }

    cout << "No se encontró ninguna entrada con ese nombre." << endl;
}


