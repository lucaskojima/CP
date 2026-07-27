#include "bits/stdc++.h"
#define sz(x) int(size(x))

using namespace std;

const int INF = 0x7f7f7f7f;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m; cin >> n >> m;

  vector a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  vector dist(n, vector(m, array<array<int, 2>, 4>()));
  queue<tuple<int, int, int, int>> q;
  for (auto &r : dist)
    for (auto &c : r)
      for (auto &a : c)
        a.fill(INF);

  auto push = [&](int i, int j, int d, int c, int dd) -> void {
    if (dd < dist[i][j][d][c]) {
      dist[i][j][d][c] = dd;
      q.push({i, j, d, c});
    }
  };
  push(0, 0, 0, 0, 0);

  auto val = [&](int i, int j) -> bool {
    return 0 <= i && i < n && 0 <= j && j < m && a[i][j] != 0;
  };
  auto can = [&](int i, int j, int c) -> bool {
    if (!val(i, j)) return false;
    if (a[i][j] == 3 && !c) return false;
    return true;
  };

  while (!q.empty()) {
    auto [i, j, d, c] = q.front(); q.pop();

    bool forced = false;
    if (a[i][j] == 4) {
      int ni = i + dx[d];
      int nj = j + dy[d];
      forced = can(ni, nj, c);
    }

    for (int nd = 0; nd < 4; nd++) {
      int ni = i + dx[nd];
      int nj = j + dy[nd];
      if (!can(ni, nj, c)) continue;
      if (forced && nd != d) continue;
      int nc = (c || (a[ni][nj] == 2)) && (a[ni][nj] != 4);
      push(ni, nj, nd, nc, dist[i][j][d][c] + 1);
    }
  }

  int ans = INF;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++)
      ans = min(ans, dist[n - 1][m - 1][i][j]);

  cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}
