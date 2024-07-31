#include <bits/stdc++.h>

using namespace std;


int main()
{

	// Add Right, Eliminate Right
	stack<int> pila;

	pila.push(3); 	// add right place
	pila.push(20);  // add right place
	pila.push(30);  // add right place
	pila.push(40);  // add right place
	pila.pop();     // eliminate first value in right

	cout << pila.top() << endl;  // show first value

	return 0;
}