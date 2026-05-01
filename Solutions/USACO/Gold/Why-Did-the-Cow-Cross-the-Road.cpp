#include "bits/stdc++.h"

using namespace std;

void setIO(string s){
  ios::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("visitfj");

  int n, t; cin >> n >> t;

  vector a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int dx[] = {1, 0, -1, 0, 3, 0, -3, 0, 2, 2, 1, 1, -1, -1, -2, -2};
  int dy[] = {0, 1, 0, -1, 0, 3, 0, -3, 1, -1, 2, -2, 2, -2, 1, -1};

  auto p = [&](int i, int j) -> int {
    return n * i + j;
  };
  auto val = [&](int i, int j) -> bool {
    return 0 <= i && i < n && 0 <= j && j < n;
  };

  vector<vector<pair<int, int>>> adj(n * n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      for (int d = 0; d < 16; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if (val(ni, nj))
          adj[p(i, j)].push_back({p(ni, nj), a[ni][nj] + 3 * t});
      }
      int d = n - 1 - i + n - 1 - j;
      if (d <= 2)
        adj[p(i, j)].push_back({p(n - 1, n - 1), d * t});
    }

  using T = pair<int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  vector<int> dist(n * n, INT_MAX);
  pq.push({0, 0});
  dist[0] = 0;

  while (!pq.empty()) {
    auto [d, x] = pq.top(); pq.pop();
    if (dist[x] != d) continue;

    for (auto [k, dd] : adj[x])
      if (d + dd < dist[k]) {
        dist[k] = d + dd;
        pq.push({dist[k], k});
      }
  }

  cout << dist[p(n - 1, n - 1)] << '\n';
  return 0;
}
