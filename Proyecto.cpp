#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fecha.cpp"
using namespace std;

struct registro {
    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;
};

bool acompare(registro lhs, registro rhs) {
    if(lhs.ubi == rhs.ubi) {
        return lhs.fechaInt < rhs.fechaInt;
    }
    return (lhs.ubi.compare(rhs.ubi) < 0);
}

int main() {
    vector<registro> mivec;
    string nombreArchivo;
    ifstream archivoCanal;

    cout << "Introduce el nombre del archivo: ";
    cin >> nombreArchivo;
    archivoCanal.open(nombreArchivo);

    string fecha, hora, ubi;
    char entrada;
    int fechaInt;

    while (archivoCanal >> fecha >> hora >> entrada >> ubi) {
        registro reg;
        reg.fecha = fecha;
        reg.hora = hora;
        reg.entrada = entrada;
        reg.ubi = ubi;

        reg.fechaInt = ftoi(fecha);

        // cout << reg.fecha << " " << reg.hora << " " << reg.entrada << " " << reg.ubi << " " << reg.fechaInt << endl ;
        mivec.push_back(reg);
    }

    sort(mivec.begin(), mivec.end(), acompare);

    string serieABuscar;
    cout << "Cuál es la serie a buscar? (Primeros 3 caracteres del ubi): ";
    cin >> serieABuscar;

    for(int i = 0; i < mivec.size(); i++) {
        if(serieABuscar == mivec[i].ubi.substr(0, 3)) {
            cout << mivec[i].ubi << " " << mivec[i].fecha << " " << mivec[i].hora << " " << mivec[i].entrada  << endl ;
        }
    }

    return 0;
}