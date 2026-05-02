#include "bits/stdc++.h"

#define int long long

using namespace std;

const int INF = LLONG_MAX;

void setIO(string s) {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("shortcut");

  int n, m, t; cin >> n >> m >> t;

  vector<int> c(n);
  for (auto &x : c) cin >> x;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, t; cin >> a >> b >> t; a--, b--;
    adj[a].push_back({b, t});
    adj[b].push_back({a, t});
  }

  using T = pair<int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  vector<int> dist(n, INF);

  auto push = [&](int x, int w) -> void {
    if (w < dist[x])
      pq.push({dist[x] = w, x});
  };
  push(0, 0);

  vector<int> p(n, INF);
  while (!pq.empty()) {
    auto [d, x] = pq.top(); pq.pop();
    if (dist[x] != d) continue;

    for (auto [k, dd] : adj[x]) {
      if (d + dd < dist[k])
        p[k] = x;
      else if (d + dd == dist[k])
        p[k] = min(p[k], x);
      push(k, d + dd);
    }
  }

  vector<vector<pair<int, int>>> adj_t(n);
  for (int i = 1; i < n; i++)
    adj_t[p[i]].push_back({i, dist[i] - dist[p[i]]});

  int ans = 0;

  auto dfs = [&](auto dfs, int x, int d) -> void {
    for (auto [k, dd] : adj_t[x]) {
      dfs(dfs, k, d + dd);
      c[x] += c[k];
    }
    if (d >= t)
      ans = max(ans, (d - t) * c[x]);
  };
  dfs(dfs, 0, 0);

  cout << ans << '\n';
  return 0;
}
