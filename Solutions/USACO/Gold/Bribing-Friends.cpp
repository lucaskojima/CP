#include "bits/stdc++.h"

using namespace std;

struct T {
  int p, c, x;
};

template<class T> void chmax(T &a, T b) { if (b > a) a = b; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, a, b; cin >> n >> a >> b;

  vector<T> v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i].p >> v[i].c >> v[i].x;

  sort(v.begin() + 1, v.end(), [&](const T &a, const T &b) {
    return a.x > b.x;
  });

  vector dp(n + 1, vector<array<int, 2>>(max(a, b) + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      chmax(dp[i][j][0], dp[i - 1][j][0]);
      if (j - v[i].c >= 0)
        chmax(dp[i][j][0], dp[i - 1][j - v[i].c][0] + v[i].p);
    }
    for (int j = 0; j <= b; j++) {
      chmax(dp[i][j][1], dp[i - 1][j][1]);
      int qnt = min(v[i].c, j / v[i].x);
      if (qnt == v[i].c)
        chmax(dp[i][j][1], dp[i - 1][j - v[i].x * qnt][1] + v[i].p);
      if (a - v[i].c + qnt >= 0)
        chmax(dp[i][j][1], dp[i - 1][a - v[i].c + qnt][0] + v[i].p);
    }
  }

  cout << dp[n][b][1] << '\n';
  return 0;
}
