#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, suma=0, count = 0;
	vector<string> grilla;
	string entrada;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{   cin >> entrada;
		grilla.push_back(entrada);
	}


	for (string tile:grilla)
	{
		count = 0;
		for (int i = 0; i < tile.size()-1; ++i)
		{
			if (tile[i]=='N' && tile[i+1]=='N')
			{
				suma+=1;
				count+=1;
				i+=1;
			}

		}
		// cout <<"puedo en "<< tile << " "<< count << " veces" << endl;
	}
	cout << suma << endl;

}