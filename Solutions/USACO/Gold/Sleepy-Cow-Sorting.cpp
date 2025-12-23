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
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);

  int n; cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  ft ok(n + 1);
  for (int i = n; i >= 1; i--) {
    if (i < n && a[i] > a[i + 1]) break;
    ok.update(a[i], 1);
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (ok.query(a[i], a[i])) break;
    ans.push_back(n - ok.query(a[i] + 1, n) - 1);
    ok.update(a[i], 1);
  }

  cout << sz(ans) << nl;
  for (int i = 0; i < sz(ans); i++)
    cout << ans[i] << " \n"[i == sz(ans) - 1];
  return 0;
}
