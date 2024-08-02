#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	

	int n;
	cin >> n;
	vector<string> vec(n);
	string palabra, word;
	

	for (int i = 0; i < n; ++i)
	{
		cin >> palabra;
		if (palabra.length()>10)
		{
			word = palabra[0]+to_string(palabra.length()-2)+palabra[palabra.length()-1];
			// cout << word << endl;
			vec[i] = word;
		}
		else{vec[i]=palabra;}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i]<<endl;;
	}

	return 0;
}