#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int LOG = 21;

vector<vector<int>> adj(MAXN);
int depth[MAXN];
int parent[MAXN];
int ancestros[MAXN][LOG];
int n;

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    for (int next : adj[node]) {
        if (next != par) {
            dfs(next, node, d + 1);
        }
    }
}

void preprocesar() {
    for (int j = 0; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 0)
                ancestros[i][j] = parent[i];
            else {
                if (ancestros[i][j - 1] != -1)
                    ancestros[i][j] = ancestros[ancestros[i][j - 1]][j - 1];
                else
                    ancestros[i][j] = -1;
            }
        }
    }
}

int obtenerLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = ancestros[u][i];
        }
    }

    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (ancestros[u][i] != ancestros[v][i]) {
            u = ancestros[u][i];
            v = ancestros[v][i];
        }
    }
    return parent[u];
}

int main() {
    int q, a, b;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        depth[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    preprocesar();

    vector<int> resultados;
    while (q--) {
        cin >> a >> b;
        int lca = obtenerLCA(a, b);
        int distancia = depth[a] + depth[b] - 2 * depth[lca];
        resultados.push_back(distancia);
    }

    for (int res : resultados) {
        cout << res << endl;
    }

    return 0;
}
