#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
vector<int> grafo[MAXN];
vector<int> visitado(MAXN);

void dfs(int nodo, int excluido) {
    visitado[nodo] = 1;
    for (auto indice : grafo[nodo]) {
        if (indice != excluido && !visitado[indice]) {
            dfs(indice, excluido);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cantidadPersonas; cin >> cantidadPersonas;
    vector<pair<int, int>> solicitudes(cantidadPersonas);

    for (int i = 0; i < cantidadPersonas; ++i) {
        int x, y; cin >> x >> y; x--; y--;
        solicitudes[i] = {x, y};
        grafo[x].push_back(i);
        grafo[y].push_back(i);
    }

    for (int i = 0; i < cantidadPersonas; ++i) {
        vector<int> accesibilidad(cantidadPersonas, 0);
        vector<int> nodosARevisar = {i, solicitudes[i].first, solicitudes[i].second};

        for (int nodo : nodosARevisar) {
            fill(visitado.begin(), visitado.end(), 0);
            dfs(nodo, i);
            for (int j = 0; j < cantidadPersonas; ++j) {
                accesibilidad[j] += visitado[j];
            }
        }

        bool puedePerderDinero = false;
        for (int j = 0; j < cantidadPersonas; ++j) {
            if (accesibilidad[j] == 3) {
                puedePerderDinero = true;
                break;
            }
        }
        cout << (puedePerderDinero ? "Y" : "N");
    }
    cout << "\n";
}
