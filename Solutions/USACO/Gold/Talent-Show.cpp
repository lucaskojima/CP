#include "bits/stdc++.h"
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int W   = 1000;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("talent");

  int n, x; cin >> n >> x;

  vector<int> w(n), t(n);
  for (int i = 0; i < n; i++)
    cin >> w[i] >> t[i];

  auto check = [&](int y) -> bool {
    vector<int> dp(x + 1, -LINF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
      int c = 1000 * t[i] - y * w[i];
      for (int j = x; j >= 0; j--) { // pull
        int k = min(x, j + w[i]);
        dp[k] = max(dp[k], dp[j] + c);
      }
    }
    return dp[x] >= 0;
  };

  int l = 0;   // l is good
  int r = 1e9; // r is bad
  while (r > l + 1) {
    int m = (l + r) / 2;
    check(m) ? l = m : r = m;
  }

  cout << l << nl;
  return 0;
}
