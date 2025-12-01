/**
 * Description: sparse segment tree
 * Source: https://drive.google.com/file/d/1iDRTlC0iU6j5Dor6BSI8nd1ZjmzGKA5W/view
 * Verification: *
 * Time: O(log(R - L))
 */

struct sparse_segtree {
  vector<int> tree, e, d;
  const int L, R;
  sparse_segtree(const int L, const int R) : L(L), R(R) {
    create(), create();
  }

  int create() {
    tree.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sz(tree) - 1;
  }
  void update(int p, int l, int r, int i, int v) {
    if (l == r) {
      tree[p] += v;
      return;
    }
    int m = (l + r) >> 1;
    if (i <= m) {
      if (e[p] == 0) e[p] = create();
      update(e[p], l, m, i, v);
    } else {
      if (d[p] == 0) d[p] = create();
      update(d[p], m + 1, r, i, v);
    }
    tree[p] = tree[e[p]] + tree[d[p]];
  }
  int query(int p, int l, int r, int lx, int rx) {
    if (rx < l || r < lx || p == 0) return 0;
    if (lx <= l && r <= rx) return tree[p];
    int m = (l + r) >> 1;
    return query(e[p], l, m, lx, rx) + query(d[p], m + 1, r, lx, rx);
  }

  void update(int i, int v) { update(1, L, R, i, v); }
  int query(int l, int r) { return query(1, L, R, l, r); }
};
