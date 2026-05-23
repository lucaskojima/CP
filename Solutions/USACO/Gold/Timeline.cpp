#include "bits/stdc++.h"

#define int long long

using namespace std;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("timeline.in","r",stdin);
	freopen("timeline.out","w",stdout);

  int n, m, c; cin >> n >> m >> c;

  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> dp[i];

  vector<vector<pair<int, int>>> adj(n + 1);
  vector<int> ing(n + 1);

  for (int i = 0; i < c; i++) {
    int a, b, x; cin >> a >> b >> x;
    adj[a].push_back({b, x});
    ing[b]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (ing[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int x = q.front(); q.pop();

    for (auto [k, w] : adj[x]) {
      dp[k] = max(dp[k], dp[x] + w);
      if (--ing[k] == 0)
        q.push(k);
    }
  }

  for (int i = 1; i <= n; i++)
    cout << dp[i] << '\n';
  return 0;
}
