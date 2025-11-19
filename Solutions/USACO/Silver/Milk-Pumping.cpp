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
const int W   = 1000;

int32_t main() {
  freopen("pump.in", "r", stdin);
  freopen("pump.out", "w", stdout);

  int n, m; cin >> n >> m;

  vector<vector<tuple<int, int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c, f; cin >> u >> v >> c >> f;
    adj[u].push_back({v, c, f});
    adj[v].push_back({u, c, f});
  }

  int ans = 0;
  for (int l = 1; l <= W; l++) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, INF);

    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
      auto [d, x] = pq.top(); pq.pop();
      if (dist[x] != d) continue;

      for (auto [k, dd, f] : adj[x]) {
        if (f < l) continue;
        if (d + dd < dist[k]) {
          dist[k] = d + dd;
          pq.push({dist[k], k});
        }
      }
    }

    int cost = dist[n];
    if (cost < INF)
      ans = max(ans, (int) 1e6 * l / cost);
  }

  cout << ans << nl;
  return 0;
}
