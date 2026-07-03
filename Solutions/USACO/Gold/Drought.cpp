#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int H   = 1e3;

int add(int a, int b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> h[i];

  int ans = 0;

  auto solve = [&]() -> void {
    vector dp(n + 1, vector<int>(H + 1));
    vector dq(n + 1, vector<int>(H + 1));

    dp[0][0] = 1;
    partial_sum(dp[0].begin(), dp[0].end(), dq[0].begin(), add);

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= h[i]; j++)
        dp[i][j] = dq[i - 1][h[i] - j];
      partial_sum(dp[i].begin(), dp[i].end(), dq[i].begin(), add);
    }

    ans = (ans + dp[n][0]) % MOD;
    for (int i = 1; i <= n; i++)
      h[i]--;
  };

  if (n % 2 == 0) {
    solve();
  } else {
    int k = *min_element(h.begin() + 1, h.end());
    for (int j = 0; j <= k; j++)
      solve();
  }

  cout << ans << '\n';
  return 0;
}
