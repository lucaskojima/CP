#include "bits/stdc++.h"

using namespace std;

const int INF = INT_MAX;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k; cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector s(k + 1, vector<int>(k + 1));
  for (int i = 1; i <= k; i++) {
    string t; cin >> t;
    for (int j = 1; j <= k; j++)
      s[i][j] = t[j - 1] - '0';
  }
  for (int j = 1; j <= k; j++)
    if (s[j][a[n - 1]])
      s[j][0] = 1;

  a[n - 1] = 0;

  vector adj(n, vector<vector<tuple<int, int, int>>>(k + 1));
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j <= k; j++) {
      adj[i][j].push_back({i + 1, j, 1});
      adj[i + 1][j].push_back({i, j, 1});
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      if (s[j][a[i]])
        adj[i][j].push_back({i, a[i], 0});

  vector d(n, vector<int>(k + 1, INF));
  deque<pair<int, int>> q;

  auto push = [&](int i, int j, int w) -> void {
    if (w < d[i][j]) {
      d[i][j] = w;
      if (w == 0)
        q.push_front({i, j});
      else
        q.push_back({i, j});
    }
  };
  push(0, a[0], 0);

  while (!q.empty()) {
    auto [i, j] = q.front(); q.pop_front();

    for (auto [ni, nj, w] : adj[i][j])
      push(ni, nj, d[i][j] + w);
  }

  int ans = d[n - 1][0];
  cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}
