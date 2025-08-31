/**
 * Description: point update range query
 * Source: https://usaco.guide/gold/PURS
 * Verification: https://cses.fi/problemset/result/14142957/
 * Time: O(log N)
 */

struct fenwick {
  int n;
  vector<long long> b;
  fenwick(int n) : n(n), b(n + 1) {}

  void add(int i, int v) {
    for (; i <= n; i += i & -i)
      b[i] += v;
  }
  long long sum(int i) {
    long long r = 0;
    for (; i >= 1; i -= i & -i)
      r += b[i];
    return r;
  }
  long long sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};
