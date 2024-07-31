#include <bits/stdc++.h>

using namespace std;


int main()
{	
	int t,n,m;
	cin >> t;

	vector<vector<vector<int>>> collection(t);

	for (int t_ = 0; t_ < t; ++t_){
		cin >> n >> m;
		vector<vector<int>> v(n,vector<int>(m,0));
		for(int row = 0; row < n; ++row){
			for (int column = 0; column < m; ++column)
			{
				cin >> v[row][column];
			}
		}
		collection[t_] = v;
	}

	for (int t_ = 0; t_ < t; ++t_){
		vector<vector<int>>  Matriz = collection[t_];
		for(int row = 0; row < Matriz.size(); ++row){
			for (int column = 0; column < Matriz[row].size(); ++column)
			{
				cout << Matriz[row][column];
			}
			cout << endl;
		}
	}



	return 0;	
}