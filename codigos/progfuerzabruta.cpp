#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include "funcostos.h"

using namespace std;

int DME_Fuerza_Bruta(const string &cadena1, const string &cadena2, int i, int j) {
    if (i == 0) return j * costo_ins(cadena2[j - 1]);
    if (j == 0) return i * costo_del(cadena1[i - 1]);

    if (cadena1[i - 1] == cadena2[j - 1]) {
        return DME_Fuerza_Bruta(cadena1, cadena2, i - 1, j - 1);
    }

    int insertar = DME_Fuerza_Bruta(cadena1, cadena2, i, j - 1) + costo_ins(cadena2[j - 1]);
    int eliminar = DME_Fuerza_Bruta(cadena1, cadena2, i - 1, j) + costo_del(cadena1[i - 1]);
    int sustituir = DME_Fuerza_Bruta(cadena1, cadena2, i - 1, j - 1) + costo_sub(cadena1[i - 1], cadena2[j - 1]);

    int transponer = INT_MAX;
    if (i > 1 && j > 1 && cadena1[i - 1] == cadena2[j - 2] && cadena1[i - 2] == cadena2[j - 1]) {
        transponer = DME_Fuerza_Bruta(cadena1, cadena2, i - 2, j - 2) + costo_trans(cadena1[i - 2], cadena1[i - 1]);
    }
    return min({insertar, eliminar, sustituir, transponer});
}

int main() {
    string cadena1, cadena2;
    ifstream archivo("cadenas.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo cadenas.txt" << endl;
        return 1;
    }

    getline(archivo, cadena1);
    getline(archivo, cadena2);
    archivo.close();

    int distancia = DME_Fuerza_Bruta(cadena1, cadena2, cadena1.size(), cadena2.size());
    cout << "La distancia minima de edicion es: " << distancia << endl;
    return 0;
}