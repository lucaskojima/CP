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
const int LOG = 5;

void solve() {
  int m, k; cin >> m >> k;

  vector<int> a;
  for (int i = 0; i < LOG; i++)
    if ((k >> i) & 1)
      a.push_back((1 << (1 << i)) - 1);

  int d = m - accumulate(all(a), 0);
  vector<int> b;
  bool ok = true;

  if (d < 0) {
    ok = false;
  } else if (d == 0) {
    b = {};
  } else if (d == 1) {
    if (a[0] == 1)
      a[0] = 2;
    else
      ok = false;
  } else if (d >= 2) {
    if (d % 2 == 0)
      b = {d / 2, d / 2};
    else
      b = {1, 2, (d - 3) / 2, (d - 3) / 2};
  }

  if (ok) {
    cout << sz(a) + sz(b) << nl;
    for (int x : a) cout << x << ' ';
    for (int x : b) cout << x << ' ';
    cout << nl;
  } else {
    cout << -1 << nl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}
