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
const int LOG = 30;

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("cruise");

  int n, m, k; cin >> n >> m >> k;

  vector a(n + 1, vector<int>(2));
  for (int i = 1; i <= n; i++)
    cin >> a[i][0] >> a[i][1];

  vector<int> dir(m);
  for (int i = 0; i < m; i++) {
    char c; cin >> c;
    dir[i] = (c == 'L' ? 0 : 1);
  }

  vector up(n + 1, vector<int>(LOG));
  for (int i = 1; i <= n; i++) {
    int x = i;
    for (int j = 0; j < m; j++)
      x = a[x][dir[j]];

    up[i][0] = x;
  }

  for (int k = 1; k < LOG; k++)
    for (int i = 1; i <= n; i++)
      up[i][k] = up[up[i][k - 1]][k - 1];

  auto lift = [&](int x, int k) -> int {
    for (int i = 0; i < LOG; i++)
      if (k >> i & 1)
        x = up[x][i];
    return x;
  };

  cout << lift(1, k) << nl;
  return 0;
}
