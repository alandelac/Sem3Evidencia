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

#include "LinkedList.h"
int main() {
    
    LinkedList<registro> listMediterraneo;
    LinkedList<registro> listRojo;
    //LinkedList<registro> listaCompleta;

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

        if(reg.entrada == 'M'){
            listMediterraneo.addLast(reg);
        } else {
            listRojo.addLast(reg);
        }
        //listaCompleta.addLast(reg);
    }
    
    //listaCompleta.SortListBy3UBI();
    
    listMediterraneo.SortList();
    listRojo.SortList();
    

    string archM;
    cout <<"Como quieres que se llame el archivo Mediterraneo?"<<endl;
    cin >> archM;
    listMediterraneo.saveInFile(archM);
    string archR;
    cout <<"Como quieres que se llame el archivo Rojo?"<<endl;
    cin >> archR;
    listRojo.saveInFile(archR);

    // Ubi a buscar
    //string serieABuscar;
    //cout << "Cual es la serie a buscar? (Primeros 3 caracteres del ubi): ";
    //cin >> serieABuscar;

    //listaCompleta.buscarUbiPorMes(serieABuscar);
    
    /*
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
*/
    return 0;
}