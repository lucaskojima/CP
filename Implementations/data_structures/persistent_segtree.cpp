/**
 * Description: persistent segment tree
 * Source: https://drive.google.com/file/d/1iDRTlC0iU6j5Dor6BSI8nd1ZjmzGKA5W/view
 * Verification: https://cses.fi/problemset/result/15458018/
 * Time: O(log N)
 */

struct persistent_segtree {
  int n; 
  vector<int> tree, e, d;
  persistent_segtree(int n) : n(n) {
    create(), create();
  }
 
  int create() {
    tree.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sz(tree) - 1;
  }
  void build(int p, int l, int r, const vector<int> &a) {
    if (l == r) {
      tree[p] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    e[p] = create();
    d[p] = create();
    build(e[p], l, m, a);
    build(d[p], m + 1, r, a);
    tree[p] = tree[e[p]] + tree[d[p]];
  }
  int update(int p, int l, int r, int i, int v) {
    int pp = create();
    tree[pp] = tree[p];
    e[pp] = e[p];
    d[pp] = d[p];
 
    if (l == r) {
      tree[pp] = v;
      return pp;
    }
    int m = (l + r) >> 1;
    if (i <= m)
      e[pp] = update(e[pp], l, m, i, v);
    else
      d[pp] = update(d[pp], m + 1, r, i, v);
 
    tree[pp] = tree[e[pp]] + tree[d[pp]];
    return pp;
  }
  int query(int p, int l, int r, int lx, int rx) {
    if (rx < l || r < lx || p == 0) return 0;
    if (lx <= l && r <= rx) return tree[p];
    int m = (l + r) >> 1;
    return query(e[p], l, m, lx, rx) + query(d[p], m + 1, r, lx, rx);
  }
 
  void build(const vector<int> &a) { build(1, 1, n, a); }
  int update(int p, int i, int v) { return update(p, 1, n, i, v); }
  int query(int p, int l, int r) { return query(p, 1, n, l, r); }
};
 
