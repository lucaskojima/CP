#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) {
    return e[v] < 0 ? v : e[v] = find(e[v]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m; cin >> n >> m;
  string s; cin >> s;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> size(n + 1, 1);
  dsu dsu(n + 1);

  auto join = [&](int i, int j) -> void {
    i = dsu.find(i);
    j = dsu.find(j);
    if (i == j) return;
    if (dsu.e[i] < dsu.e[j]) swap(i, j);
    dsu.e[j] += dsu.e[i];
    size[j] += size[i];
    dsu.e[i] = j;
  };

  for (int i = 1; i <= n; i++)
    if (s[i - 1] == '1') {
      size[dsu.find(i)] = 0;
      for (int j : adj[i])
        if (s[j - 1] == '1')
          join(i, j);
    }

  vector<i64> ans;
  i64 val = 0;

  for (int i = n; i >= 1; i--) {
    if (s[i - 1] == '1') {
      val += size[dsu.find(i)];
      size[dsu.find(i)]++;
    } else {
      for (int j : adj[i]) {
        if (j < i && s[j - 1] == '0') continue;
        if (dsu.same(i, j)) continue;

        val += 1LL * size[dsu.find(i)] * size[dsu.find(j)];
        join(i, j);
      }
    }
    ans.push_back(val);
  }

  reverse(ans.begin(), ans.end());

  for (i64 x : ans)
    cout << x << '\n';
  return 0;
}
