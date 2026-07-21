#include "bits/stdc++.h"

using namespace std;

template<class T> void chmax(T &a, T b) { if (b > a) a = b; }

int main() {
  freopen("dec.in", "r", stdin);
  freopen("dec.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m; cin >> n >> m;

  vector<vector<pair<int, int>>> b(n);
  for (int i = 0; i < m; i++) {
    int k, p, a; cin >> k >> p >> a; k--;
    b[k].push_back({p, a});
  }

  vector a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  vector<int> dp(1 << n);
  for (int mask = 1; mask < (1 << n); mask++) {
    int i = __builtin_popcount(mask) - 1;
    for (int j = 0; j < n; j++)
      if (mask >> j & 1)
        chmax(dp[mask], dp[mask ^ (1 << j)] + a[j][i]);
    for (auto [p, a] : b[i])
      if (dp[mask] >= p)
        dp[mask] += a;
  }

  cout << dp[(1 << n) - 1] << '\n';
  return 0;
}
