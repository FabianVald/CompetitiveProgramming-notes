#include <bits/stdc++.h>
using namespace std;



int main()
{
	string s;
	cin >> s;
	queue<int>sumas;
	int lugar, contador=0;
	int count = 0;

	for (int i = 0; i <= s.size(); ++i)
	{
		if (s[i]=='+') count++;
		else count--;
		if (sumas.empty())
		{
			sumas.push(count);
		}
		if (count > sumas.front()){
			sumas.pop(); 
			sumas.push(count);
			lugar = contador; }
			
				
		contador++;
	}
	cout << lugar+1<< '\n';

	return 0;
}