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
  setIO("deleg");

  int n; cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> s(n + 1);

  auto dfs = [&](auto dfs, int x, int p, int f) -> bool {
    vector<int> v;
    for (int k : adj[x]) if (k != p) {
      if (!dfs(dfs, k, x, f)) return false;
      v.push_back(s[k] + 1);
    }
    auto check = [&](int i) -> bool {
      int l = 0;
      int r = sz(v) - 1;
      while (l < r) {
        if (l == i) l++;
        if (r == i) r--;
        if (v[l++] + v[r--] < f) return false;
      }
      return true;
    };

    if (x == 1) {
      if (sz(v) % 2 == 1) v.push_back(0);
      sort(all(v));
      return check(-1);
    } else {
      if (sz(v) % 2 == 0) v.push_back(0);
      sort(all(v));

      int l = -1;
      int r = sz(v);
      while (r > l + 1) {
        int m = (l + r) / 2;
        check(m) ? l = m : r = m;
      }

      if (l == -1) return false;
      s[x] = v[l];
      return true;
    }
  };

  int l = 1;
  int r = n + 1;
  while (r > l + 1) {
    int m = (l + r) / 2;
    dfs(dfs, 1, -1, m) ? l = m : r = m;
    fill(all(s), 0);
  }

  cout << l << nl;
  return 0;
}

