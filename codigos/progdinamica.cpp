#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "funcostos.h"

using namespace std;

int DME_Programacion_Dinamica(const string &cadena1, const string &cadena2) {
    int m = cadena1.size();
    int n = cadena2.size();

    vector<vector<int>> matriz(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) matriz[i][0] = i * costo_del(cadena1[i - 1]);
    for (int j = 0; j <= n; ++j) matriz[0][j] = j * costo_ins(cadena2[j - 1]);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cadena1[i - 1] == cadena2[j - 1]) {
                matriz[i][j] = matriz[i - 1][j - 1];
            } else {
                matriz[i][j] = min({
                    matriz[i - 1][j] + costo_del(cadena1[i - 1]),
                    matriz[i][j - 1] + costo_ins(cadena2[j - 1]),
                    matriz[i - 1][j - 1] + costo_sub(cadena1[i - 1], cadena2[j - 1])
                });
            }

            if (i > 1 && j > 1 && cadena1[i - 1] == cadena2[j - 2] && cadena1[i - 2] == cadena2[j - 1]) {
                matriz[i][j] = min(matriz[i][j], matriz[i - 2][j - 2] + costo_trans(cadena1[i - 1], cadena1[i - 2]));
            }
        }
    }
    return matriz[m][n];
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

    int distancia = DME_Programacion_Dinamica(cadena1, cadena2);
    cout << "La distancia minima de edicion es: " << distancia << endl;
    return 0;
}
