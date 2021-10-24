#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#include "BST.h"
#include "fecha.cpp"

int main()
{
    BST arbolRojo;
    BST arbolMedi;

    string nombreArchivoRojo;  // nombre del archivo
    ifstream archivoCanalRojo; // apertura del archivo

    string nombreArchivoMedi;  // nombre del archivo
    ifstream archivoCanalMedi; // apertura del archivo

    cout << "Introduce el nombre del archivo del Mar Rojo: ";
    cin >> nombreArchivoRojo;
    archivoCanalRojo.open(nombreArchivoRojo);

    cout << "Introduce el nombre del archivo del Mar Mediterraneo: ";
    cin >> nombreArchivoMedi;
    archivoCanalMedi.open(nombreArchivoMedi);

    string fecha, hora, ubi;
    char entrada;
    int fechaInt;
    int contador = 1;
    string aux;
    archivoCanalRojo >> ubi >> fecha >> hora >> entrada;
    aux = ubi;

    // aqui se construye el BST para el canal rojo
    while (archivoCanalRojo >> ubi >> fecha >> hora >> entrada)
    { 
        // si el ubi es diferente termina de contar y agrega al arbol, sigue con la sig ubi
        if (aux.substr(0, 3) != ubi.substr(0, 3)) {
            dataCS temp1(contador, aux.substr(0, 3));
            arbolRojo.add(temp1);
            contador = 0;
            aux = ubi;
        }
        contador++;
    }
    dataCS temp1(contador, ubi.substr(0, 3));
    arbolRojo.add(temp1);

    // aqui se construye el BST para el canal medi
    archivoCanalMedi >> ubi >> fecha >> hora >> entrada;
    aux = ubi;
    contador = 1;
    while (archivoCanalMedi >> ubi >> fecha >> hora >> entrada)
    { 
        // si el ubi es diferente termina de contar y agrega al arbol, sigue con la sig ubi
        if (aux.substr(0, 3) != ubi.substr(0, 3)) {
            dataCS temp2(contador, aux.substr(0, 3));
            arbolMedi.add(temp2);
            contador = 0;
            aux = ubi;
        }
        contador++;
    }
    dataCS temp2(contador, ubi.substr(0, 3));
    arbolMedi.add(temp2);

    // se imprimen los resultados de ambos arboles
    cout << "Entradas Mar ROJO" << endl;
    arbolRojo.print();
    cout << "Entradas Mar MEDITERRANEO" << endl;
    arbolMedi.print();

    





    return 0;
}