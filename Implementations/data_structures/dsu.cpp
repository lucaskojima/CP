/**
 * Description: Disjoint Set Union with path compression and union by size
 * Source:
    * https://usaco.guide/gold/dsu
    * https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/graphs%20(12)/DSU/DSU%20(7.6).h
 * Verification: https://judge.yosupo.jp/submission/307393
 * Time: O(alpha(N))
 */

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) { return e[v] < 0 ? v : e[v] = find(e[v]); }
  int size(int v) { return -e[find(v)]; }
  bool same(int a, int b) { return find(a) == find(b); }
  void une(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (e[a] < e[b]) swap(a, b);
    e[b] += e[a];
    e[a] = b;
  }
};
