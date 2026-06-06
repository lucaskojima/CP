/* Verification: https://judge.yosupo.jp/submission/377423 */

template<class S, auto op, auto e> struct segtree {
  private:
    int n, size, log;
    vector<S> d;

    void update(int i) { d[i] = op(d[2 * i], d[2 * i + 1]); }
  public:
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(const vector<S> &v) : n(int(v.size())) {
      size = 1, log = 0;
      while (size < n) size *= 2, log++;
      d = vector<S>(2 * size, e());
      for (int i = 0; i < n; i++) d[i + size] = v[i];
      for (int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
      d[p += size] = x;
      for (int i = 1; i <= log; i++) update(p >> i);
    }
    S prod(int l, int r) {
      S lx = e(), rx = e();
      for (l += size, r += size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) lx = op(lx, d[l++]);
        if (r % 2 == 0) rx = op(d[r--], rx);
      }
      return op(lx, rx);
    }
    S all_prod() { return d[1]; }
};
