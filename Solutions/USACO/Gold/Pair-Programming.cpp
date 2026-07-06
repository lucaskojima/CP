#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += MOD;
  return a;
}
bool digit(char c) {
  return '1' <= c && c <= '9';
}

void solve() {
  int n; cin >> n;

  vector<char> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector zero(n + 1, vector<bool>(n + 1));
  zero[0][0] = true;

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      if (i == 0 && j == 0) continue;
      zero[i][j] = a[i] == '0' || b[j] == '0' || (i && zero[i - 1][j] && a[i] != '+') || (j && zero[i][j - 1] && b[j] != '+');
    }

  vector dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1 - zero[0][i];
    dp[i][0] = 1 - zero[i][0];
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i] != '0') dp[i][j] = add(dp[i][j], dp[i - 1][j]);
      if (a[i] == '+') dp[i][j] = add(dp[i][j], zero[i - 1][j]);
      if (b[j] != '0') dp[i][j] = add(dp[i][j], dp[i][j - 1]);
      if (b[j] == '+') dp[i][j] = add(dp[i][j], zero[i][j - 1]);

      if ((a[i] == '+' && b[j] == '+') || (a[i] == '1' && b[j] == '+') || (a[i] == '+' && b[j] == '1'))
        dp[i][j] = sub(dp[i][j], add(dp[i - 1][j - 1], zero[i - 1][j - 1]));
      else if (digit(a[i]) && digit(b[j]))
        dp[i][j] = sub(dp[i][j], dp[i - 1][j - 1]);
    }

  cout << add(dp[n][n], zero[n][n]) << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}
