#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = value;
        while (pos > 1) {
            pos >>= 1;
            tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
        }
    }

    int range_min(int left, int right) {
        left += n;
        right += n + 1;
        int min_val = INT_MAX;
        while (left < right) {
            if (left & 1) {
                min_val = min(min_val, tree[left]);
                left++;
            }
            if (right & 1) {
                right--;
                min_val = min(min_val, tree[right]);
            }
            left >>= 1;
            right >>= 1;
        }
        return min_val;
    }

private:
    int n;
    vector<int> tree;

    void build(const vector<int>& data) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = data[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    SegmentTree segTree(array);

    for (int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            int k = a - 1;
            int u = b;
            segTree.update(k, u);
        } else if (type == 2) {
            int left = a - 1;
            int right = b - 1;
            cout << segTree.range_min(left, right) << '\n';
        }
    }

    return 0;
}
