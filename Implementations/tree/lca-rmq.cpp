/**
 * Description: lowest common ancestor with rmq
 * Source: https://usaco.guide/gold/tree-euler?lang=cpp
 * Verification: https://judge.yosupo.jp/submission/312484
 * Time: O(1)
 */

struct lca_solver {
  vector<pii> euler;
  vector<int> first;
  sparse_table<pii> st;

  using T = vector<vector<int>>;
  lca_solver(const T &adj) : first(sz(adj)), st((dfs(adj, 1, -1), euler)) {}

  void dfs(const T &adj, int x, int p, int h = 0) {
    first[x] = sz(euler);
    euler.push_back({h, x});
    for (int k : adj[x]) if (k != p) {
      dfs(adj, k, x, h + 1);
      euler.push_back({h, x});
    }
  }
  int lca(int a, int b) {
    int l = first[a], r = first[b];
    if (l > r) swap(l, r);
    return st.query(l, r).second;
  }
};
