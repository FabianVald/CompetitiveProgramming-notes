#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> KMP(const string& s) {
    int n = s.length();
    vector<int> P(n, 0);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = P[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        P[i] = j;
    }
    return P;
}

vector<int> bordes(const string& s) {
    vector<int> P = KMP(s);
    set<int> b;
    int k = P.back();
    while (k > 0) {
        b.insert(k);
        k = P[k - 1];
    }
    vector<int> sorted_b(b.begin(), b.end());
    return sorted_b;
}

int main() {
    string input;
    cin >> input;

    vector<int> b = bordes(input);
    for (size_t i = 0; i < b.size(); ++i) {
        if (i > 0) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}