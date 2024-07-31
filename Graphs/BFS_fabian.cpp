#include <bits/stdc++.h>

using namespace std;


// Breadth First Search (BFS)  ---->  O(Vertices+Edges)
// Useful for finding the shortest path on unweighted 
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


vector<int> solve(vector<vector<int>>& adjacency,int s, int n){
	queue<int> q;
	q.push(s);

	vector<bool> visited(n,false);
	visited[s] = true;

	vector<int> prev(n,-1);
	int node;
	vector<int> neighbours;
	while(!q.empty()) {
		node = q.front();
		q.pop();
		neighbours = adjacency[node];

		for (int next :neighbours){
			if (!visited[next]){
				q.push(next);
				visited[next] = true;
				prev[next] = node;
			}
		}
	}
	return prev;
}

vector<int> reconstructPath(int s, int e, vector<int>& prev){
	vector<int> path;
	for(int at = e; at != -1; at = prev[at]){
		path.push_back(at);
	}	

	reverse(path.begin(), path.end());
	if (path[0] == s)
	{
		return path;
	}
	return {};
}


vector<int> bfs(vector<vector<int>>& adjacency,int s, int e, int n)
{	
		//BFS Starting at node s
		vector<int> prev(n);
		prev = solve(adjacency,s,n);
	
		// s -> e
		return reconstructPath(s, e, prev);
	}


int main()
{
	int n = 13;
	vector<vector<int>> adjacency(n);
	addEdge(adjacency,0,9);
	addEdge(adjacency,0,11);
	addEdge(adjacency,0,7);
	addEdge(adjacency,9,8);
	addEdge(adjacency,9,10);
	addEdge(adjacency,8,1);
	addEdge(adjacency,10,1);
	addEdge(adjacency,8,12);
	addEdge(adjacency,12,2);
	addEdge(adjacency,2,3);
	addEdge(adjacency,3,4);
	addEdge(adjacency,7,3);
	addEdge(adjacency,7,6);
	addEdge(adjacency,6,5);
	addEdge(adjacency,11,7);
	showAdjacency(adjacency,n);


	vector<int> path_result = bfs(adjacency,1,9,n);


	for (int i : path_result)
	{
		cout << i << endl;
	}
	return 0;
}