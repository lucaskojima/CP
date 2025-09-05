/**
 * Description: fast range queries
 * Source: https://cp-algorithms.com/data_structures/sparse-table.html
 * Verification: https://judge.yosupo.jp/submission/312483
 * Time: O(1)
 */

template<class T> struct sparse_table {
  vector<vector<T>> st;

  int log2_floor(int x) {
    return x ? 31 - __builtin_clz(x) : -1;
  }
  sparse_table(const vector<T> &v) {
    int n = sz(v);
    int k = log2_floor(n);
    st.resize(k + 1);
    st[0] = v;

    for (int i = 1; i <= k; i++) {
      st[i].resize(n - (1 << i) + 1);
      for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  T query(int l, int r) {
    int i = log2_floor(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
  }
};
