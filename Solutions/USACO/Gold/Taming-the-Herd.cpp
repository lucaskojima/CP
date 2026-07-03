#include "bits/stdc++.h"

using namespace std;

const int INF = 0x3f3f3f3f;

template<class T> void chmin(T &a, T b) { if (b < a) a = b; }

int main() {
  freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector r(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (j == i)
        r[i][j] = (a[i] == 0 ? 0 : 1);
      else
        r[i][j] = r[i][j - 1] + (a[j] == j - i ? 0 : 1);

  vector dp(n + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      chmin(dp[i][j], dp[i - 1][j] + 1);
      chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      if (i - a[i] - 1 >= 0)
        chmin(dp[i][j], dp[i - a[i] - 1][j - 1] + r[i - a[i]][i]);
    }

  for (int i = 1; i <= n; i++)
    cout << dp[n][i] << '\n';
  return 0;
}
