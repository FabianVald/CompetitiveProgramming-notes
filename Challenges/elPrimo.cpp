#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t;
	string binario;
	cin >> t;
	vector<string> vec(t, "No");

	for (int i = 0; i < t; ++i)
	{
		cin >> binario;
		for (int j = 0; j < binario.length()-1; ++j)
		{	
			if (binario!="1")
			{			
				if (binario[j]=='1'){
					vec[i] = "Yes";
					break;
			}}
		}
	}
		
	for (int i = 0; i < t; ++i)
	{
		cout << vec[i] << endl;
	}
	
	return 0;
}	