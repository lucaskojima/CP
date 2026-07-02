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

  vector dp(n + 1, vector(n + 1, vector<int>(n + 1, INF)));
  vector dq(n + 1, vector<int>(n + 1, INF));
  dp[0][0][0] = dq[0][0] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      dp[i][j][0] = dq[i - 1][j - 1] + (a[i] != 0);
      for (int k = 1; k <= n; k++)
        dp[i][j][k] = dp[i - 1][j][k - 1] + (a[i] != k);

      for (int k = 0; k <= n; k++)
        chmin(dq[i][j], dp[i][j][k]);
    }

  for (int j = 1; j <= n; j++)
    cout << dq[n][j] << '\n';
  return 0;
}
