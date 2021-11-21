#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;

// Complejidad: O(n*m)
void loadGraph(int n, int m, vector<string> &puertos, vector<vector<int>> &listAdj)
{

    string a, b; // nombre de los puertos con conexion
    string puerto; // aux para guardar los puertos en la lista
    int pos1, pos2; // indices de los barcos en la lista

    // registrar los nombres de los puertos en la lista
    for (int j = 0; j < n; j++)
    {
        cin >> puerto;
        puertos.push_back(puerto);
    }

    // hacer las conexiones entre los puertos
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        // se busca el indice de los barcos a y b
        for (int k = 0; k < puertos.size(); k++)
        {
            if (puertos[k].compare(a) == 0)
            {
                pos1 = k;
            }
            if (puertos[k].compare(b) == 0)
            {
                pos2 = k;
            }
        }

        // se añade el indice en la lista de adjacencia
        listAdj[pos1].push_back(pos2);
        listAdj[pos2].push_back(pos1);
    }
}

// Complejidad: O(m*n)
void printMatAdj(vector<string> puertos, vector<vector<int>> &listAdj, int n)
{
    for (int i = 0; i < listAdj.size(); i++)
    {
        cout << (i) << " ";
        for (int j = 0; j < listAdj[i].size(); j++)
        {
            cout << " ==> " << (listAdj[i][j]);
        }
        cout << endl;
    }
}

// Complejidad: O(|V| + |E|)
int BFS(string puerto, int mnp, vector<vector<int>> &listAdj, vector<string> &puertos)
{
    pair<int, int> pareja, parejaAux;
    queue<pair<int, int>> fila;
    vector<bool> status(listAdj.size(), false);
    int altura = 1;
    int pos;
    int contador = 1;

    // se obtiene el indice del puerto a buscar
    for (int i = 0; i < puertos.size(); i++)
    {
        if (puertos[i].compare(puerto) == 0)
        {
            pos = i;
        }
    }
    status[pos] = true;

    // se agregan los vecinos a una fila
    for (int j = 0; j < listAdj[pos].size(); j++)
    {
        pareja.first = listAdj[pos][j];
        pareja.second = altura;
        fila.push(pareja);
    }

    // por cada vecino ir recoorriendo por el mnp
    while (!fila.empty() && fila.front().second <= mnp)
    {
        pareja = fila.front();
        fila.pop();

        if (status[pareja.first] == false)
        {
            contador++;
            status[pareja.first] = true;
        }

        for (int k = 0; k < listAdj[pareja.first].size(); k++)
        {
            parejaAux.first = listAdj[pareja.first][k];
            parejaAux.second = pareja.second + 1;
            fila.push(parejaAux);
        }
    }
    return listAdj.size() - contador;
}

int main()
{
    int n, m, q, mnp;
    string puerto;
    cin >> n >> m; // n = nodos, m = arcos
    vector<string> puertos;
    vector<vector<int>> listAdj(n); // Lista de Adyacencias

    loadGraph(n, m, puertos, listAdj); // Hacer la matriz y lista de Adyacencias
    // printMatAdj(puertos, listAdj, n);

    cin >> q;
    // recorrer los casos de prueba
    for (int i = 0; i < q; i++)
    {
        cin >> puerto;
        cin >> mnp;
        cout << "Case " << i + 1 << ": " << BFS(puerto, mnp, listAdj, puertos) << " ports not reachable from port " << puerto << " with MNP = " << mnp << "." << endl;
    }
}

/*
Input: Ejemplo con dos islas
16 14
A
B
C
D
E
F
G
H
I
J
K
L
M
N
O
P
A E
A B
C G
D F
E F
F G
G J
H L
I J
I N
K O
L O
M N
O P
3
G 3
L 5 
J 7

Output:
Case 1: 7 ports not reachable from port G with MNP = 3.
Case 2: 11 ports not reachable from port L with MNP = 5.
Case 3: 5 ports not reachable from port J with MNP = 7.
*/