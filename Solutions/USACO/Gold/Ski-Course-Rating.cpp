#include "bits/stdc++.h"

using namespace std;

const int N = 1e9;
const int K = 40;

struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}

  int find(int v) {
    return e[v] < 0 ? v : e[v] = find(e[v]);
  }
  int size(int v) {
    return -e[find(v)];
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

struct edge {
  int u, v, d;
  bool operator<(const edge &o) {
    return d < o.d;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("skilevel.in","r",stdin);
	freopen("skilevel.out","w",stdout);

  int n, m, t; cin >> n >> m >> t;

  vector a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  auto id = [&](int i, int j) -> int {
    return m * i + j;
  };

  vector<edge> ed;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i + 1 < n)
        ed.push_back({id(i, j), id(i + 1, j), abs(a[i][j] - a[i + 1][j])});
      if (j + 1 < m)
        ed.push_back({id(i, j), id(i, j + 1), abs(a[i][j] - a[i][j + 1])});
    }

  sort(ed.begin(), ed.end());

  vector<int> pos;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      if (x)
        pos.push_back(id(i, j));
    }

  int k = int(size(pos));
  vector<int> lx(k, -1), rx(k, N);

  for (int _ = 0; _ < K; _++) {
    vector<pair<int, int>> x;
    for (int i = 0; i < k; i++)
      if (lx[i] + 1 < rx[i])
        x.push_back({(lx[i] + rx[i]) / 2, i});

    sort(x.begin(), x.end());

    dsu dsu(n * m);
    int j = 0;
    for (auto [z, i] : x) {
      while (j < int(size(ed)) && ed[j].d <= z) {
        dsu.join(ed[j].u, ed[j].v);
        j++;
      }
      if (dsu.size(pos[i]) >= t)
        rx[i] = z;
      else
        lx[i] = z;
    }
  }

  cout << accumulate(rx.begin(), rx.end(), 0LL) << '\n';
  return 0;
}
