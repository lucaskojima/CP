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
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  int n; cin >> n;

  vector<int> a(2 * n), pos(n + 1);
  ft fen(2 * n);
  int ans = 0;

  for (int i = 1; i <= 2 * n; i++) {
    int x; cin >> x;

    if (pos[x] == 0) {
      pos[x] = i;
      fen.update(pos[x], 1);
    } else {
      fen.update(pos[x], -1);
      ans += fen.query(pos[x], i);
    }
  }

  cout << ans << nl;
  return 0;
}
