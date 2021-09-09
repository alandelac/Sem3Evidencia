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

    // Ubi a buscar
    string serieABuscar;
    cout << "Cual es la serie a buscar? (Primeros 3 caracteres del ubi): ";
    cin >> serieABuscar;

    //Vector de Ubis con posición igual al vector de registros
    vector<string>ubis;
    for(int i = 0; i<mivec.size();i++){
        ubis.push_back(mivec[i].ubi.substr(0, 3));
    }

    // [Low, ..., High] Rango de búsqueda para el UBI seleccionado
    // Búsqueda Binaria para cada límite, complejidad O(log(n)) 
    std::vector<string>::iterator low, up;

    low = std::lower_bound(ubis.begin(), ubis.end(), serieABuscar);
    up = std::upper_bound (ubis.begin(), ubis.end(), serieABuscar);

    //Convertir iterador en int
    int indexB = std::distance( ubis.begin(), low );
    int indexE = std::distance( ubis.begin(), up );

    if(indexB == 0 && indexE == 0){
        cout<<"No se encontro un registro con el UBI seleccionado"<<endl;
    } else {
        //Se imprimen todos los registros buscados por UBI
        for(int j = indexB ; j < indexE ; j++){
            cout << mivec[j].ubi << " " << mivec[j].fecha << " " << mivec[j].hora << " " << mivec[j].entrada  << endl ;
        }
    }

    return 0;
}