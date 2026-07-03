#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

int exp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int main() {
  freopen("poetry.in", "r", stdin);
  freopen("poetry.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m, k; cin >> n >> m >> k;

  vector<int> w(n), c(n);
  for (int i = 0; i < n; i++)
    cin >> w[i] >> c[i];

  vector<int> cnt(26);
  for (int i = 0; i < m; i++) {
    char c; cin >> c;
    cnt[c - 'A']++;
  }

  vector<int> dp(k + 1);
  dp[0] = 1;

  for (int i = 1; i <= k; i++)
    for (int j = 0; j < n; j++)
      if (i - w[j] >= 0)
        dp[i] = add(dp[i], dp[i - w[j]]);

  vector<int> dq(n + 1);
  for (int i = 0; i < n; i++)
    dq[c[i]] = add(dq[c[i]], dp[k - w[i]]);

  int ans = 1;
  for (int c = 0; c < 26; c++) {
    if (cnt[c] == 0) continue;
    int cur = 0;
    for (int i = 1; i <= n; i++)
      cur = add(cur, exp(dq[i], cnt[c]));
    ans = mul(ans, cur);
  }

  cout << ans << '\n';
  return 0;
}
