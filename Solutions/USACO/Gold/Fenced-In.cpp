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
  freopen("fencedin.in","r",stdin);
	freopen("fencedin.out","w",stdout);

  int A, B, n, m; cin >> A >> B >> n >> m;

  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  a.push_back(A);
  b.push_back(B);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = n; i > 0; i--)
    a[i] = a[i] - a[i - 1];
  for (int i = m; i > 0; i--)
    b[i] = b[i] - b[i - 1];

  auto id = [&](int i, int j) -> int {
    return (m + 1) * i + j;
  };

  vector<tuple<int, int, int>> ed;
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < m + 1; j++) {
      if (j < m)
        ed.push_back({a[i], id(i, j), id(i, j + 1)});
      if (i < n)
        ed.push_back({b[j], id(i, j), id(i + 1, j)});
    }

  sort(ed.begin(), ed.end());

  dsu dsu((n + 1) * (m + 1));
  long long ans = 0;

  for (auto [w, u, v] : ed)
    if (!dsu.same(u, v)) {
      dsu.join(u, v);
      ans += w;
    }

  cout << ans << '\n';
  return 0;
}
