#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


template<class T, T merge(T, T)>
struct segment_tree{
  int n;
  vector<T> ST;
  segment_tree(int n, T def = T()) : n(n), ST(4 * n + 5, def){
    vector<T> a(n, def);
    build(1, 0, n - 1, a);
  }
  segment_tree(vector<T> &a) : n(a.size()), ST(4 * n + 5){
    build(1, 0, n - 1, a);
  }
  segment_tree(){}

  void build(int i, int l, int r, vector<T> &a){
    if (l == r){
      ST[i] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid, a);
    build(i * 2 + 1, mid + 1, r, a);
    ST[i] = merge(ST[i * 2], ST[i * 2 + 1]);
  }
  void update(int i, int l, int r, int p, T x){
    if (r < p or l > p)
      return;
    if (l == r){
      ST[i] = x;
      return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, x);
    update(i * 2 + 1, mid + 1, r, p, x);
    ST[i] = merge(ST[i * 2], ST[i * 2 + 1]);
  }
  T query(int i, int l, int r, int a, int b){
    if (l >= a and r <= b)
      return ST[i];
    int mid = (l + r) / 2;
    if (b <= mid)
      return query(i * 2, l, mid, a, b);
    else if (a > mid)
      return query(i * 2 + 1, mid + 1, r, a, b);
    else
      return merge(
        query(i * 2, l, mid, a, b), 
        query(i * 2 + 1, mid + 1, r, a, b)
      );
  }
  // user methods
  void update(int p, T x){
    update(1, 0, n - 1, p, x);
  }
  T query(int a, int b){
    return query(1, 0, n - 1, a, b);
  }
};


ll merge(ll a, ll b){
  return min(a,b);
}



int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int n, q;
  cin >> n >> q; // give number of values and queries
  vector<ll> a(n); // create vector size n

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];  // 
  }
  
  segment_tree<ll, merge> st(a);

  for (int i = 0; i < q; ++i)
  {
   int tipo;
   cin >> tipo;
  
   if (tipo == 1)
   {
     int pos; ll u;
     cin >> pos >> u;
     pos --;
     st.update(pos, u);
   }

   else{
    int a, b;
    cin >> a >> b;
    a --; b --;
    cout << st.query(a,b) << endl;
   }
  }
  return 0;
}