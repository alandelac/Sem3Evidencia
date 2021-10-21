#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fecha.cpp"
using namespace std;

// Creación del struct registro para cada entrada
struct registro
{
    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;
};

struct contBuques
{
    string fechaSalida;
    int contMedi;
    int contRojo;
};

#include "LinkedList.h"

int main()
{

    LinkedList<registro> listMediterraneo;
    LinkedList<registro> listRojo;
    LinkedList<registro> listaCompleta;

    string nombreArchivo;  // nombre del archivo
    ifstream archivoCanal; // apertura del archivo

    cout << "Introduce el nombre del archivo: ";
    cin >> nombreArchivo;
    archivoCanal.open(nombreArchivo);

    string fecha, hora, ubi;
    char entrada;
    int fechaInt;

    // complejidad O(n)
    while (archivoCanal >> fecha >> hora >> entrada >> ubi)
    { // itera por cada línea del archivo
        registro reg;
        reg.fecha = fecha;
        reg.hora = hora;
        reg.entrada = entrada;
        reg.ubi = ubi;
        reg.fechaInt = ftoi(fecha); // método para pasar de formato DD-MM-YYYY a Int

        if (reg.entrada == 'M')
        {
            listMediterraneo.addLast(reg);
        }
        else
        {
            listRojo.addLast(reg);
        }
        listaCompleta.addLast(reg);
    }

    // se sortean todas las listas
    listaCompleta.SortListBy3UBI();
    listMediterraneo.SortList();
    listRojo.SortList();

    // guardar las listas del mar rojo y mediterraneo en un .txt
    string archM;
    cout << "Como quieres que se llame el archivo Mediterraneo?" << endl;
    cin >> archM;
    listMediterraneo.saveInFile(archM);
    string archR;
    cout << "Como quieres que se llame el archivo Rojo?" << endl;
    cin >> archR;
    listRojo.saveInFile(archR);

    // Ubi a buscar
    string serieABuscar;
    cout << "Cual es la serie a buscar? (Primeros 3 caracteres del ubi): ";
    cin >> serieABuscar;

    listaCompleta.buscarUbiPorMes(serieABuscar);

    return 0;
}