/**
 * Description: multi-dimensional point update range query
 * Source: https://codeforces.com/blog/entry/64914
 * Verification: https://cses.fi/problemset/result/15386613/
 * Time: O((log N)^2)
 */

template<int... ArgsT>
struct fenwick {
  int val = 0;
  void update(int val) { this->val += val; }
  int query() { return val; }
};
 
template<int N, int... Ns>
struct fenwick<N, Ns...> {
  fenwick<Ns...> b[N + 1];
 
  template<class... Args>
  void update(int i, Args... args) {
    for (; i <= N; b[i].update(args...), i += i & -i);
  }
 
  template<class... Args>
  int query(int l, int r, Args... args) {
    int res = 0; l--;
    for (; r >= 1; res += b[r].query(args...), r -= r & -r);
    for (; l >= 1; res -= b[l].query(args...), l -= l & -l);
    return res;
  }
};
