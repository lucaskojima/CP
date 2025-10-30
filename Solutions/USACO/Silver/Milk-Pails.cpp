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

int32_t main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, k, m; cin >> x >> y >> k >> m;

  set<pii> st;
  st.insert({0, 0});
  int ans = INF;

  while (k--) {
    set<pii> nst;

    for (auto [a, b] : st) {
      ans = min(ans, abs(m - (a + b)));
      nst.insert({0, b});
      nst.insert({x, b});
      nst.insert({a, 0});
      nst.insert({a, y});

      int d = min(a, y - b);
      nst.insert({a - d, b + d});
      d = min(x - a, b);
      nst.insert({a + d, b - d});
    }

    swap(nst, st);
  }

  cout << ans << nl;
  return 0;
}
