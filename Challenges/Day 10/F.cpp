#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}


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

	/*for (int t_ = 0; t_ < t; ++t_){
		vector<vector<int>>  Matriz = collection[t_];
		for(int row = 0; row < Matriz.size(); ++row){
			for (int column = 0; column < Matriz[row].size(); ++column)
			{
				cout << Matriz[row][column];
			}
			cout << endl;
		}
	}*/

	for(int t_ = 0; t_ < t; ++t_){
		vector<vector<int>>  Matriz = collection[t_];      
        vector<vector<int>> dp(Matriz.size(), vector<int>(Matriz[0].size()));

        dp[0][0] = Matriz[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int top = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = Matriz[i][j];
                if (top > 0) {
                    dp[i][j] = max(dp[i][j], GCD(dp[i][j], top));
                }
                if (left > 0) {
                    dp[i][j] = max(dp[i][j], GCD(dp[i][j], left));
                }
            }
        }

        cout << dp[n - 1][m - 1] << "\n";

    }


	return 0;	
}