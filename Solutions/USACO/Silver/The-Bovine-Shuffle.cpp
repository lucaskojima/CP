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

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("shuffle");

  int n; cin >> n;

  vector<int> nxt(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> nxt[i];

  vector<int> vis(n + 1), in_cycle(n + 1);

  auto floyd = [&](int x) -> void {
    int y = x;
    do {
      if (vis[x] == 1) return;
      vis[x] = 1;

      x = nxt[x];
      y = nxt[nxt[y]];
    } while (x != y);

    do {
      is[x] = in_cycle[x] = 1;
      x = nxt[x];
    } while (x != y);
  };

  for (int i = 1; i <= n; i++)
    if (vis[i] == 0)
      floyd(i);

  int ans = accumulate(all(in_cycle), 0);
  cout << ans << nl;
  return 0;
}

