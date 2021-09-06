#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fecha.cpp"
using namespace std;

// Creación del struct registro para cada entrada
struct registro {
    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;
};

// Método para comparar dos registros (para ordenamiento)
bool acompare(registro lhs, registro rhs) {
    if(lhs.ubi == rhs.ubi) { 
        return lhs.fechaInt < rhs.fechaInt; // false si fecha anterior es menor que siguiente (con misma UBI)
    }
    return (lhs.ubi.compare(rhs.ubi) < 0); // -1 si dos registros son diferentes y 0 si son iguales
}

int main() {
    vector<registro> mivec; // vector de registros
    string nombreArchivo; // nombre del archivo
    ifstream archivoCanal; // apertura del archivo

    cout << "Introduce el nombre del archivo: ";
    cin >> nombreArchivo; 
    archivoCanal.open(nombreArchivo); 

    string fecha, hora, ubi;
    char entrada;
    int fechaInt;

    while (archivoCanal >> fecha >> hora >> entrada >> ubi) { // itera por cada línea del archivo
        registro reg;
        reg.fecha = fecha;
        reg.hora = hora;
        reg.entrada = entrada;
        reg.ubi = ubi;
        reg.fechaInt = ftoi(fecha); // método para pasar de formato DD-MM-YYYY a Int

        mivec.push_back(reg);
    }

    sort(mivec.begin(), mivec.end(), acompare); //QuickSort O(nlog(n))

    string serieABuscar;
    cout << "Cuál es la serie a buscar? (Primeros 3 caracteres del ubi): ";
    cin >> serieABuscar;

    // Búsqueda secuencial O(n)
    for(int i = 0; i < mivec.size(); i++) {
        if(serieABuscar == mivec[i].ubi.substr(0, 3)) {
            cout << mivec[i].ubi << " " << mivec[i].fecha << " " << mivec[i].hora << " " << mivec[i].entrada  << endl ;
        }
    }

    return 0;
}