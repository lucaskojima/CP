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

struct ft {
  int n;
  vector<int> b;
  ft(int n) : n(n), b(n + 1) {}

  void update(int i, int v) {
    for (; i <= n; i += i & -i)
      b[i] += v;
  }
  int query(int i) {
    int res = 0;
    for (; i >= 1; i -= i & -i)
      res += b[i];
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int32_t main() {
  freopen("haircut.in", "r", stdin);
  freopen("haircut.out", "w", stdout);

  int n; cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  ft cnt(n + 1), ans(n);
  for (int i = 1; i <= n; i++) {
    int inv = cnt.query(a[i] + 1, n);
    if (a[i] > 0)
      cnt.update(a[i], 1);
    ans.update(a[i] + 1, inv);
  }

  for (int i = 0; i < n; i++)
    cout << ans.query(i) << nl;
  return 0;
}
