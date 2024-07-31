#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {return mid;}
        else if (vec[mid] < target) {left = mid + 1;}
        else {right = mid - 1;}
    }
    return -1;
}

int main() {

    vector<int> vec = {2, 3, 4, 10, 40};
    int target = 4;
    int result = binarySearch(vec, target);

    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element not found in vector" << endl;
    }
    return 0;
}