#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
bool dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, e;
    cin >> n >> k >> e;
    int left = e, right = n - k - e;

    dp[0][0] = true;
    for (int len = 1; len <= n; ++len) {
        if (len != k) {
            for (int i = left; i >= 0; --i) {
                for (int j = right; j >= 0; --j) {
                    if (len <= i) dp[i][j] |= dp[i - len][j];
                    if (len <= j) dp[i][j] |= dp[i][j - len];
                }
            }
        }
    }

    int ans = k;
    for (int i = 0; i <= left; ++i) {
        for (int j = 0; j <= right; ++j) {
            if (dp[i][j]) {
                ans = max(ans, i + j + k);
            }
        }
    }

    cout << n - ans << "\n";
    return 0;
}
