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

long long solve() {
  long long a, b, c, d; cin >> a >> b >> c >> d;

  long long ans = 0;
  while (a != c || b != d) {
    if (c < a || d < b) return -1;
    if (c > d) {
      long long qnt = max(1LL, (c - a) / d);
      ans += qnt;
      c -= d * qnt;
    } else if (d > c) {
      long long qnt = max(1LL, (d - b) / c);
      ans += qnt;
      d -= c * qnt;
    } else {
      return -1;
    }
  }
  return ans;
}


int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cout << solve() << nl;
  }
  return 0;
}
