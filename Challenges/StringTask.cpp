#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string palabra, letra, newstring;
	string vec[6] = {"a","e","i","o","u", "y"};


	cin >> palabra;
	
	int count;
	for (int i = 0; i < palabra.length(); ++i)
	{	count = 0;
		letra = tolower(palabra[i]);
		
		for (int j = 0; j < 6; ++j)
		{
			if (letra!=vec[j])
			{
				count++;
			}
			if (count==6)
			{
				newstring = newstring+"."+letra;
			}
		}
	}
	cout << newstring << endl;
	return 0;
}