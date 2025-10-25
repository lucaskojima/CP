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

template<class T> void chmin(T &a, T b) { if (b < a) a = b; }

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  vector<int> a(n); for (auto &x : a) cin >> x;

  vector dp(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;

  for (int i = n - 1; i >= 0; i--)
    for (int j = i + 1; j < n; j++)
      for (int k = i; k < j; k++)
        chmin(dp[i][j], dp[i][k] + dp[k + 1][j] - (a[i] == a[j]));

  cout << dp[0][n - 1] << nl;
  return 0;
}
