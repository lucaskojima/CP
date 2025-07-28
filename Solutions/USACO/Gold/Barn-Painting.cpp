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
const int MOD = 1e9 + 7;

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("barnpainting");

  int n, k; cin >> n >> k;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> c(n + 1, -1);
  for (int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    c[a] = b - 1;
  }

  vector dp(n + 1, vector<long long>(3));

  auto dfs = [&](auto dfs, int x, int p) -> void {
    if (c[x] == -1)
      dp[x][0] = dp[x][1] = dp[x][2] = 1;
    else
      dp[x][c[x]] = 1;

    for (int k : adj[x]) {
      if (k == p) continue;
      dfs(dfs, k, x);

      for (int i = 0; i < 3; i++) {
        dp[x][i] *= dp[k][(i + 1)%3] + dp[k][(i+2)%3];
        dp[x][i] %= MOD;
      }
    }
  };
  dfs(dfs, 1, -1);

  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += dp[1][i];
    ans %= MOD;
  }

  cout << ans << nl;
  return 0;
}
