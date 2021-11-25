#include <iostream>
#include <unordered_map>
using namespace std;

// Complejidad O(n + m) // párrafos + palabras
int main() {
    int palabras;
    int q;
    int contador = 0;

    string aux;
    int cant;
    unordered_map<string, int> mapa;

    cin >> palabras;
    cin >> q;
    
    // En este for se añaden los datos al mapa
    for(int i=0; i<palabras; i++) {
        cin >> aux;
        cin >> cant;

        if(mapa.find(aux) == mapa.end()) { // No esta el dato a encontrar
            mapa[aux] = cant;
        } else {
            mapa[aux] = mapa[aux] + cant;
        }
    }

    // Se itera cada caso
    for(int i=0;  i<q; i++) {
        contador = 0;
        cin >> aux;

        // Se itera palabra por palabra hasta el punto final
        while(aux.compare(".") != 0) {
            // Si coincide con un dato en el mapa, entonces  se añade al contador
            if(mapa.find(aux) != mapa.end()) {
                contador = contador + mapa[aux];
            }
            cin >> aux;
        }
        cout << contador << endl;
    }
}