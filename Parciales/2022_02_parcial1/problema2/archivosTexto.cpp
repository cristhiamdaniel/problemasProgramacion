/*
 * Se tiene un archivo notas.dat que guarda el arreglo de las siguientes estructuras:
 Identificacion  Nombre  Tipo de examen  Nota
111     Roberto INICIAL 3.5
222     Maria   SUPLETORIO      2.8
333     Yamile  INICIAL 4.6

 La estructura tiene la forma:
 struct Estudiante {
    int identificacion;
    char nombre[50];
    char tipoExamen[50];
    float nota;
};

 Desarrolle una funcion que cree dos archivos de texto llamados ```inicial.txt``` y ```supletorio.txt```. Cada tipo de archivo debe contener: El tipo de examen, el nombre y la nota obtenida por todos los estudiantes, el numero de examenes presentados, y la nota promedio de los examenes. Un ejemplo de este archivo es:

```bash
INICIAL
Roberto 3.5
Yamile 4.6
Numero de examenes presentados: 2
Nota promedio: 4.05
```
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Estudiante {
    int identificacion;
    char nombre[50];
    char tipoExamen[50];
    float nota;
};

void procesarExamenes(Estudiante *estudiantes, int numEstudiantes, const char* tipoExamen, const char* nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    archivoSalida << tipoExamen << endl;

    float suma = 0;
    int contador = 0;
    for (int i = 0; i < numEstudiantes; i++) {
        if (strcmp(estudiantes[i].tipoExamen, tipoExamen) == 0) {
            archivoSalida << estudiantes[i].nombre << " " << estudiantes[i].nota << endl;
            suma += estudiantes[i].nota;
            contador++;
        }
    }
    archivoSalida << "Numero de examenes presentados: " << contador << endl;
    archivoSalida << "Nota promedio: " << suma / contador << endl;
    archivoSalida.close();
}

int main() {
    ifstream archivoEntrada("notas.dat", ios::binary);
    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    // Contar el número de estudiantes en el archivo
    archivoEntrada.seekg(0, archivoEntrada.end);
    int numEstudiantes = archivoEntrada.tellg() / sizeof(Estudiante);
    archivoEntrada.seekg(0, archivoEntrada.beg);

    // Leer los estudiantes del archivo
    Estudiante *estudiantes = new Estudiante[numEstudiantes];
    archivoEntrada.read((char*)estudiantes, sizeof(Estudiante) * numEstudiantes);
    archivoEntrada.close();

    procesarExamenes(estudiantes, numEstudiantes, "INICIAL", "inicial.txt");
    procesarExamenes(estudiantes, numEstudiantes, "SUPLETORIO", "supletorio.txt");

    delete[] estudiantes;
    return 0;
}
