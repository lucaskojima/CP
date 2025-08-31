/**
 * Description: maximum matching on bipartite graphs
 * Source: https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
 * Verification: https://judge.yosupo.jp/submission/305184
 * Time: O(VE)
 */

void kuhn(int l, int r, vector<vector<int>> adj) {
  vector<bool> vis(l + 1);
  vector<int> mt(r + 1, -1);

  auto try_kuhn = [&](auto try_kuhn, int x) -> bool {
    if (vis[x]) return false;
    vis[x] = true;

    for (int k : adj[x])
      if (mt[k] == -1 || try_kuhn(try_kuhn, mt[k])) {
        mt[k] = x;
        return true;
      }
    return false;
  };

  for (int i = 1; i <= l; i++) {
    try_kuhn(try_kuhn, i);
    fill(all(vis), false);
  }
}
