#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "funcostos.h"

using namespace std;

//----------------------FUNCION DE OBTENCION COSTO INSERCION----------------------

int costo_ins(char a) {
    int costo = 0;
    int indice = a - 'a';

    ifstream archivo("cost_insert.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return -1;
    }
    string linea;

    if (getline(archivo, linea)) {
        istringstream iss(linea);
        vector<int> costos;

        int valor;
        while (iss >> valor) {
            costos.push_back(valor);
        }

        costo = costos[indice];
    }
    archivo.close();
    return costo;
}

//---------------------FUNCION DE OBTENCION COSTO ELIMINACION---------------------

int costo_del(char a) {
    int costo = 0;
    int indice = a - 'a';

    ifstream archivo("cost_delete.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return -1;
    }
    string linea;
    
    if (getline(archivo, linea)) {
        istringstream iss(linea);
        vector<int> costos;

        int valor;
        while (iss >> valor) {
            costos.push_back(valor);
        }

        costo = costos[indice];
    }
    archivo.close();
    return costo;
}

//---------------------FUNCION DE OBTENCION COSTO SUSTITUCION---------------------

int costo_sub(char a, char b) {
    int costo = 0;
    int fila_objetivo = b - 'a';
    int columna_objetivo = a - 'a';

    ifstream archivo("cost_replace.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return -1;
    }

    string linea;
    for (int fila = 0; fila <= fila_objetivo; fila++) {
        getline(archivo, linea);
    }
    istringstream iss(linea);
    for (int columna = 0; columna <= columna_objetivo; columna++) {
        iss >> costo;
    }
    return costo;
}

//--------------------FUNCION DE OBTENCION COSTO TRANSPOSICION--------------------

int costo_trans(char a, char b) {
    int costo = 0;
    int fila_objetivo = b - 'a';
    int columna_objetivo = a - 'a';

    ifstream archivo("cost_transpose.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return -1;
    }

    string linea;
    for (int fila = 0; fila <= fila_objetivo; fila++) {
        getline(archivo, linea);
    }
    istringstream iss(linea);
    for (int columna = 0; columna <= columna_objetivo; columna++) {
        iss >> costo;
    }
    return costo;
}