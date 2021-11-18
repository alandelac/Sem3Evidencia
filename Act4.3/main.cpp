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
        cout << (puertos[i]) << " ";
        for(int j=0; j<listAdj[i].size(); j++) {
            cout << " ==> " << (puertos[listAdj[i][j]]);
        }
        cout << endl;
    }
}

// Complejidad: O(|V| + |E|)
void BFS(string puerto, int mnp, vector<vector<int>> &listAdj,  vector<string> &puertos) {
    pair<int, int> pareja;
    queue<pair<int, int>> fila;
    vector<bool> status(listAdj.size(), false);
    int altura = 1;
    int pos;

    for(int i = 0; i < puertos.size(); i++) {
        if(puertos[i].compare(puerto) == 0) {
            pos = i;
        }
    }
     
    for(int j = 0; j < listAdj.size(); j++) {
        for(int k = 0; k<listAdj[pos].size(); k++) {
            
        }
    }





    
    // for (int i=0; i<listAdj.size(); i++) {
    //     if(!status[i]) {
    //         pareja.first = i;
    //         pareja.second = altura;
    //         fila.push(pareja);
    //         status[i] = true;
            
    //         while (!fila.empty()) {
    //             dato = fila.front();
    //             fila.pop();
    //             cout <<  (dato+1) << " ";
    //             for(int j=0; j<listAdj[dato].size(); j++) {
    //                 if(!status[listAdj[dato][j]]) {
    //                     fila.push(listAdj[dato][j]);
    //                     status[listAdj[dato][j]] = true;
    //                 }
    //             }
    //         }
    //     }
    // }
}

int main () {
    int n,m, q, mnp;
    string puerto;
    cin >> n >> m; // n = nodos, m = arcos
    vector<string> puertos;
    vector<vector<int>> listAdj(n); // Lista de Adyacencias

    
    loadGraph(n, m, puertos, listAdj); // Hacer la matriz y lista de Adyacencias

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> puerto;
        cin >> mnp;
        BFS(puerto, mnp, listAdj, puertos);
    }


    // printMatAdj(puertos, listAdj, n);
    
}