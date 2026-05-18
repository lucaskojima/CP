#include "bits/stdc++.h"

using namespace std;

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) {
    return e[v] < 0 ? v : e[v] = find(e[v]);
  }
  int size(int v) {
    return -e[find(v)];
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

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++, deg[v]++;
  }

  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++)
    st.insert({deg[i], i});

  vector<int> ord, deg_ord;
  vector<bool> mark(n + 1);

  auto remove = [&]() -> void {
    auto [d, x] = *st.begin();
    st.erase(st.begin());
    ord.push_back(x);
    deg_ord.push_back(d);
    mark[x] = true;

    for (int k : adj[x])
      if (!mark[k]) {
        st.erase({deg[k], k});
        deg[k]--;
        st.insert({deg[k], k});
      }
  };

  for (int i = 0; i < n; i++)
    remove();

  reverse(ord.begin(), ord.end());
  reverse(deg_ord.begin(), deg_ord.end());

  dsu dsu(n + 1);
  long long ans = 0;
  fill(mark.begin(), mark.end(), false);

  for (int i = 0; i < n; i++) {
    int x = ord[i];
    int d = deg_ord[i];
    mark[x] = true;

    for (int k : adj[x])
      if (mark[k])
        dsu.join(x, k);

    ans = max(ans, 1LL * d * dsu.size(x));
  }

  cout << ans << '\n';
  return 0;
}
