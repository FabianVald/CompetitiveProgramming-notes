#include <bits/stdc++.h>

using namespace std;


int main()
{
	int t, a_1, a_2, b_1, b_2;
	cin >> t; 
	int juegos_1 = 0;
	for (int i = 0; i < t; ++i)
	{	juegos_1 = 0;

		cin >> a_1 >> a_2 >> b_1 >> b_2;

		if ((a_1 >= b_1 && a_2 > b_2) || (a_1 > b_1 && a_2 >= b_2))
		{
			juegos_1+=2;
			
		}

		if ((a_1 >= b_2 && a_2 > b_1) || ((a_1 > b_2 && a_2 >= b_1)))
		{
			juegos_1+=2;
			
		}

		cout << juegos_1 << endl;
	}
}
