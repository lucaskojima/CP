#include "bits/stdc++.h"

using namespace std;

const int INF = INT_MAX;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("walk.in", "r", stdin);
  freopen("walk.out", "w", stdout);

  int n, k; cin >> n >> k;

  auto dist = [&](int i, int j) -> int {
    return (i * 2019201913LL + j * 2019201949LL) % 2019201997;
  };

  vector<int> d(n + 1, INF);
  vector<bool> vis(n + 1);

  for (int j = 0; j < n; j++) {
    int v = -1;
    for (int i = 1; i <= n; i++)
      if (!vis[i] && (v == -1 || d[i] < d[v]))
        v = i;

    vis[v] = true;
    for (int i = 1; i <= n; i++)
      if (!vis[i])
        d[i] = min(d[i], dist(min(i, v), max(i, v)));
  }

  sort(d.begin(), d.end());

  cout << d[n - k] << '\n';
  return 0;
}
