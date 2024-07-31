
#include <bits/stdc++.h>
using namespace std;


void agregarArista(vector<vector<int>>& adyacencias, int u, int v) {
    adyacencias[u].push_back(v);
    adyacencias[v].push_back(u);
}

void imprimirArbol(vector<vector<int>>& adyacencias, int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int vecino : adyacencias[i]) {
            cout << vecino << " ";
        }
        cout << endl;
    }
}

int main(){

    vector<vector<int>> adyacencia(7);
    agregarArista(adyacencia, 0, 1);
    agregarArista(adyacencia, 0, 2);
    agregarArista(adyacencia, 1, 3);
    agregarArista(adyacencia, 1, 4);
    agregarArista(adyacencia, 2, 5);
    agregarArista(adyacencia, 2, 6);

    imprimirArbol(adyacencia, 7);

}