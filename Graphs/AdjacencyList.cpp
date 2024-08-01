#include <bits/stdc++.h>
using namespace std;

void addEdgeDirected(vector<vector<int>>& adjacency, int u, int v) {
    adjacency[u].push_back(v);
}

void addEdgeUndirected(vector<vector<int>>& adjacency, int u, int v) {
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);
}

void showAdjacency(vector<vector<int>>& adjacency, int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int vecino : adjacency[i]) {
            cout << vecino << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    vector<vector<int>> adjacency_undirected(7);
    addEdgeUndirected(adjacency_undirected, 0, 1);
    addEdgeUndirected(adjacency_undirected, 0, 2);
    addEdgeUndirected(adjacency_undirected, 1, 3);
    addEdgeUndirected(adjacency_undirected, 1, 4);
    addEdgeUndirected(adjacency_undirected, 2, 5);
    addEdgeUndirected(adjacency_undirected, 2, 6);

    showAdjacency(adjacency_undirected, 7);

    vector<vector<int>> adjacency_directed(3);
    addEdgeDirected(adjacency_directed, 0, 1);
    addEdgeDirected(adjacency_directed, 0, 2);
    addEdgeDirected(adjacency_directed, 1, 3);
    addEdgeDirected(adjacency_directed, 1, 4);
    addEdgeDirected(adjacency_directed, 2, 5);
    addEdgeDirected(adjacency_directed, 2, 6);

    showAdjacency(adjacency_directed, 3);

}