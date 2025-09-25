/**
 * Description: finds an eulerian path of an eulerian graph
 * Source: https://usaco.guide/adv/eulerian-tours
 * Verification: https://cses.fi/problemset/result/14662541/
 * Time: O(E)
 */

vector<int> eulerianPath(vector<vector<pii>> adj, vector<bool> vis, int s) {
  vector<int> path;

  auto dfs = [&](auto dfs, int x) -> void {
    while (!adj[x].empty()) {
      auto [k, id] = adj[x].back(); adj[x].pop_back();
      if (vis[id]) continue;
      vis[id] = true;
      dfs(dfs, k);
    }
    path.push_back(x);
  };
  dfs(dfs, s);

  return path;
}
