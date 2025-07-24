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

template<class T> struct sparse_table {
  vector<T> v;
  vector<vector<int>> st;

  int log2_floor(int x) {
    return x ? 31 - __builtin_clz(x) : -1;
  }
  int cmb(int a, int b) {
    if (v[a] == v[b]) return min(a, b);
    return v[a] < v[b] ? a : b;
  }
  void init(const vector<T>&_v) {
    v = _v;
    int n = sz(v), k = log2_floor(n);
    st.resize(k + 1);
    st[0].resize(n);
    iota(all(st[0]), 0);

    for (int i = 1; i <= k; i++) {
      st[i].resize(n - (1 << i) + 1);
      for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = cmb(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  int index(int l, int r) {
    int i = log2_floor(r - l + 1);
    return cmb(st[i][l], st[i][r - (1 << i) + 1]);
  }
  T query(int l, int r) {
    return v[index(l, r)];
  }
};

struct lca_solver {
  vector<pii> euler;
  vector<int> first;
  sparse_table<pii> st;

  lca_solver(const vector<vector<int>> &adj) {
    int n = sz(adj) - 1;
    euler.reserve(2 * n);
    first.resize(n + 1);

    dfs(adj, 1, -1);
    st.init(euler);
  }
  void dfs(const vector<vector<int>> &adj, int x, int p, int h = 0) {
    first[x] = sz(euler);
    euler.push_back({h, x});
    for (int k : adj[x])
      if (k != p) {
        dfs(adj, k, x, h + 1);
        euler.push_back({h, x});
      }
  }
  int lca(int a, int b) {
    int l = first[a], r = first[b];
    if (r < l) swap(l, r);
    return st.query(l, r).second;
  }
};

struct segtree {
  int n;
  vector<int> seg;
  segtree(int n) : n(n), seg(4 * n) {}

	void update(int p, int l, int r, int lx, int rx, int v) {
		if (rx < l || r < lx) return;
		if (lx <= l && r <= rx) { seg[p] ^= v; return; }

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		update(e, l, m, lx, rx, v);
		update(d, m + 1, r, lx, rx, v);
	}
	void update(int l, int r, int v) { update(0, 1, n, l, r, v); }

	int query(int p, int l, int r, int i) {
		if (i < l || r < i) return 0;
		if (l == r) return seg[p];

		int m = (l + r) / 2;
		int e = 2 * p + 1, d = 2 * p + 2;
		return seg[p] ^ query(e, l, m, i) ^ query(d, m + 1, r, i);
	}
	int query(int i) { return query(0, 1, n, i); }
};

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("cowland");

  int n, q; cin >> n >> q;
  vector<int> e(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> e[i];

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> tin(n + 1), tout(n + 1), pai(n + 1);
  int t = 0;

  auto euler = [&](auto euler, int x, int p) -> void {
    tin[x] = ++t;
    pai[x] = p;
    for (int k : adj[x])
      if (k != p)
        euler(euler, k, x);
    tout[x] = t;
  };
  euler(euler, 1, 0);

  lca_solver L(adj);
  segtree seg(n);
  for (int i = 1; i <= n; i++)
    seg.update(tin[i], tout[i], e[i]);

  auto sub = [&](int a, int b) -> bool {
    return tin[a] <= tin[b] && tin[b] <= tout[a];
  };
  auto val = [&](int i) -> int {
    return (seg.query(tin[i]) ^ seg.query(tin[pai[i]]));
  };

  while (q--) {
    int op; cin >> op;

    if (op == 1) {
      int i, v; cin >> i >> v;
      int p = pai[i];
      seg.update(tin[i], tout[i], val(i) ^ v);
    } else {
      int i, j; cin >> i >> j;
      int k = L.lca(i, j);
      cout << (seg.query(tin[i]) ^ seg.query(tin[j]) ^ val(k))<< nl;
    }
  }
  return 0;
}

