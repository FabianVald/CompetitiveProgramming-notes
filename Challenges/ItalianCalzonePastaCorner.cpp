#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> direcciones = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int grilla[100][100];
pair<int, int> posiciones[100 * 100];

bool esMovimientoValido(int x, int y, int valorPrevio, const vector<int>& visitadoLocal) {
    if (x < 0 || y < 0 || x >= 100 || y >= 100) return false;
    if (grilla[x][y] < valorPrevio) return false;
    if (visitadoLocal[grilla[x][y]]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int filas, columnas;
    cin >> filas >> columnas;

    vector<int> visitado(filas * columnas, 0);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> grilla[i][j];
            grilla[i][j]--;
            posiciones[grilla[i][j]] = {i, j};
        }
    }

    int platosComidos = 0;

    for (int i = 0; i < filas * columnas; ++i) {
        if (visitado[i]==false) {
            vector<int> visitadoLocal(filas * columnas, 0);
            queue<int> cola;
            cola.push(i);
            visitadoLocal[i] = 1;
            int longitudActual = 0;

            while (!cola.empty()) {
                int actual = cola.front(); cola.pop();
                visitado[actual] = 1;
                int x = posiciones[actual].first, y = posiciones[actual].second;
                longitudActual++;

                for (auto& dir : direcciones) {
                    int pos_x = x + dir.first, pos_y = y + dir.second;
                    if (esMovimientoValido(pos_x, pos_y, grilla[x][y], visitadoLocal)) {
                        visitadoLocal[grilla[pos_x][pos_y]] = 1;
                        cola.push(grilla[pos_x][pos_y]);
                    }
                }
            }

            platosComidos = max(platosComidos, longitudActual);
        }
    }

    cout << platosComidos << endl;

    return 0;
}
