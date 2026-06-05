#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++)
    g[a[i]].push_back(i);

  for (int i = 1; i <= n; i++)
    if (i == a[i])
      c[i] = 0;

  vector<bool> vis(n + 1);
  i64 ans = 0;

  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;

    auto dfs = [&](auto dfs, int x, int rt) -> pair<i64, i64> {
      vis[x] = true;
      i64 dp0 = 0;
      i64 dp1 = c[x];
      for (int k : g[x]) {
        if (k == rt) continue;
        auto [a, b] = dfs(dfs, k, rt);
        dp0 += b;
        dp1 += min(a, b);
      }
      return {dp0, dp1};
    };

    int x = i, y = i;
    do {
      x = a[x];
      y = a[a[y]];
    } while (x != y);

    i64 r1 = dfs(dfs, x, x).second;
    i64 r2 = dfs(dfs, a[x], a[x]).second;
    ans += min(r1, r2);
  }

  cout << ans << '\n';
  return 0;
}
