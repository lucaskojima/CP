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

  auto dfs = [&](auto dfs, int x, int p, int t) -> int {
    multiset<int> st;
    for (int k : adj[x]) if (k != p) {
      int v = dfs(dfs, k, x, t);
      if (v == -1) return -1;
      if (++v == t) continue;

      if (st.count(t - v))
        st.erase(st.find(t - v));
      else
        st.insert(v);
    }
    if (sz(st) == 0)
      return 0;
    else if (sz(st) == 1)
      return *st.begin();
    else
      return -1;
  };

  for (int i = 1; i <= n - 1; i++) {
    int ans = 0;
    if ((n - 1) % i == 0)
      if (dfs(dfs, 1, -1, i) == 0)
        ans = 1;
    cout << ans;
  }
  return 0;
}


