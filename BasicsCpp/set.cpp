#include <bits/stdc++.h>

using namespace std;


// Set add sorted elements and each element doesn't repeat
int main(){

    set<int> mySet;

    // Insert elements
    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(7);
    mySet.insert(5); // doesn't add, because 5 was.

    // print elements

    cout << "Set elements: ";
    for (int elem : mySet) {cout << elem << " ";}
    cout << endl;

    // Check element in set with set.find() 
	// myset.end() is useful for check
    if (mySet.find(3) != mySet.end()) {
        cout << "Element 3 is in Set." << endl;
    } else {
        cout << "Element 3 isn't Set." << endl;
    }

    // Eliminate element in myset
    mySet.erase(3);

    // Check again
    if (mySet.find(3) != mySet.end()) {
        cout << "Element 3 is in Set." << endl;
    } else {
        cout << "Element 3 isn't Set." << endl;
    }

    return 0;
}

