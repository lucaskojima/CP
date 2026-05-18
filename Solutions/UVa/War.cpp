#include "bits/stdc++.h"

using namespace std;

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) {
    return e[v] < 0 ? v : e[v] = find(e[v]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (e[a] < e[b]) swap(a, b);
    e[b] += e[a];
    e[a] = b;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  dsu dsu(2 * n + 1);

  auto F = [&](int a, int b) -> bool {
    return dsu.same(a, b) && dsu.same(a + n, b + n);
  };
  auto E = [&](int a, int b) -> bool {
    return dsu.same(a, b + n) && dsu.same(a + n, b);
  };

  int c, x, y;
  while (cin >> c >> x >> y) {
    if (c == 0) return 0;

    if (c == 1) {
      if (E(x, y)) { cout << -1 << '\n'; continue; }
      dsu.join(x, y);
      dsu.join(x + n, y + n);
    } else if (c == 2) {
      if (F(x, y)) { cout << -1 << '\n'; continue; }
      dsu.join(x + n, y);
      dsu.join(x, y + n);
    } else if (c == 3) {
      cout << (F(x, y) ? 1 : 0) << '\n';
    } else {
      cout << (E(x, y) ? 1 : 0) << '\n';
    }
  }
}
