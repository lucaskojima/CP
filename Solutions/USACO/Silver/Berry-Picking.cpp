#include "bits/stdc++.h"

#define int long long

using namespace std;

const int N = 1e3;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("berries.in", "r", stdin);
  freopen("berries.out", "w", stdout);

  int n, k; cin >> n >> k;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  int ans = 0;
  for (int x = 1; x <= N; x++) {
    vector<int> a1 = a;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int qnt = a1[i] / x;
      cnt += qnt;
      a1[i] -= x * qnt;
    }

    cnt = min(cnt, k);
    if (cnt < k / 2) continue;
    cnt -= k / 2;

    int res = 0;
    for (int i = 0; i < cnt; i++)
      res += x;

    sort(a1.begin(), a1.end(), greater<int>());
    for (int i = 0; i < min(n, k / 2 - cnt); i++)
      res += a1[i];

    ans = max(ans, res);
  }

  cout << ans << '\n';
  return 0;
}
