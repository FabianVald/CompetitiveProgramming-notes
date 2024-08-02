#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, w;  // Duration, umbrellas at home, umbrellas at work
    cin >> n >> h >> w;

    vector<pair<string, string>> llueve(n);
    for(int i = 0; i < n; ++i){
        cin >> llueve[i].first >> llueve[i].second; // Rain status for both trips
    }

    for (int i = 0; i < n; ++i) {
        string trip1, trip2;

       
        if (llueve[i].first == "Y") {
            trip1 = "Y";
            h--; w++;  
        } else if (w == 0) {
            trip1 = "Y";
            h--; w++; 
        } else {
            trip1 = "N";
        }

      
        if (llueve[i].second == "Y") {
            trip2 = "Y";
            w--; h++;  
        } else if (h == 0) {
            trip2 = "Y";
            w--; h++;  
        } else {
            trip2 = "N";
        }

        cout << trip1 << " " << trip2 << endl;
    }

    return 0;
}