#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    vector<int> multiplo;
    multiset<int> poderes;
    
    cin >> n >> k;

    int i = 0;
    while (pow(2, i) <= n) {
        multiplo.push_back(pow(2, i));
        i++;
    }

    int suma = 0;
    i = multiplo.size() - 1;
    while (i >= 0 && suma < n) {
        if (suma + multiplo[i] <= n) {
            suma += multiplo[i];
            poderes.insert(multiplo[i]);
        }
        i--;
    }

    while (poderes.size() < k) {
        if (poderes.empty()) {
            cout << "NO" << endl;
            return 0;
        }

        auto last = poderes.rbegin(); 
        int last_value = *last; 
        poderes.erase(poderes.find(last_value)); 
        int nuevoElemento = last_value / 2;
        if (nuevoElemento > 0) {
            poderes.insert(nuevoElemento);
            poderes.insert(nuevoElemento);
        }
    }

    int sumaFinal = accumulate(poderes.begin(), poderes.end(), 0);
    if (sumaFinal == n && poderes.size() == k) {
        cout << "YES" << endl;
        for (int num : poderes) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
