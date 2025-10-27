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

ll dp[19][50][2][2];
string num;

void reset() {
  for (int i = 0; i < 19; i++)
    for (int j = 0; j < 50; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++)
          dp[i][j][k][l] = -1;
}

ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2) {
  if (pos == sz(num)) {
    if (!started)
      return 0;
    if (targ2 != -1)
      return k == 20;
    return k >= 20;
  }
  if (dp[pos][k][under][started] != -1) return dp[pos][k][under][started];

  ll res = 0;
  for (int i = 0; i <= 9; i++) {
    int dig = num[pos] - '0';
    if (!under && i > dig) break;

    bool n_under = under || (i < dig);
    bool n_started = started || (i != 0);

    if (n_started && targ2 != -1 && i != targ && i != targ2) continue;

    int n_k = k;
    if (n_started)
      n_k += (i == targ ? 1 : -1);

    res += solve_dp(pos + 1, n_k, n_under, n_started, targ, targ2);
  }
  return dp[pos][k][under][started] = res;
}

ll solve(ll bound) {
  num = to_string(bound);

  ll res = 0;
  for (int i = 0; i <= 9; i++) {
    reset();
    res += solve_dp(0, 20, false, false, i, -1);
  }

  ll duplicates = 0;
  for (int i = 0; i <= 9; i++)
    for (int j = i; j <= 9; j++) {
      reset();
      duplicates += solve_dp(0, 20, false, false, i, j);
    }

  return res - duplicates;
}

int32_t main() {
  freopen("odometer.in", "r", stdin);
  freopen("odometer.out", "w", stdout);

  ll x, y; cin >> x >> y;
  cout << solve(y) - solve(x - 1) << nl;
  return 0;
}
