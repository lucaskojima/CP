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

struct T {
  int a, b, c;
};

void setIO(string name) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((name+".in").c_str(),"r",stdin);
  freopen((name+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("milkvisits");

  int n, m; cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> p(n + 1);
  vector<T> q(m);
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    q[i] = {a, b, c};
    p[a].push_back(i);
    p[b].push_back(i);
  }

  vector<int> tin(n + 1), tout(n + 1);
  int t = 0;

  auto euler = [&](auto euler, int x, int p) -> void {
    tin[x] = ++t;
    for (int k : adj[x])
      if (k != p)
        euler(euler, k, x);
    tout[x] = t;
  };
  euler(euler, 1, -1);

  auto anc = [&](int a, int b) -> bool {
    return tin[a] <= tin[b] && tin[b] <= tout[a];
  };

  vector<int> ans(m), s;
  vector<vector<pii>> st(n + 1);

  auto dfs = [&](auto dfs, int x, int pai) -> void {
    st[v[x]].push_back({x, sz(s)});
    s.push_back(x);

    for (int i : p[x]) {
      auto [a, b, c] = q[i];
      if (st[c].empty()) continue;
      auto [y, py] = st[c].back();

      if (y == x) ans[i] = 1;
      else {
        int k = s[py + 1];
        if (!anc(k, a + b - x)) ans[i] = 1;
      }
    }

    for (int k : adj[x])
      if (k != pai)
        dfs(dfs, k, x);

    st[v[x]].pop_back();
    s.pop_back();
  };
  dfs(dfs, 1, -1);

  for (int i = 0; i < m; i++)
    cout << ans[i];
  return 0;
}


