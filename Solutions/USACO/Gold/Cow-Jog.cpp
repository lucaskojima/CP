#include "bits/stdc++.h"

#define int long long

using namespace std;

int32_t main() {
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, t; cin >> n >> t;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a.push_back(x + t * y);
  }

  reverse(a.begin(), a.end());

  vector<int> dp;
  for (int i = 0; i < n; i++) {
    int pos = upper_bound(dp.begin(), dp.end(), a[i])- dp.begin();
    if (pos == int32_t(size(dp)))
      dp.push_back(a[i]);
    else
      dp[pos] = a[i];
  }

  cout << int32_t(size(dp)) << '\n';
  return 0;
}
