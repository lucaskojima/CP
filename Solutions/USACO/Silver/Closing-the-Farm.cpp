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

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("closing");

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> vis(n + 1), out(n + 1);

  auto dfs = [&](auto dfs, int x) -> void {
    vis[x] = 1;
    for (int k : adj[x])
      if (vis[k] == 0 && out[k] == 0)
        dfs(dfs, k);
  };

  dfs(dfs, 1);
  bool ok = true;
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      ok = false;

  cout << (ok ? "YES" : "NO") << nl;

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    out[x] = 1;

    fill(all(vis), 0);
    for (int j = 1; j <= n; j++)
      if (!out[j]) {
        dfs(dfs, j);
        break;
      }

    bool ok = true;
    for (int j = 1; j <= n; j++)
      if (!out[j] && !vis[j])
        ok = false;

    if (i == n - 1) continue;
    cout << (ok ? "YES" : "NO") << nl;
  }
  return 0;
}
