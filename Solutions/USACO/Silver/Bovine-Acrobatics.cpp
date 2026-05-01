#include "bits/stdc++.h"

#define int long long

using namespace std;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m, k; cin >> n >> m >> k;

  vector<pair<int, int>> c(n);
  for (auto &[w, a] : c) {
    cin >> w >> a;
    a = min(a, m);
  }

  sort(c.begin(), c.end(), greater<>());

  deque<pair<int, int>> q;
  q.push_front({INT_MAX, m});

  int ans = 0;
  for (auto [w, a] : c) {
    int rem = a;
    while (!q.empty() && w + k <= q.front().first && rem > 0)
      if (q.front().second >= rem) {
        q.front().second -= rem;
        rem = 0;
      } else {
        rem -= q.front().second;
        q.pop_front();
      }

    q.push_back({w, a - rem});
    ans += a - rem;
  }

  cout << ans << '\n';
  return 0;
}
