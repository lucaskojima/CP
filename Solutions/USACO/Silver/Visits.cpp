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
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> nxt(n + 1), val(n + 1);
  vector<vector<int>> prv(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> nxt[i] >> val[i];
    prv[nxt[i]].push_back(i);
  }

  vector<int> vis(n + 1);

  auto fill = [&](auto fill, int x) -> void {
    for (int k : prv[x])
      if (vis[k] == 0) {
        vis[k] = 1;
        fill(fill, k);
      }
  };

  auto floyd = [&](int x) -> int {
    int y = x;
    do {
      x = nxt[x];
      y = nxt[nxt[y]];
    } while (x != y);

    int r = INF;
    do {
      vis[x] = 1;
      fill(fill, x);

      r = min(r, val[x]);
      x = nxt[x];
    } while (x != y);

    return r;
  };

  long long ans = accumulate(all(val), 0LL);
  for (int i = 1; i <= n; i++)
    if (vis[i] == 0)
      ans -= floyd(i);

  cout << ans << nl;
  return 0;
}
