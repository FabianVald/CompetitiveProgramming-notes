#include <bits/stdc++.h>

using namespace std;


// Breadth First Search (BFS)  ---->  O(Vertices+Edges)
// Useful for finding the shortest path on unweighted graphs

// ===================================
// 				  Nodes and Adjacency
// ===================================
void addEdge(vector<vector<int>>& adjacency, int u, int v) 
{
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);
}

void showAdjacency(vector<vector<int>>& adjacency, int n) 
{
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int vecino : adjacency[i]) {
            cout << vecino << " ";
        }
        cout << endl;
    }
}


// ===================================
// 				  BFS
// ===================================
vector<int> solve(int s, int n, vector<vector<int>>& adjacency ){

	// Solve bfs, creating a queue and visiting neighbors of each node

	queue<int> q;
	int node;
	vector<int> neighbors;
	q.push(s);
	vector<bool> visited(n,false);
	visited[s]=true;
	vector<int> prev(n,-1); // create a vector with null values

	while (!q.empty()){  //verify that q isn't empty
		node = q.front(); // take a first value in queue
		q.pop();		  // eliminate this node
		neighbors= adjacency[node]; // get neighbors
		for (int next : neighbors)  // iterate each neighbor
		{
			if (!visited[next]){
				q.push(next);       // add new node to start
				visited[next]=true; // the node is visited
				prev[next] = node;  // add the prev node 
			}
		}
	}
	return prev;
}

vector<int> reconstructPath(int s, int e, vector<int>& prev)
{
	// Reconstruct path from end to initial node
	vector<int> path;
	for (int at = e; at!=(-1); at = prev[at]) {path.push_back(at);} //prev[at] is node prev at
	reverse(path.begin(), path.end()); 
	if (path[0]==s){return path;} 
	return {};
}

vector<int> bfs(int s, int e, int n, vector<vector<int>>& adjacency) // start node, end node
{
	vector<int> prev = solve(s, n, adjacency);
	return reconstructPath(s,e,prev);
}

int main()
{
	int n = 13;
	vector<vector<int>> adjacency_list(n);

	addEdge(adjacency_list,0,9);
	addEdge(adjacency_list,0,11);
	addEdge(adjacency_list,0,7);
	addEdge(adjacency_list,9,8);
	addEdge(adjacency_list,9,10);
	addEdge(adjacency_list,10,1);
	addEdge(adjacency_list,8,1);
	addEdge(adjacency_list,8,12);
	addEdge(adjacency_list,12,2);
	addEdge(adjacency_list,2,3);
	addEdge(adjacency_list,3,4);
	addEdge(adjacency_list,7,3);
	addEdge(adjacency_list,7,6);
	addEdge(adjacency_list,6,5);
	addEdge(adjacency_list,11,7);

	showAdjacency(adjacency_list,n);
    vector<int>pathh;
	pathh = bfs(10, 4, n, adjacency_list);// start node, end node
	
	for (int m :pathh)
	{
		cout << m <<endl;
	}
	return 0;
}








