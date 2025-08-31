/**
 * Description: fast range queries
 * Source:
    * https://cp-algorithms.com/data_structures/sparse-table.html
    * https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/data-structures/Static%20Range%20Queries%20(9.1)/RMQ%20(9.1).h
 * Verification: https://judge.yosupo.jp/submission/310263
 * Time: O(1)
 */

template<class T> struct sparse_table {
  vector<T> v;
  vector<vector<int>> st;

  int log2_floor(int x) {
    return x ? 31 - __builtin_clz(x) : -1;
  }
  int cmb(int i, int j) {
    if (v[i] == v[j]) return min(i, j);
    return v[i] < v[j] ? i : j;
  }
  sparse_table(const vector<T> &v) : v(v) {
    int n = sz(v);
    int k = log2_floor(n);
    st.assign(k + 1, vector<int>(n));
    iota(all(st[0]), 0);

    for (int i = 1; i <= k; i++)
      for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = cmb(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  int index(int l, int r) {
    int i = log2_floor(r - l + 1);
    return cmb(st[i][l], st[i][r - (1 << i) + 1]);
  }
  T query(int l, int r) {
    return v[index(l, r)];
  }
};
