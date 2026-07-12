#include "bits/stdc++.h"

using namespace std;

template<class S, auto op, auto e> struct segtree {
  private:
    int n, size, log;
    vector<S> d;

    void update(int i) { d[i] = op(d[2 * i], d[2 * i + 1]); }
  public:
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(const vector<S> &v) : n(int(v.size())) {
      size = 1, log = 0;
      while (size < n) size *= 2, log++;
      d = vector<S>(2 * size, e());
      for (int i = 0; i < n; i++) d[i + size] = v[i];
      for (int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
      d[p += size] = x;
      for (int i = 1; i <= log; i++) update(p >> i);
    }
    S prod(int l, int r) {
      S lx = e(), rx = e();
      for (l += size, r += size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) lx = op(lx, d[l++]);
        if (r % 2 == 0) rx = op(d[r--], rx);
      }
      return op(lx, rx);
    }
    S all_prod() { return d[1]; }
};

int op(int l, int r) { return max(l, r); }
int e() { return -1; }

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  segtree<int, op, e> s(n + 1), g(n + 1);
  vector<int> bst(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    int x = a[i % n];

    int one = s.prod(x + 1, n);
    int two = g.prod(x + 1, n);
    bst[i] = max(two, i > 0 ? bst[i - 1] : -1);

    s.set(x, i);
    if (one != -1)
      g.set(x, one);
  }

  vector<int> ans;
  for (int i = 2 * n - 1; i >= n; i--)
    if (i - n + 1 > bst[i])
      ans.push_back(2 * n - 1 - i);

  cout << int(size(ans)) << '\n';
  for (int i = 0; i < int(size(ans)); i++) {
    if (i > 0) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}
