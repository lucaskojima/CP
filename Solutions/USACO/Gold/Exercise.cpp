#include "bits/stdc++.h"

using namespace std;

int main() {
  freopen("exercise.in", "r", stdin);
  freopen("exercise.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, M; cin >> n >> M;

  auto add = [&](int a, int b) -> int {
    if ((a += b) >= M) a -= M;
    return a;
  };
  auto mul = [&](int a, int b) -> int {
    return 1LL * a * b % M;
  };

  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= n; i++)
    if (is_prime[i] && 1LL * i * i <= n)
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

  vector<int> primes;
  for (int i = 1; i <= n; i++)
    if (is_prime[i])
      primes.push_back(i);
  int m = int(size(primes));

  vector dp(m + 1, vector<int>(n + 1));
  dp[0][0] = 1;

  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];

      int p = primes[i - 1];
      while (p <= j) {
        dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - p], p));
        p = mul(p, primes[i - 1]);
      }
    }

  int ans = 0;
  for (int i = 0; i <= n; i++)
    ans = add(ans, dp[m][i]);

  cout << ans << '\n';
  return 0;
}
