#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>>& adjacency, int u, int v) {
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
}

int main(){

    vector<vector<int>> adjacency(7);
    addEdge(adjacency, 0, 1);
    addEdge(adjacency, 0, 2);
    addEdge(adjacency, 1, 3);
    addEdge(adjacency, 1, 4);
    addEdge(adjacency, 2, 5);
    addEdge(adjacency, 2, 6);

    showAdjacency(adjacency, 7);

}