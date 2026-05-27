#include "bits/stdc++.h"

using namespace std;

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) {
    return e[v] < 0 ? v : e[v] = find(e[v]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (e[a] < e[b]) swap(a, b);
    e[b] += e[a];
    e[a] = b;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<tuple<int, int, int, int, int>> g(n);
  vector<vector<int>> adj(2 * n + 1);

  for (auto &[w, a, b, c, d] : g) {
    cin >> w >> a >> b >> c >> d;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adj[c].push_back(d);
    adj[d].push_back(c);
  }

  vector<int> id(2 * n + 1);

  auto dfs = [&](auto dfs, int x, int i) -> void {
    id[x] = i;
    for (int k : adj[x])
      if (id[k] == 0)
        dfs(dfs, k, i);
  };
  for (int i = 1, j = 1; i <= 2 * n; i++)
    if (id[i] == 0)
      dfs(dfs, i, j++);

  sort(g.begin(), g.end());

  dsu dsu(2 * n + 1);
  int ans = 0;

  for (auto [w, a, _, b, __] : g) {
    a = id[a], b = id[b];
    if (!dsu.same(a, b)) {
      dsu.join(a, b);
      ans += w;
    }
  }

  cout << ans << '\n';
  return 0;
}
