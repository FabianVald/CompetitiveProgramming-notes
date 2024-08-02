#include <bits/stdc++.h>
using namespace std;

void build(vector<int>& tree, const string& s, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1 << (s[start] - 'a');
    } else {
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        build(tree, s, leftChild, start, mid);
        build(tree, s, rightChild, mid + 1, end);
        tree[node] = tree[leftChild] | tree[rightChild];
    }
}

void update(vector<int>& tree, int idx, char c, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1 << (c - 'a');
    } else {
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        if (start <= idx && idx <= mid) {
            update(tree, idx, c, leftChild, start, mid);
        } else {
            update(tree, idx, c, rightChild, mid + 1, end);
        }
        tree[node] = tree[leftChild] | tree[rightChild];
    }
}

int query(const vector<int>& tree, int l, int r, int node, int start, int end) {
    if (r < start || l > end) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;
    int leftMask = query(tree, l, r, leftChild, start, mid);
    int rightMask = query(tree, l, r, rightChild, mid + 1, end);
    return leftMask | rightMask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> tree(4 * n);

    build(tree, s, 0, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            update(tree, pos - 1, c, 0, 0, n - 1);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int resultMask = query(tree, l - 1, r - 1, 0, 0, n - 1);
            int distinctCount = __builtin_popcount(resultMask);
            cout << distinctCount << '\n';
        }
    }

    return 0;
}
