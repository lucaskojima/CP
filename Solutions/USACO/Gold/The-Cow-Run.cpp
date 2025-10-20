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

int32_t main() {
  freopen("cowrun.in", "r", stdin);
  freopen("cowrun.out", "w", stdout);

  int n; cin >> n;
  vector<int> a(n); for (auto &x : a) cin >> x;

  sort(all(a));

  vector dp(n, vector(n, vector<ll>(2, LINF)));

  for (int i = n - 1; i >= 0; i--)
    for (int j = i; j < n; j++) {
      int rem = n - (j - i);
      if (i == j) {
        dp[i][j][0] = abs(a[i]) * rem;
        dp[i][j][1] = abs(a[i]) * rem;
        continue;
      }

      if (i + 1 < n)
        dp[i][j][0] = min(
          dp[i + 1][j][0] + abs(a[i] - a[i + 1]) * rem,
          dp[i + 1][j][1] + abs(a[i] - a[j]) * rem
        );

      if (j - 1 >= 0)
        dp[i][j][1] = min(
          dp[i][j - 1][1] + abs(a[j] - a[j - 1]) * rem,
          dp[i][j - 1][0] + abs(a[j] - a[i]) * rem
        );
    }

  cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << nl;
  return 0;
}
