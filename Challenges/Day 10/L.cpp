#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

const long long MAX_PRIME = 1000000LL; // 10^6

vector<bool> sieve(MAX_PRIME + 1, true);
unordered_set<long long> t_primes;

// Eratosthenes
void compute_primes() {
    sieve[0] = sieve[1] = false; 
    for (long long i = 2; i * i <= MAX_PRIME; ++i) {
        if (sieve[i]) {
            for (long long j = i * i; j <= MAX_PRIME; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    // Compute T-primes
    for (long long i = 2; i <= MAX_PRIME; ++i) {
        if (sieve[i]) {
            long long t_prime = i * i;
            t_primes.insert(t_prime);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    compute_primes();

    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        if (t_primes.find(x) != t_primes.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
