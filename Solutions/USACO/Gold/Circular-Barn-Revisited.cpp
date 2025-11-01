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
  freopen("cbarn2.in", "r", stdin);
  freopen("cbarn2.out", "w", stdout);

  int N, K; cin >> N >> K;
  vector<int> a(N); for (auto &x : a) cin >> x;

  ll ans = LINF;
  for (int _ = 0; _ < N; _++) {
    vector dp(N + 1, vector<ll>(K + 1, LINF));
    dp[N][0] = 0;

    for (int k = 1; k <= K; k++)
      for (int i = N - 1; i >= 0; i--) {
        ll cost = 0;
        for (int j = i; j < N; j++) {
          cost += a[j] * (j - i);
          chmin(dp[i][k], dp[j + 1][k - 1] + cost);
        }
      }

    chmin(ans, dp[0][K]);
    rotate(a.begin(), a.begin() + 1, a.end());
  }

  cout << ans << nl;
  return 0;
}
