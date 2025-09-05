/**
 * Description: lowest common ancestor with rmq
 * Source: https://usaco.guide/gold/tree-euler?lang=cpp
 * Verification: https://judge.yosupo.jp/submission/312471
 * Time: O(1)
 */

struct lca_solver {
  vector<pii> euler;
  vector<int> first;
  sparse_table<pii> st;

  lca_solver(vector<vector<int>> &adj) : st(vector<pii>(1)) {
    int n = sz(adj) - 1;
    euler.reserve(2 *  n);
    first.resize(n + 1);

    dfs(adj, 1, -1);
    st = sparse_table<pii>(euler);
  }
  void dfs(vector<vector<int>> &adj, int x, int p, int h = 0) {
    first[x] = sz(euler);
    euler.push_back({h, x});
    for (int k : adj[x]) if (k != p) {
      dfs(adj, k, x, h + 1);
      euler.push_back({h, x});
    }
  }
  int lca(int a, int b) {
    int l = first[a], r = first[b];
    if (r < l) swap(l, r);
    return st.query(l, r).second;
  }
};
