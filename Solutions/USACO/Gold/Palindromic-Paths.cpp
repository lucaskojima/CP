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
const int MOD = 1e9 + 7;

int32_t main() {
  freopen("palpath.in", "r", stdin);
  freopen("palpath.out", "w", stdout);

  int n; cin >> n;
  vector<string> g(n); for (auto &x : g) cin >> x;

  vector dp(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;

  for (int a = 1; a < n; a++) {
    vector ndp(n, vector<ll>(n));

    for (int r1 = 0; r1 < n; r1++) {
      int c1 = n - 1 - r1 - a;
      if (c1 < 0) continue;

      for (int r2 = 0; r2 < n; r2++) {
        int c2 = n - 1 - r2 + a;
        if (c2 >= n) continue;

        if (g[r1][c1] != g[r2][c2]) continue;
        ndp[r1][r2] += dp[r1][r2];
        if (r1 + 1 < n)
          ndp[r1][r2] += dp[r1 + 1][r2];
        if (r2 - 1 >= 0)
          ndp[r1][r2] += dp[r1][r2 - 1];
        if (r1 + 1 < n && r2 - 1 >= 0)
          ndp[r1][r2] += dp[r1 + 1][r2 - 1];

        ndp[r1][r2] %= MOD;
      }
    }

    swap(dp, ndp);
  }

  cout << dp[0][n - 1] << nl;
  return 0;
}
