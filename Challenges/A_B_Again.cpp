#include <bits/stdc++.h>

using namespace std;
int main()
{
	int t, suma = 0;
	cin >> t;
	string n;
	vector<string>v(t);
	for (int i = 0; i < t; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < v.size(); ++i)
	{
		n = v[i];
		
		suma = 0;
		for (int j = 0; j < n.size(); ++j)
		{	
		
			
			suma+= int(n[j]-'0');
		}
		cout << suma << endl;
	}
}


