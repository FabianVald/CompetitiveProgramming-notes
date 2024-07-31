#include <bits/stdc++.h>

using namespace std;

// map is analog to dictionary in python

int main()
{
    // Create a map with int key and string value
    map<string, int> inventory;

    // Insert key-values
    inventory["apple"] = 3;
    inventory["banana"] = 5;
    inventory["orange"] = 2;

    // access to a element
    cout << "Apples: " << inventory["apple"] << endl;

    // Search element
    auto it = inventory.find("banana");
    if (it != inventory.end()) {
        cout << "Found banana with count: " << it->second << endl;
    } else {
        cout << "Banana not found." << endl;
    }

    // Eliminate a element
    inventory.erase("apple");

    // Iterate in a map
    cout << "Current inventory:" << endl;
    for (auto& item : inventory) {
        cout << item.first << ": " << item.second << endl;
    }

    return 0;
}
