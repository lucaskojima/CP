#include "bits/stdc++.h"

using namespace std;

template<class T> void chmax(T &a, T b) { if (b > a) a = b; }

int main() {
  freopen("pieaters.in", "r", stdin);
  freopen("pieaters.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m; cin >> n >> m;

  vector mx(n + 1, vector(n + 2, vector<int>(n + 2)));
  for (int i = 0; i < m; i++) {
    int w, l, r; cin >> w >> l >> r;

    for (int x = l; x <= r; x++)
      chmax(mx[x][l][r], w);
  }

  for (int x = 1; x <= n; x++)
    for (int r = x; r <= n; r++)
      for (int l = x; l >= 1; l--) {
        chmax(mx[x][l][r], mx[x][l + 1][r]);
        chmax(mx[x][l][r], mx[x][l][r - 1]);
      }

  vector dp(n + 2, vector<int>(n + 2));
  for (int r = 1; r <= n; r++)
    for (int l = r; l >= 1; l--)
      for (int i = l; i <= r; i++)
        chmax(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + mx[i][l][r]);

  cout << dp[1][n] << '\n';
  return 0;
}
