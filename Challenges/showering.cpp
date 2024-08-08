#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, s, m; // Number of time intervals Alex already has planned, 
                    // the amount of time Alex takes to take a shower, and 
                    // the number of minutes a day has.
    cin >> t;
    vector<string> v;

    for (int i = 0; i < t; ++i) {
        cin >> n >> s >> m;

        vector<pair<int, int>> intervalo(n);

        for (int j = 0; j < n; ++j) {
            cin >> intervalo[j].first >> intervalo[j].second;
        }

        string estado = "NO";
       
        if (intervalo[0].first >= s) {
            estado = "YES";
        }

       
        for (int j = 1; j < n; ++j) {
            if (intervalo[j].first - intervalo[j - 1].second >= s) {
                estado = "YES";
            }
        }


        if (m - intervalo[n - 1].second >= s) {
            estado = "YES";
        }

        v.push_back(estado);
    }

    for (const string &result : v) {
        cout << result << endl;
    }

    return 0;
}
