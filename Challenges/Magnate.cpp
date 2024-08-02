//#include </Users/ariel/Documents/CIPC/bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cantidad=1, mes = 0, suma_dolares = 0;
	int a, b, c;

	cin >> a >> b >> c; // costo de un edificio,
						// la ganancia mensual de cada uno, 
						//y la cantidad de edificios que Carlos quiere
	// 5 1 2
	//   5
	while(cantidad<c){
		mes+=1;
		suma_dolares+=(cantidad*b);
		//cout << "Dinero actual: " <<suma_dolares<<endl;
		if (suma_dolares>=a)
		{

			cantidad+=(suma_dolares/a); // 4
			//cout << "cantidad: " << cantidad << endl;
			suma_dolares -= (suma_dolares/a)*a;
		}

	}
	cout << mes << endl;
	return 0;
}