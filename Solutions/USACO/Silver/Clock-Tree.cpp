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
  setIO("clocktree");

  int n; cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> cnt(2), sum(2);

  auto dfs = [&](auto dfs, int x, int p, int t) -> void {
    cnt[t]++;
    sum[t] += a[x];
    for (int k : adj[x])
      if (k != p)
        dfs(dfs, k, x, 1 - t);
  };
  dfs(dfs, 1, -1, 0);

  if ((sum[0] % 12) == (sum[1] % 12))
    cout << n << nl;
  else if (((sum[0] + 1) % 12) == (sum[1] % 12))
    cout << cnt[1] << nl;
  else if ((sum[0] % 12) == ((sum[1] + 1) % 12))
    cout << cnt[0] << nl;
  else
    cout << 0 << nl;
  return 0;
}

