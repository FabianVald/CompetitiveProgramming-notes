#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,k, t,celdas;
	vector<int>memory;
	
	cin >> t;
	for (int i = 0; i < t; ++i)
	{   
		cin >> n >> k;


		if (k==(2*n-1))
		{
			celdas = n*n;
		}

		else if (k%2==0){
			celdas = k/2;
			celdas = celdas*(celdas+1);
		}

		else{
			celdas = k/2+1;
			celdas = celdas*(celdas);
		}
		memory.push_back(celdas);

	}

	for (int i = 0; i < memory.size(); ++i)
	{
		cout << memory[i] << endl;
	}
	return 0;
}