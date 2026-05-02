#include "bits/stdc++.h"

using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
  int x;
  int d;
  bool f;
  bool operator<(const node &o) const {
    return d > o.d;
  }
};

void setIO(string s){
  ios::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("dining");

  int n, m, k; cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, t; cin >> a >> b >> t; a--, b--;
    adj[a].push_back({b, t});
    adj[b].push_back({a, t});
  }

  vector<int> c(n);
  for (int i = 0; i < k; i++) {
    int j, x; cin >> j >> x; j--;
    c[j] = max(c[j], x);
  }

  vector<array<int, 2>> dist(n, {INF, INF});
  priority_queue<node> pq;
  dist[n - 1][0] = 0;
  pq.push({n - 1, 0, false});

  while (!pq.empty()) {
    auto [x, d, f] = pq.top(); pq.pop();
    if (dist[x][f] != d) continue;

    for (auto [k, dd] : adj[x])
      if (d + dd < dist[k][f]) {
        dist[k][f] = d + dd;
        pq.push({k, dist[k][f], f});
      }
    if (c[x] > 0 && !f && d - c[x] < dist[x][1]) {
      dist[x][1] = d - c[x];
      pq.push({x, dist[x][1], true});
    }
  }

  for (int i = 0; i < n - 1; i++)
    cout << (dist[i][1] <= dist[i][0]) << '\n';
  return 0;
}
