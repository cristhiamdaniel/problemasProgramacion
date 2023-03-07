//
// Created by cristhiamdaniel on 6/03/23.
//
/*
 * Crear un archivo binario notas.dat que contiene los resultados de presentacion de examenes estan grabadas en un archivo binario con tipo llamado ```notas.dat``` que contiene cada persona: numero de identificacion, nombre de la persona, tipo de examen (INICIAL o SUPLETORIO) y la nota obtenida con un decimal, como se muestra en el siguiente ejemplo:

| Identificacion | Nombre | Tipo de examen | Nota |
|----------------|--------|----------------|------|
1111 | Juan Perez | INICIAL | 4.5
2222 | Maria Lopez | SUPLETORIO | 3.5
3333 | Pedro Gomez | INICIAL | 2.5

 El programa debe solicitar cuantos estudiantes desea ingresar.
 Por cada estudiante debe pedir los datos y grabarlos en el archivo.
 Al finalizar el programa debe mostrar el contenido del archivo.
 */

#include <iostream>
#include <fstream>

using namespace std;

struct Estudiante {
    int identificacion;
    char nombre[50];
    char tipoExamen[50];
    float nota;
};

int main() {
    int cantidadEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidadEstudiantes;

    Estudiante estudiantes[cantidadEstudiantes];

    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese la identificacion del estudiante: ";
        cin >> estudiantes[i].identificacion;
        cout << "Ingrese el nombre del estudiante: ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el tipo de examen del estudiante: ";
        cin >> estudiantes[i].tipoExamen;
        cout << "Ingrese la nota del estudiante: ";
        cin >> estudiantes[i].nota;
    }

    ofstream archivo("notas.dat", ios::binary);
    archivo.write((char *) estudiantes, sizeof(Estudiante) * cantidadEstudiantes);
    archivo.close();

    ifstream archivoLectura("notas.dat", ios::binary);
    archivoLectura.read((char *) estudiantes, sizeof(Estudiante) * cantidadEstudiantes);
    archivoLectura.close();

    cout << "Identificacion\tNombre\tTipo de examen\tNota" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << estudiantes[i].identificacion << "\t" << estudiantes[i].nombre << "\t" << estudiantes[i].tipoExamen << "\t" << estudiantes[i].nota << endl;
    }

    return 0;
}
