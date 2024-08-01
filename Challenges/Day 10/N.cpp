#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>& adjacency, int u, int v) 
{
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);
}

void precomputeDistances(int n, const vector<vector<int>>& adjacency, vector<vector<int>>& distances)
{
    for (int start = 0; start < n; ++start) {
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> dist(n, -1);
        
        q.push(start);
        visited[start] = true;
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjacency[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    dist[neighbor] = dist[node] + 1;
                }
            }
        }

        distances[start] = dist;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adjacency(n);

    // Read edges
    for (int i = 0; i < n - 1; ++i) {
        int nodo_1, nodo_2;
        cin >> nodo_1 >> nodo_2;
        --nodo_1; // Convertir a índice 0-based
        --nodo_2; // Convertir a índice 0-based
        addEdge(adjacency, nodo_1, nodo_2);
    }

    // Precompute distances
    vector<vector<int>> distances(n, vector<int>(n));
    precomputeDistances(n, adjacency, distances);

    // Read queries
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int q_1, q_2;
        cin >> q_1 >> q_2;
        --q_1; // Convertir a índice 0-based
        --q_2; // Convertir a índice 0-based
        queries[i] = {q_1, q_2};
    }

    // Process and print results for all queries
    for (const auto& query : queries) {
        int q_1 = query.first;
        int q_2 = query.second;
        cout << distances[q_1][q_2] << endl;
    }

    return 0;
}
