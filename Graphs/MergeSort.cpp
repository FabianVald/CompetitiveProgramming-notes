#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);
    
    for (int i = 0; i < n1; ++i) {L[i] = arr[left + i];}
    for (int j = 0; j < n2; ++j) {R[j] = arr[mid + 1 + j];}
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {arr[k++] = L[i++];} 
        else {arr[k++] = R[j++];}
    }
    
    while (i < n1) {arr[k++] = L[i++];}
    
    while (j < n2) {arr[k++] = R[j++];}
}

void MergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void showVector(vector<int>& arr) {
    for (int num : arr) {cout << num << " ";}
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Unsorted vector: ";
    showVector(arr);
    
    MergeSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted vector: ";
    showVector(arr);
    
    return 0;
}
