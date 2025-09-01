#include "bits/stdc++.h"
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, a, b; cin >> n >> a >> b;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int k, id; cin >> k >> id;
    cnt[id] = k;
  }

  map<int, set<int>> adj;
  queue<int> q;

  for (auto [id, _] : cnt) {
    q.push(id);
    for (int s : {a, b})
      if (cnt.count(s - id))
        adj[id].insert(s - id);
  }

  long long ans = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (sz(adj[x]) != 1) continue;

    int y = *adj[x].begin();
    if (x == y) {
      ans += cnt[x] / 2;
    } else {
      int v = min(cnt[x], cnt[y]);
      cnt[y] -= v;
      ans += v;
    }

    adj[x].erase(y);
    adj[y].erase(x);
    q.push(y);
  }

  cout << ans << nl;
  return 0;
}

