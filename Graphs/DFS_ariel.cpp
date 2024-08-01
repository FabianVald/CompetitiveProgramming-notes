#include <bits/stdc++.h>
using namespace std;

void addEdgeDirected(vector<vector<int>>& adjacency, int u, int v) {
    adjacency[u].push_back(v);
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


// 			===================================
//   			 DFS ALGORITHM WITHOUT WEIGHT
// 			===================================

vector<vector<int>> AdjList;
vector<int>dfs_num;

void dfs(int u) {
    cout << "Visiting Vertice: " << u << endl;
    dfs_num[u] = 1;

    for (int i = 0; i < (int)AdjList[u].size(); ++i) {
        int v = AdjList[u][i];
        if (dfs_num[v] == 0) {
            cout << "Exploring from " << u << " to " << v << endl;
            dfs(v);
        }
    }
}


int main()
{
 	int n=5;
 	dfs_num.resize(n);
 	AdjList.resize(n);
	addEdgeDirected(AdjList,0,1);
	addEdgeDirected(AdjList,0,2);
	addEdgeDirected(AdjList,1,3);
	addEdgeDirected(AdjList,2,3);
	addEdgeDirected(AdjList,3,4);

	showAdjacency(AdjList,5);

	dfs(0); // dfs from 0 to all

	return 0;
}