#include <bits/stdc++.h>

using namespace std;
	
void AddConection(vector<vector<int>>& adjacencyMatrix,int i, int j) {
	adjacencyMatrix[i][j] = 1;
}


void showAdjacencyMatrix(vector<vector<int>>& adjacencyMatrix){
	for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = 0; j < adjacencyMatrix.size(); ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
   }
}

int main()
{	int n = 8;
	vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

	AddConection(adjacencyMatrix,0,0);
	AddConection(adjacencyMatrix,7,2);
	AddConection(adjacencyMatrix,5,3);
	showAdjacencyMatrix(adjacencyMatrix);

	return 0;
}