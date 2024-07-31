#include <bits/stdc++.h>

using namespace std;


int main()
{

	// Add Right, Eliminate Left
	queue<int> cola;

	cola.push(3); 	// add right place
	cola.push(20);  // add right place
	cola.push(30);  // add right place
	cola.pop();     // eliminate first value in left

	cout << cola.front() << endl;  // show first value

	return 0;
}