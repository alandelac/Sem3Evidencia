#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void loadGraph(int n, int m, vector<string> &puertos, vector<vector<int>> &listAdj) {
    string a, b;
    string puerto;
    int pos1, pos2;
    for(int j=0; j<n; j++) {
        cin >> puerto;
        puertos.push_back(puerto);
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        for(int k=0; k<puertos.size(); k++) {
            if(puertos[k].compare(a) == 0) {
                pos1 = k;   
            }
            if(puertos[k].compare(b) == 0) {
                pos2 = k; 
            }
        }
        listAdj[pos1].push_back(pos2);
        listAdj[pos2].push_back(pos1);
    }
}

void printMatAdj(vector<string> puertos, vector<vector<int>> &listAdj, int n) {
    for(int i=0; i<listAdj.size(); i++) {
        cout << (i) << " ";
        for(int j=0; j<listAdj[i].size(); j++) {
            cout << " ==> " << (listAdj[i][j]);
        }
        cout << endl;
    }
}

// Complejidad: O(|V| + |E|)
int BFS(string puerto, int mnp, vector<vector<int>> &listAdj,  vector<string> &puertos) {
    pair<int, int> pareja, parejaAux;
    queue<pair<int, int>> fila;
    vector<bool> status(listAdj.size(), false);
    int altura = 1;
    int pos;
    int contador = 1;

    for(int i = 0; i < puertos.size(); i++) {
        if(puertos[i].compare(puerto) == 0) {
            pos = i;
        }
    }
    status[pos] = true;
    
    for(int j = 0; j < listAdj[pos].size(); j++) {
        pareja.first = listAdj[pos][j];
        pareja.second = altura;
        fila.push(pareja);
    }

    
    while(!fila.empty() && fila.front().second <= mnp) {
        pareja = fila.front();
        fila.pop();

        if(status[pareja.first] == false) {
            contador++;
            status[pareja.first] = true;
        }

        for(int k = 0; k < listAdj[pareja.first].size(); k++) {
            parejaAux.first = listAdj[pareja.first][k];
            parejaAux.second = pareja.second + 1;
            fila.push(parejaAux);
        }
    }
    return listAdj.size() - contador;
}

int main () {
    int n,m, q, mnp;
    string puerto;
    cin >> n >> m; // n = nodos, m = arcos
    vector<string> puertos;
    vector<vector<int>> listAdj(n); // Lista de Adyacencias

    
    loadGraph(n, m, puertos, listAdj); // Hacer la matriz y lista de Adyacencias
    // printMatAdj(puertos, listAdj, n);

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> puerto;
        cin >> mnp;
        cout << BFS(puerto, mnp, listAdj, puertos) << endl;
    }
}