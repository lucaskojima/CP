/**
 * Description: coordinate compression
 * Source: https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/data-structures/STL%20(5)/CoordCompress.h
 * Verification: https://cses.fi/problemset/result/14268795/
 * Time: O(N log N) / O(log N)
 */

template<class T> vector<T> nor(vector<T> a) {
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  return a;
}
template<class T> int id(T x, vector<T> &a) {
  return lower_bound(all(a), x) - a.begin();
}
