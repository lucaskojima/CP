#include "bits/stdc++.h"
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct segtree {
  int n;
  vector<vector<int>> seg;
  segtree(int n) : n(n), seg(4 * n) {}

  void build(int p, int l, int r, const vector<int> &v) {
    if (l == r) {
      seg[p] = vector<int>(1, v[l]);
      return;
    }
    int m = (l + r) / 2;
    int e = 2 * p + 1, d = 2 * p + 2;
    build(e, l, m, v);
    build(d, m + 1, r, v);

    merge(all(seg[e]), all(seg[d]), back_inserter(seg[p]));
  }
  int query(int p, int l, int r, int lx, int rx, int v) {
    if (rx < l || r < lx) return 0;
    if (lx <= l && r <= rx) return seg[p].end() - upper_bound(all(seg[p]), v);
    int m = (l + r) / 2;
    int e = 2 * p + 1, d = 2 * p + 2;
    return query(e, l, m, lx, rx, v) + query(d, m + 1, r, lx, rx, v);
  }

  void build(const vector<int> &v) { build(0, 1, n, v); }
  int query(int l, int r, int v) { return query(0, 1, n, l, r, v); }
};

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("promote");

  int n; cin >> n;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int a; cin >> a;
    adj[i].push_back(a);
    adj[a].push_back(i);
  }

  vector<int> tin(n + 1), tout(n + 1);
  int t = 0;

  auto euler = [&](auto euler, int x, int p) -> void {
    tin[x] = ++t;
    for (int k : adj[x])
      if (k != p)
        euler(euler, k, x);
    tout[x] = t;
  };
  euler(euler, 1, -1);

  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
    v[tin[i]] = p[i];

  segtree seg(n);
  seg.build(v);

  for (int i = 1; i <= n; i++)
    cout << seg.query(tin[i], tout[i], p[i]) << nl;
  return 0;
}


